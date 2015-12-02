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

package mymhc;

network XTC
{
    parameters:
        int numnodes = 60;
    @display("bgb=1000,1000");
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }
    submodules:
        node1:MyXtc{@display("i=old/x_blank;p=950.129285,503.447550");}
        node2:MyXtc{@display("i=old/x_blank;p=231.138514,100.230825");}
        node3:MyXtc{@display("i=old/x_blank;p=606.842584,178.370839");}
        node4:MyXtc{@display("i=old/x_blank;p=485.982469,355.089616");}
        node5:MyXtc{@display("i=old/x_blank;p=891.298966,182.025659");}
        node6:MyXtc{@display("i=old/x_blank;p=762.096833,339.772444");}
        node7:MyXtc{@display("i=old/x_blank;p=456.467665,658.029382");}
        node8:MyXtc{@display("i=old/x_blank;p=18.503643,710.274104");}
        node9:MyXtc{@display("i=old/x_blank;p=821.407164,658.806431");}
        node10:MyXtc{@display("i=old/x_blank;p=444.703364,465.920982");}
        node11:MyXtc{@display("i=old/x_blank;p=615.432348,272.886783");}
        node12:MyXtc{@display("i=old/x_blank;p=791.937037,690.709840");}
        node13:MyXtc{@display("i=old/x_blank;p=921.812971,161.503955");}
        node14:MyXtc{@display("i=old/x_blank;p=738.207246,431.927539");}
        node15:MyXtc{@display("i=old/x_blank;p=176.266144,629.586443");}
        node16:MyXtc{@display("i=old/x_blank;p=405.706213,297.260087");}
        node17:MyXtc{@display("i=old/x_blank;p=935.469699,453.428848");}
        node18:MyXtc{@display("i=old/x_blank;p=916.904440,555.119795");}
        node19:MyXtc{@display("i=old/x_blank;p=410.270207,305.432760");}
        node20:MyXtc{@display("i=old/x_blank;p=893.649531,378.689869");}
        node21:MyXtc{@display("i=old/x_blank;p=57.891305,205.178920");}
        node22:MyXtc{@display("i=old/x_blank;p=352.868132,43.156552");}
        node23:MyXtc{@display("i=old/x_blank;p=813.166497,477.409651");}
        node24:MyXtc{@display("i=old/x_blank;p=9.861301,119.857793");}
        node25:MyXtc{@display("i=old/x_blank;p=138.890882,827.043859");}
        node26:MyXtc{@display("i=old/x_blank;p=202.765219,20.253103");}
        node27:MyXtc{@display("i=old/x_blank;p=198.721743,728.552741");}
        node28:MyXtc{@display("i=old/x_blank;p=603.792479,747.670653");}
        node29:MyXtc{@display("i=old/x_blank;p=272.187925,124.258100");}
        node30:MyXtc{@display("i=old/x_blank;p=198.814268,262.694012");}
        node31:MyXtc{@display("i=old/x_blank;p=15.273927,863.481258");}
        node32:MyXtc{@display("i=old/x_blank;p=746.785677,988.243313");}
        node33:MyXtc{@display("i=old/x_blank;p=445.096432,106.102034");}
        node34:MyXtc{@display("i=old/x_blank;p=931.814578,800.861933");}
        node35:MyXtc{@display("i=old/x_blank;p=465.994342,701.276988");}
        node36:MyXtc{@display("i=old/x_blank;p=418.649468,338.557424");}
        node37:MyXtc{@display("i=old/x_blank;p=846.221418,715.591410");}
        node38:MyXtc{@display("i=old/x_blank;p=525.152496,530.775715");}
        node39:MyXtc{@display("i=old/x_blank;p=202.647358,935.218877");}
        node40:MyXtc{@display("i=old/x_blank;p=672.137468,11.665062");}
        node41:MyXtc{@display("i=old/x_blank;p=838.118445,417.208318");}
        node42:MyXtc{@display("i=old/x_blank;p=19.639514,576.503743");}
        node43:MyXtc{@display("i=old/x_blank;p=681.277161,484.488248");}
        node44:MyXtc{@display("i=old/x_blank;p=379.481018,666.048520");}
        node45:MyXtc{@display("i=old/x_blank;p=831.796018,567.093404");}
        node46:MyXtc{@display("i=old/x_blank;p=502.812884,774.050132");}
        node47:MyXtc{@display("i=old/x_blank;p=709.471393,420.193127");}
        node48:MyXtc{@display("i=old/x_blank;p=428.892365,239.634990");}
        node49:MyXtc{@display("i=old/x_blank;p=304.617367,470.176883");}
        node50:MyXtc{@display("i=old/x_blank;p=189.653748,359.473501");}
        node51:MyXtc{@display("i=old/x_blank;p=193.431156,790.930596");}
        node52:MyXtc{@display("i=old/x_blank;p=682.223224,620.181630");}
        node53:MyXtc{@display("i=old/x_blank;p=302.764401,216.671350");}
        node54:MyXtc{@display("i=old/x_blank;p=541.673854,319.154249");}
        node55:MyXtc{@display("i=old/x_blank;p=150.872976,538.904873");}
        node56:MyXtc{@display("i=old/x_blank;p=697.898482,432.171288");}
        node57:MyXtc{@display("i=old/x_blank;p=378.373001,205.789349");}
        node58:MyXtc{@display("i=old/x_blank;p=860.011605,940.817407");}
        node59:MyXtc{@display("i=old/x_blank;p=853.655131,397.130914");}
        node60:MyXtc{@display("i=old/x_blank;p=593.562913,949.731196");}

	connections:
        node1.gate++ <--> Channel <--> node17.gate++;
        node1.gate++ <--> Channel <--> node18.gate++;
        node2.gate++ <--> Channel <--> node26.gate++;
        node2.gate++ <--> Channel <--> node29.gate++;
        node3.gate++ <--> Channel <--> node11.gate++;
        node3.gate++ <--> Channel <--> node33.gate++;
        node3.gate++ <--> Channel <--> node40.gate++;
        node4.gate++ <--> Channel <--> node10.gate++;
        node4.gate++ <--> Channel <--> node36.gate++;
        node4.gate++ <--> Channel <--> node54.gate++;
        node5.gate++ <--> Channel <--> node13.gate++;
        node5.gate++ <--> Channel <--> node20.gate++;
        node6.gate++ <--> Channel <--> node11.gate++;
        node6.gate++ <--> Channel <--> node14.gate++;
        node6.gate++ <--> Channel <--> node59.gate++;
        node7.gate++ <--> Channel <--> node35.gate++;
        node7.gate++ <--> Channel <--> node38.gate++;
        node7.gate++ <--> Channel <--> node44.gate++;
        node8.gate++ <--> Channel <--> node31.gate++;
        node8.gate++ <--> Channel <--> node42.gate++;
        node9.gate++ <--> Channel <--> node12.gate++;
        node9.gate++ <--> Channel <--> node45.gate++;
        node10.gate++ <--> Channel <--> node38.gate++;
        node10.gate++ <--> Channel <--> node49.gate++;
        node11.gate++ <--> Channel <--> node54.gate++;
        node12.gate++ <--> Channel <--> node37.gate++;
        node12.gate++ <--> Channel <--> node52.gate++;
        node14.gate++ <--> Channel <--> node23.gate++;
        node14.gate++ <--> Channel <--> node47.gate++;
        node15.gate++ <--> Channel <--> node27.gate++;
        node15.gate++ <--> Channel <--> node55.gate++;
        node16.gate++ <--> Channel <--> node19.gate++;
        node16.gate++ <--> Channel <--> node48.gate++;
        node17.gate++ <--> Channel <--> node20.gate++;
        node18.gate++ <--> Channel <--> node45.gate++;
        node19.gate++ <--> Channel <--> node36.gate++;
        node20.gate++ <--> Channel <--> node59.gate++;
        node21.gate++ <--> Channel <--> node24.gate++;
        node21.gate++ <--> Channel <--> node30.gate++;
        node22.gate++ <--> Channel <--> node29.gate++;
        node22.gate++ <--> Channel <--> node33.gate++;
        node23.gate++ <--> Channel <--> node41.gate++;
        node23.gate++ <--> Channel <--> node45.gate++;
        node24.gate++ <--> Channel <--> node26.gate++;
        node25.gate++ <--> Channel <--> node31.gate++;
        node25.gate++ <--> Channel <--> node39.gate++;
        node25.gate++ <--> Channel <--> node51.gate++;
        node27.gate++ <--> Channel <--> node44.gate++;
        node27.gate++ <--> Channel <--> node51.gate++;
        node28.gate++ <--> Channel <--> node46.gate++;
        node28.gate++ <--> Channel <--> node52.gate++;
        node29.gate++ <--> Channel <--> node53.gate++;
        node30.gate++ <--> Channel <--> node50.gate++;
        node30.gate++ <--> Channel <--> node53.gate++;
        node32.gate++ <--> Channel <--> node58.gate++;
        node32.gate++ <--> Channel <--> node60.gate++;
        node33.gate++ <--> Channel <--> node57.gate++;
        node34.gate++ <--> Channel <--> node37.gate++;
        node34.gate++ <--> Channel <--> node58.gate++;
        node35.gate++ <--> Channel <--> node46.gate++;
        node38.gate++ <--> Channel <--> node43.gate++;
        node41.gate++ <--> Channel <--> node59.gate++;
        node42.gate++ <--> Channel <--> node55.gate++;
        node43.gate++ <--> Channel <--> node52.gate++;
        node43.gate++ <--> Channel <--> node56.gate++;
        node46.gate++ <--> Channel <--> node60.gate++;
        node47.gate++ <--> Channel <--> node56.gate++;
        node48.gate++ <--> Channel <--> node57.gate++;
        node49.gate++ <--> Channel <--> node50.gate++;
        node49.gate++ <--> Channel <--> node55.gate++;
        node53.gate++ <--> Channel <--> node57.gate++;
}
simple MyXtc
{
    gates:
        inout gate[];
}
