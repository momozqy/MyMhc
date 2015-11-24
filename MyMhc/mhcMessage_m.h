//
// Generated file, do not edit! Created by opp_msgc 4.5 from mhcMessage.msg.
//

#ifndef _MHCMESSAGE_M_H_
#define _MHCMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>mhcMessage.msg</tt> by opp_msgc.
 * <pre>
 * message mhcMessage
 * {
 *  	int msgType;
 *     int source; 
 *     int destination; 
 *     int forward=100;
 *     int totalCount = 0;
 *     int hopCount=100;
 *     int msgId;
 *    	int restEnergy;
 *    	int power=30;
 *    	int oldpower=0;
 *    	int lqi;
 * }
 * </pre>
 */
class mhcMessage : public ::cMessage
{
  protected:
    int msgType_var;
    int source_var;
    int destination_var;
    int forward_var;
    int totalCount_var;
    int hopCount_var;
    int msgId_var;
    int restEnergy_var;
    int power_var;
    int oldpower_var;
    int lqi_var;

  private:
    void copy(const mhcMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const mhcMessage&);

  public:
    mhcMessage(const char *name=NULL, int kind=0);
    mhcMessage(const mhcMessage& other);
    virtual ~mhcMessage();
    mhcMessage& operator=(const mhcMessage& other);
    virtual mhcMessage *dup() const {return new mhcMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getMsgType() const;
    virtual void setMsgType(int msgType);
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getDestination() const;
    virtual void setDestination(int destination);
    virtual int getForward() const;
    virtual void setForward(int forward);
    virtual int getTotalCount() const;
    virtual void setTotalCount(int totalCount);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
    virtual int getMsgId() const;
    virtual void setMsgId(int msgId);
    virtual int getRestEnergy() const;
    virtual void setRestEnergy(int restEnergy);
    virtual int getPower() const;
    virtual void setPower(int power);
    virtual int getOldpower() const;
    virtual void setOldpower(int oldpower);
    virtual int getLqi() const;
    virtual void setLqi(int lqi);
};

inline void doPacking(cCommBuffer *b, mhcMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, mhcMessage& obj) {obj.parsimUnpack(b);}


#endif // _MHCMESSAGE_M_H_