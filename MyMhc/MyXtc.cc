//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include <MyXtc.h>

MyXtc::MyXtc() {
    // TODO Auto-generated constructor stub

}

MyXtc::~MyXtc() {
    // TODO Auto-generated destructor stub
}
//��õ�ǰ�ڵ��ID
int MyXtc::getMyIndex(char* name) {
    int index = 0;
    //���node%d���node������֣�������ת��������
    name = name + 4;
    index = atoi(name);
    return index;
}
void MyXtc::initialize() {
    idex = getMyIndex((char*) getName());
    numSent = 0; //�������ݰ��ĸ���
    numReceived = 0; //�������ݰ��ĸ���
    numLocalSent = 0; //
    localCount = 100;
    neibCount = 0; //�ھӵĸ���
    myPower = 30;
    energy = INIENERGY;
    initializeNeib(); //initialize parents list
    flag = 0;
    WATCH(numSent);
    WATCH(numReceived);
    WATCH(localCount);
    WATCH(numLocalSent);
    WATCH(energy);
    WATCH(degree);
    WATCH(odegree);
    WATCH(neighbors);
    energyStats.setName("hopCountStats");
    nodeEnergy.setName("nodeEnergy");

    // Module 0 sends the first message
    //���û�վ�ڵ�
    // network setup phrase , gateway(node index=0) send its hopcount to the node at layer 2.
    if (idex == 1) //tic0 send a message first,so begin the program,like startcontrol in micaz
            {
        localCount = 0;
        iniTemp = 1;
        // Boot the process scheduling the initial message as a self-message.
        mhcMessage *msg = generateMessage(0);
        scheduleAt(0.0, msg);
    }
    if (idex != 1) {
        int n = size();
        ev << "modules size : " << n << endl;
        ev << "!!!!!!!!!!!!!!ordinary node send data!!!!!!!!!!!!!!!!!!!"
                << endl;
        mhcMessage *dataMsg = generateMessage(1);
//            float k = (float) simTime() + (float)intuniform(0,5);
        scheduleAt(simTime() + intuniform(0, 5), dataMsg);
    }
}
void MyXtc::handleMessage(cMessage *msg) {
    ev << "time is :" << simTime() << endl;
    mhcMessage *ttmsg = check_and_cast<mhcMessage *>(msg);
    //energy--;
    ev << "rest energy is :" << energy << endl;
    ev << "localCount is " << localCount << " hops.\n";
    int mType = ttmsg->getMsgType();
    ev << "msg type is : " << mType << endl;

    int totalCount = ttmsg->getTotalCount();

//    hopCountStats.collect(totalCount);

    int node;
    if (ttmsg->getForward() == 100) //get the real forward node or the source node
            {
        node = ttmsg->getSource();
    } else
        node = ttmsg->getForward();

    //if index =0 and msgType =0 ,means broadcast message send by scheduleat
    //do not add parent 0 to 0,just forward the message.
    if (mType == 0 && energy > 30) //receive hopcount broadcast message,decide to accept as parent or not
            {

        if (idex != 1) //current node is not the sink(index=0)
                {
            int hopcount = ttmsg->getHopCount();
            ev << "hopcount in msg is" << hopcount << endl;
            if (hopcount + 1 < localCount
                    || (hopcount + 1 < localCount && !isExistInNeib(node))) //parent!! add source node into parent table
                    {
                localCount = hopcount + 1; //change the local hop count
                ev << "update current hops:" << localCount;
                ev << "current node is: " << idex << endl;
                ev << "source is: " << ttmsg->getForward() << endl;
                int hopcount = ttmsg->getHopCount();
                int outgateindex = outGatesDetect(node); // find the outgate of current node connect to the parent.
                if (outgateindex < 0)
                    ev << "error" << endl;
                else if (isExistInNeib(node) == -1) //add neighbor node to the table
                        {
                    addToNeib(node, outgateindex, hopcount,
                            ttmsg->getRestEnergy());
                }
                printNeib();

//                ev << "run to forward" << endl;
//                ev << "totalcount : " << ttmsg->getTotalCount() << endl;
                forwardHopMessage(ttmsg);
            } else {
//                ev << "the newest hop yet." << endl;
//                ev << "totalcount : " << ttmsg->getTotalCount() << endl;
            }
        }
        //if sink receive broadcastmsg as the first time ,forward it
        //if sink receive the msg from its son ,ignore the msg
        else if (idex == 1 && iniTemp == 1) //avoid the schedualat time
                {
            iniTemp--;
            ev << "index 1 forward" << endl;
            ev << "totalcount : " << ttmsg->getTotalCount() << endl;
            forwardHopMessage(ttmsg);
        } else
            ev << "receive already." << endl;
    } else if (mType == 1 && energy > 30) //receive data message
            {
        ev << "----------------receive data----------------------" << endl;
        ev << "source node is : " << ttmsg->getSource() << endl;
        ev << "current node is : " << idex << endl;
        ev << "destinate node is : " << ttmsg->getDestination() << endl;
        ev << "the hop current msg used: " << ttmsg->getTotalCount() << endl;
        printNeib();
        if (!ttmsg->isSelfMessage()) {
            ev << "start to send a ack msg" << endl;
            mhcMessage *ack = ttmsg->dup();
            char msgname[20];
            sprintf(msgname, "ack-%d-to-back",node) ;
            ack->setMsgType(2);
            //�������power�õ���Ӧ��lqi
            int power = ttmsg->getPower();
            int lqi = fuzzyGetLqi(power);
            //��������޸ĵõ�LQIֵ�ķ������Ѿ�
            //�Ѳ�����lqi��ֵ����ack��Ϣ�з����ȥ��
            ack->setLqi(lqi);
            //����ʹ�õ��ںõĹ��ʷ����ȥ��
//                ack->setPower();
            //���÷�������ڵ�Ĺ��ʡ�
            ack->setOldpower(power);
            ack->setSource(idex);
            energy = energy - power;
            //�ҵ���Ӧ�Ľڵ㷢��ack��Ϣ��
            int outgateindex = outGatesDetect(node);
            ev << node << "  " << outgateindex << endl;
            ev << "using" <<power<< "send ack msg"<<endl;
            ack->setName(msgname);
            send(ack, "gate$o", outgateindex);
        }
        if (ttmsg->getDestination() == idex) {
            //int totalCount = ttmsg->getTotalCount();
            ev << "Message " << ttmsg << " arrived ater " << totalCount
                    << " hops.\n";
            numReceived++;
            //nodeEnergy.record(energy);
            //hopCountStats.collect(totalCount);
            ev << "numReceived is " << numReceived << " .\n";
            delete ttmsg;
            bubble("ARRIVED, starting new one!");
        } else {
            forwardDataMessage(ttmsg);
        }
    } else {
        //�����ack��Ϣ
        int lqi = ttmsg->getLqi();
        int fatherid = ttmsg->getSource();
        //����õ�����ack�Ĺ��ʡ�
        ev << "�յ�ack ��Ϣ" << endl;
        int power = ttmsg->getOldpower();
        //����õ�֮ǰ�ķ��书�ʣ��Լ����䵽���ڵ�Ĳ�����Lqiֵ��
        //ʹ��������ֵ���� ʹ��ģ�����ڽ��й��ʵ���
        //int newpower = getPower(LQI,POWER);
        int index = isExistInNeib(fatherid);
        int old = neighbors[index-1].oldlqi;
        if(old<0)
        {
            neighbors[index-1].oldlqi = lqi;
            neighbors[index-1].lqi = lqi;
        }
        else{
            int adj = 0;
            ev << "LQI is "<<lqi<<" oldLQI is "<<neighbors[index-1].lqi<<endl;
            ev << "before power is " << power << endl;
            if (index != -1) {
                //ʹ��ģ���㷨���ڹ���
                adj = fuzzyChangePower(lqi, neighbors[index-1].lqi, power);
                neighbors[index-1].lqi = lqi;
                power = power + adj;
                neighbors[index-1].powerlimit = power;
                ev << "neighbors["<<index<<"].powerlimit="<<power<<endl;
            }
            ev << lqi << endl;
            delete ttmsg;
        }
    }
    nodeEnergy.record(energy);
    energyStats.collect(energy);
}
void MyXtc::initialDegree() {
    for (int i = 0; i < 5; i++) {
        degree[i] = 0;
        odegree[i] = 0;
    }
}
int MyXtc::fuzzyChangePower(int lqi, int oldlqi, int power) {
    initialDegree();
    int list = fuzzy(lqi, 0);
    int olist = fuzzy(oldlqi, 1);
    //�õ�֮ǰlqi��ģ��ֵ�͵�ǰlqi��ģ��ֵ
    int *x = new int[2];
    x[0] = 0;
    x[1] = 0;
    int index = 0;
    while (list != 0) {
        if (list >= 16) {
            list -= 16;
            x[index++] = 16;
            continue;
        }
        if (list >= 8) {
            list -= 8;
            x[index++] = 8;
            continue;
        }
        if (list >= 4) {
            list -= 4;
            x[index++] = 4;
            continue;
        }
        if (list >= 2) {
            list -= 2;
            x[index++] = 2;
            continue;
        }
        if (list >= 1) {
            list -= 1;
            x[index++] = 1;
            continue;
        }
    }
    int *y = new int[2];
    y[0] = 0;
    y[1] = 0;
    index = 0;
    while (olist != 0) {
        if (olist >= 16) {
            olist -= 16;
            y[index++] = 16;
            continue;
        }
        if (olist >= 8) {
            olist -= 8;
            y[index++] = 8;
            continue;
        }
        if (olist >= 4) {
            olist -= 4;
            y[index++] = 4;
            continue;
        }
        if (olist >= 2) {
            olist -= 2;
            y[index++] = 2;
            continue;
        }
        if (olist >= 1) {
            olist -= 1;
            y[index++] = 1;
            continue;
        }
    }
    double BStep = 0;
    double SStep = 0;
    double TStep = 0;
    double sum = 0;
    int index1, index2;
    if (y[0])
        index1 = countPower(y[0]);
    if (y[1])
        index2 = countPower(y[1]);
    for (int j = 0; j < 2; j++) {
        if (x[j] == 16) {
            BStep += -degree[4] * 10;
            sum += degree[4];
        } else if (x[j] == 1) {
            BStep += degree[0] * 10;
            sum += degree[0];
        } else if (x[j] == 4) {
            //��ǰ��lqiΪ������������Ͳ��õ����ˡ�
            sum += degree[2];
        } else if (x[j] == 8) {
            if (y[0] != 0) {
                double min =
                        degree[3] < odegree[index1] ?
                                degree[3] : odegree[index1];
                if (y[0] < 8) {
                    TStep += -min * 2;
                } else {
                    SStep += -min * 5;
                }
                sum += min;
            }
            if (y[1] != 0) {
                double min =
                        degree[3] < odegree[index2] ?
                                degree[3] : odegree[index2];
                if (y[1] < 8) {
                    TStep += min * 2;
                } else {
                    SStep += min * 5;
                }
                sum += min;
            }
        } else if (x[j] == 2) {
            if (y[0] != 0) {
                double min =
                        degree[1] < odegree[index1] ?
                                degree[1] : odegree[index1];
                if (y[0] < 4) {
                    SStep += min * 5;
                } else {
                    TStep += min * 2;
                }
                sum += min;
            }
            if (y[1] != 0) {
                double min =
                        degree[1] < odegree[index2] ?
                                degree[1] : odegree[index2];
                if (y[1] < 4)
                    SStep += min * 5;
                else
                    TStep += min * 2;
                sum += min;
            }
        }
    }
    int adj = 0;
    if (sum != 0)
        adj = (BStep + SStep + TStep) / sum;
    ev << "sum = " << sum << endl;
    ev << "adj = " << adj << endl;
    return adj;
}
int MyXtc::fuzzy(int lqi, int id) {
//    bool *list = new bool[5];
    int res = 0;
    if (lqi >= 50 && lqi <= 70) {
        res += 1;
        if (id)
            odegree[0] = ((double) (70 - lqi)) / ((double) 20);
        else
            degree[0] = ((double) (70 - lqi)) / ((double) 20);
    }
    if (lqi >= 60 && lqi <= 80) {
        res += 2;
        if (id)
            odegree[1] = getLi(60, 80, lqi);
        else
            degree[1] = getLi(60, 80, lqi);
    }
    if (lqi >= 70 && lqi <= 90) {
        res += 4;
        if (id)
            odegree[2] = getLi(70, 90, lqi);
        else
            degree[2] = getLi(70, 90, lqi);
    }
    if (lqi >= 80 && lqi <= 100) {
        res += 8;
        if (id)
            odegree[3] = getLi(80, 100, lqi);
        else
            degree[3] = getLi(80, 100, lqi);
    }
    if (lqi >= 90 && lqi <= 110) {
        res += 16;
        if (id)
            odegree[4] = ((double) (lqi - 90)) / ((double) 20);
        else
            degree[4] = ((double) (lqi - 90)) / ((double) 20);
    }
    return res;
}
//������������Ϊ�����������е�λ��
int MyXtc::countPower(int num) {
    int count = 0;
    while (num != 1) {
        num = num / 2;
        count++;
    }
    return count;
}

