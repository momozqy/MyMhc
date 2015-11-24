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
message mhcMessage
{
 	int msgType;//消息类型 0 mean join 1 mean data 2 ack
    int source; //source node
    int destination; //目标节点 
    int forward=100;
    int totalCount = 0;//传递跳数
    int hopCount=100;//跳数
    int msgId;//消息id
   	int restEnergy;
   	int power=30;
   	int oldpower=0;
   	int lqi;
}