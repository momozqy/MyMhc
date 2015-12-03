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

#ifndef MYXTC_H_
#define MYXTC_H_

#include <csimplemodule.h>
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <cgate.h>
#include "mhcMessage_m.h"
#define NEIBNUM 10
#define SINK 1
#define INIENERGY 15000  //the initial energy a node have

struct NeibNodes
{
    int nodeId;
    int ogate;  //the outgate of current module connect to the neib node's ingate.
//  int igate;  //the ingate of current module connect to the neib node's ingate.
    int hop;
    int oldlqi;
    int powerlimit;
    int lqi;
    int neibEnergy;
};
class MyXtc: public cSimpleModule {
private:
    long numSent;
    //
    bool flag3;
    long numReceived;
    long numLocalSent;//send msg number as source
    NeibNodes neighbors[NEIBNUM];
    int localCount;
    int energy; //current node's energy.
    int flag;
    int iniTemp;
    bool flag2;
    int idex;
    int myPower;
    int neibCount; //the number of neibghours.
    double degree[5];
    double odegree[5];
//    cLongHistogram hopCountStats;
//    cOutVector hopCountVector;
    cLongHistogram energyStats;
    cOutVector nodeEnergy;
    cLongHistogram numsStats;
    cOutVector nodenumsV;
public:
    MyXtc();
    static int nodenums;
    static void init(){
        nodenums = 5;
    }
    virtual ~MyXtc();
    virtual int getMyIndex(char* name);
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    virtual mhcMessage* generateMessage(int type);
    virtual void forwardHopMessage(mhcMessage *msg);
    virtual void forwardDataMessage(mhcMessage *msg);
    virtual void initializeNeib();
    virtual int isExistInNeib(int p);
    virtual void printNeib();
    virtual bool addToNeib(int p,int outgateindex,int hop,int neibEnergy);
    virtual bool deleteFromNeib(int p);
    virtual int outGatesDetect(int nodeindex);
    virtual void changeFatherPower(int fahterid,int power);
    virtual int fuzzyChangePower(int lqi,int oldlqi,int power);
    virtual int fuzzyGetLqi(int power);
    virtual double Gaussian_distribution(double u,double o,double x);
    virtual int fuzzy(int lqi,int id);
    virtual double getLi(int a,int b,int lqi);
    virtual int countPower(int num);
    virtual void initialDegree();
};
Define_Module(MyXtc);
#endif /* MYXTC_H_ */