//�����������ȵĺ������Ժ���Ҫ�Ľ�
double MyXtc::getLi(int a, int b, int lqi) {
    int c = (a + b) / 2;
    double result;
    if (lqi < c) {
        result = ((double) (lqi - a)) / ((double) (c - a));
    }
    if (lqi >= c) {
        result = ((double) (b - lqi)) / ((double) (b - c));
    }
    return result;
}
int MyXtc::fuzzyGetLqi(int power) {
    //�������Թ�ϵ �ѹ��ʵĴ�С��LQI����������
    int middle = 50 + power * 2 - 5;
    int a, b;
    if (uniform(0, 1) > 0.1) {
        a = middle - 5;
        b = middle + 5;
        if (a < 50)
            a = 50;
        if (b > 110)
            b = 110;
    } else {
        if (uniform(0, 1) > 0.5)
            return intuniform(50, 60);
        return intuniform(middle, 110);
    }
    return intuniform(a, b);
}
void MyXtc::changeFatherPower(int fatherid, int power) {
    int i;
    for (i = 0; i < NEIBNUM; i++) {
        if (neighbors[i].nodeId == fatherid) {
            neighbors[i].powerlimit = power; //p exist in parents list ,return p's hop count
            break;
        }
    }
}
void MyXtc::finish() {
    // This function is called by OMNeT++ at the end of the simulation.
    ev << "node:" << getMyIndex((char*) getName()) << "Sent: " << numSent
            << "rest energy: " << energy << endl;
    ev << "time is :" << simTime() << endl;
    ev << "Received: " << numReceived << endl;
//    ev << "Hop count, min:    " << hopCountStats.getMin() << endl;
//    ev << "Hop count, max:    " << hopCountStats.getMax() << endl;
//    ev << "Hop count, mean:   " << hopCountStats.getMean() << endl;
//    ev << "Hop count, stddev: " << hopCountStats.getStddev() << endl;
//    recordScalar("#sent",numSent);
//    recordScalar("#energy",energy);
//    recordScalar("#received", numReceived);
//    hopCountStats.recordWithUnit("hop count");
    ev << "energy , min:    " << energyStats.getMin() << endl;
    ev << "energy , max:    " << energyStats.getMax() << endl;
    ev << "energy , mean:   " << energyStats.getMean() << endl;
    ev << "energy , stddev: " << energyStats.getStddev() << endl;
    recordScalar("#sent", numSent);
    recordScalar("#energy", energy);
    recordScalar("#received", numReceived);
    energyStats.recordAs("Energy");
}
//������Ϣ
mhcMessage *MyXtc::generateMessage(int type) {
    numLocalSent++;
    int src = idex;   // our module index
    int n = size();      // module vector size
    int dest = 100; // initial data = 100 means extreamly large ,no node as dest yet.
    char msgname[20];
    // Create message object and set source and destination field.
    //���콨����Ϣ
    if (0 == type) //send setup message , node 0 started.
            {
        sprintf(msgname, "node-%d-broadcast hopcounts", src);
        mhcMessage *msg = new mhcMessage(msgname);
        msg->setMsgType(type);
        msg->setSource(src);
        msg->setDestination(dest);
        msg->setHopCount(localCount);
        msg->setRestEnergy(energy);
        return msg;
    }
    //���촫����Ϣ
    else if (type == 1) //data package
            {
        dest = 1;
        sprintf(msgname, "node-%d-to-sink", src);
        mhcMessage *msg = new mhcMessage(msgname);
        msg->setMsgType(type);
        msg->setSource(src);
        msg->setDestination(dest);
        msg->setHopCount(localCount);
        msg->setRestEnergy(energy);
        return msg;
    }
}
void MyXtc::forwardHopMessage(mhcMessage *msg) {

    numSent++;
    msg->setHopCount(localCount);
    msg->setTotalCount(msg->getTotalCount() + 1);
    msg->setForward(idex);
//    cGate *gates = gateSize("gate");
    int n = gateSize("gate");
    ev << "gate out size n=" << n << endl;
    int i;
    for (i = 0; i < n - 1; i++) {
        cGate *outgate = gate("gate$o", i);
        if (outgate->isConnected()) {
            cGate *othergate =
                    (outgate->getType() == 'O') ?
                            outgate->getNextGate() : outgate->getPreviousGate();
            ev << "setup phrase outgate " << i << " is connected to: "
                    << othergate->getFullPath() << endl;
        } else {
            ev << "gates not connected" << endl;
            return;
        }
        cMessage *copy = (cMessage *) msg->dup();
        send(copy, "gate$o", i);
    }
    send(msg, "gate$o", n - 1);
}
void MyXtc::forwardDataMessage(mhcMessage *msg) {
//    energy = energy - 1;
    ev << "rest energy is: " << energy << endl;
    ev << "current node is: " << idex << endl;
    ev << "msg Source is: " << msg->getSource() << endl;
    if (energy <= 30) {
        ev << "energy is not enough to send a msg" << endl;
        delete msg;
        finish();
        return;
    }
    if (energy > 900 && msg->getSource() == idex) {
        ev << "generate new msg!!!!!!!!!!!!!" << endl;
        mhcMessage *dataMsg = generateMessage(1);
//        float k = (float) simTime() + 5 + (float)intuniform(0,1);
        numSent++;
        scheduleAt(simTime() + 5 + intuniform(0, 1), dataMsg);
    }
    /*if (energy < 5)
     {
     ev << "@@@@@@@@@@@@@ low energy @@@@@@@@@@@@@@@@@@" << endl;
     deleteModule();
     return;
     }
     */
    // Increment hop count.
    msg->setHopCount(localCount);
    msg->setTotalCount(msg->getTotalCount() + 1);
    msg->setForward(idex);
//    cGate *gates = gate("$o");

    // Same routing as before: random gate.
    int n = gateSize("gate");
    int power = 30;
    ev << "gate out size n=" << n << endl;
    int i;
    ev<<"neibCount" << neibCount<<endl;
    for (i = 0; i < neibCount; i++) {
        int j = intuniform(i,neibCount-1);
        if (neighbors[j].hop < localCount) {
            int k = neighbors[j].ogate;

            power = neighbors[j].powerlimit;
            msg->setPower(power);
            ev<<"using neighbors["<<j<<"]"<<"powerlimit="<<power<<endl;
            ev << "Forwarding message " << msg << " on port out[" << k << "]\n";
            send(msg, "gate$o", k);
            break;
        }
    }
    ev << "using power level is " << power << endl;
    energy = energy - power;
}
void MyXtc::initializeNeib() {
    int i = 0;
    for (i = 0; i < NEIBNUM; i++) {
        neighbors[i].nodeId = -1;
        neighbors[i].ogate = -1;
        neighbors[i].hop = 1000;
        neighbors[i].neibEnergy = -1;
        neighbors[i].powerlimit = 30;
        neighbors[i].oldlqi = -1;
        neighbors[i].lqi = 90;
    }
}
int MyXtc::isExistInNeib(int p) {
    int i;
    for (i = 0; i < NEIBNUM; i++) {
        if (neighbors[i].nodeId == p) {
            return i + 1;        //p exist in parents list ,return p's hop count
        }
    }
    return -1;        //p is not exist in parents list.
}
void MyXtc::printNeib() {
    ev << "neighbors:" << endl;
    for (int i = 0; i < NEIBNUM; i++) {
        if (neighbors[i].nodeId == -1)
            continue;
        else
            ev << "node: " << neighbors[i].nodeId << ",outgate "
                    << neighbors[i].ogate << ",hopcount " << neighbors[i].hop
                    << "restEnergy: " << neighbors[i].neibEnergy << endl;
    }
}
bool MyXtc::addToNeib(int p, int outgateindex, int hop, int neibEnergy) {
    int i = 0;
    for (i = 0; i < NEIBNUM; i++) {
        if (neighbors[i].nodeId == -1) {
            neighbors[i].nodeId = p;
            neighbors[i].ogate = outgateindex;
            neighbors[i].hop = hop;
            neighbors[i].neibEnergy = neibEnergy;
            break;
        }
    }
    neibCount++;
    return true;
}
bool MyXtc::deleteFromNeib(int p) {
    int i = 0;
    int j;
    bool res = true;
    while (res) {
        if (neighbors[i].nodeId == p) {
            break;
        }
        if (neighbors[i].nodeId == -1) {
            res = false;
            return res;
        }
        i++;
    }
    for (j = i + 1; j < NEIBNUM; j++) {
        if (neighbors[i].nodeId == p && p != -1) {
            neighbors[i].nodeId = neighbors[j].nodeId;
            neighbors[i].ogate = neighbors[j].ogate;
            neighbors[i].neibEnergy = neighbors[j].neibEnergy;
            p = neighbors[j].nodeId;
        }
    }
    neibCount--;
    return res;
}
int MyXtc::outGatesDetect(int nodeindex) {
    int n = gateSize("gate");  //out gate size
    ev << "total gates number n = " << n << ";" << endl;
    for (int i = 0; i < n; i++) {
        cGate *outgate = gate("gate$o", i);     //get every out gate
        if (outgate->isConnected()) {
            cGate *othergate =
                    (outgate->getType() == 'O') ?
                            outgate->getNextGate() : outgate->getPreviousGate();
            ev << "outgate " << i << " is connected to: "
                    << othergate->getFullPath() << endl;
        } else {
            ev << "out gate not connected" << endl;
        }
        if (nodeindex
                == getMyIndex(
                        (char*) outgate->getNextGate()->getOwnerModule()->getName())) //get the outgate of current node which connect to the node with index = "nodeindex"
                        {
            ev << "outgate " << i << " is connected to " << nodeindex
                    << " #module." << endl;
            return i;
        }
    }
    return -1;
}
