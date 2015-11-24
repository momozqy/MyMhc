//
// Generated file, do not edit! Created by opp_msgc 4.5 from mhcMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "mhcMessage_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(mhcMessage);

mhcMessage::mhcMessage(const char *name, int kind) : ::cMessage(name,kind)
{
    this->msgType_var = 0;
    this->source_var = 0;
    this->destination_var = 0;
    this->forward_var = 100;
    this->totalCount_var = 0;
    this->hopCount_var = 100;
    this->msgId_var = 0;
    this->restEnergy_var = 0;
    this->power_var = 30;
    this->oldpower_var = 0;
    this->lqi_var = 0;
}

mhcMessage::mhcMessage(const mhcMessage& other) : ::cMessage(other)
{
    copy(other);
}

mhcMessage::~mhcMessage()
{
}

mhcMessage& mhcMessage::operator=(const mhcMessage& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void mhcMessage::copy(const mhcMessage& other)
{
    this->msgType_var = other.msgType_var;
    this->source_var = other.source_var;
    this->destination_var = other.destination_var;
    this->forward_var = other.forward_var;
    this->totalCount_var = other.totalCount_var;
    this->hopCount_var = other.hopCount_var;
    this->msgId_var = other.msgId_var;
    this->restEnergy_var = other.restEnergy_var;
    this->power_var = other.power_var;
    this->oldpower_var = other.oldpower_var;
    this->lqi_var = other.lqi_var;
}

void mhcMessage::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->msgType_var);
    doPacking(b,this->source_var);
    doPacking(b,this->destination_var);
    doPacking(b,this->forward_var);
    doPacking(b,this->totalCount_var);
    doPacking(b,this->hopCount_var);
    doPacking(b,this->msgId_var);
    doPacking(b,this->restEnergy_var);
    doPacking(b,this->power_var);
    doPacking(b,this->oldpower_var);
    doPacking(b,this->lqi_var);
}

void mhcMessage::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->msgType_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->forward_var);
    doUnpacking(b,this->totalCount_var);
    doUnpacking(b,this->hopCount_var);
    doUnpacking(b,this->msgId_var);
    doUnpacking(b,this->restEnergy_var);
    doUnpacking(b,this->power_var);
    doUnpacking(b,this->oldpower_var);
    doUnpacking(b,this->lqi_var);
}

int mhcMessage::getMsgType() const
{
    return msgType_var;
}

void mhcMessage::setMsgType(int msgType)
{
    this->msgType_var = msgType;
}

int mhcMessage::getSource() const
{
    return source_var;
}

void mhcMessage::setSource(int source)
{
    this->source_var = source;
}

int mhcMessage::getDestination() const
{
    return destination_var;
}

void mhcMessage::setDestination(int destination)
{
    this->destination_var = destination;
}

int mhcMessage::getForward() const
{
    return forward_var;
}

void mhcMessage::setForward(int forward)
{
    this->forward_var = forward;
}

int mhcMessage::getTotalCount() const
{
    return totalCount_var;
}

void mhcMessage::setTotalCount(int totalCount)
{
    this->totalCount_var = totalCount;
}

int mhcMessage::getHopCount() const
{
    return hopCount_var;
}

void mhcMessage::setHopCount(int hopCount)
{
    this->hopCount_var = hopCount;
}

int mhcMessage::getMsgId() const
{
    return msgId_var;
}

void mhcMessage::setMsgId(int msgId)
{
    this->msgId_var = msgId;
}

int mhcMessage::getRestEnergy() const
{
    return restEnergy_var;
}

void mhcMessage::setRestEnergy(int restEnergy)
{
    this->restEnergy_var = restEnergy;
}

int mhcMessage::getPower() const
{
    return power_var;
}

void mhcMessage::setPower(int power)
{
    this->power_var = power;
}

int mhcMessage::getOldpower() const
{
    return oldpower_var;
}

void mhcMessage::setOldpower(int oldpower)
{
    this->oldpower_var = oldpower;
}

int mhcMessage::getLqi() const
{
    return lqi_var;
}

void mhcMessage::setLqi(int lqi)
{
    this->lqi_var = lqi;
}

class mhcMessageDescriptor : public cClassDescriptor
{
  public:
    mhcMessageDescriptor();
    virtual ~mhcMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(mhcMessageDescriptor);

mhcMessageDescriptor::mhcMessageDescriptor() : cClassDescriptor("mhcMessage", "cMessage")
{
}

mhcMessageDescriptor::~mhcMessageDescriptor()
{
}

bool mhcMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<mhcMessage *>(obj)!=NULL;
}

const char *mhcMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int mhcMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int mhcMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *mhcMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "msgType",
        "source",
        "destination",
        "forward",
        "totalCount",
        "hopCount",
        "msgId",
        "restEnergy",
        "power",
        "oldpower",
        "lqi",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int mhcMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgType")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "forward")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "totalCount")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgId")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "restEnergy")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "power")==0) return base+8;
    if (fieldName[0]=='o' && strcmp(fieldName, "oldpower")==0) return base+9;
    if (fieldName[0]=='l' && strcmp(fieldName, "lqi")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *mhcMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *mhcMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int mhcMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    mhcMessage *pp = (mhcMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string mhcMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    mhcMessage *pp = (mhcMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMsgType());
        case 1: return long2string(pp->getSource());
        case 2: return long2string(pp->getDestination());
        case 3: return long2string(pp->getForward());
        case 4: return long2string(pp->getTotalCount());
        case 5: return long2string(pp->getHopCount());
        case 6: return long2string(pp->getMsgId());
        case 7: return long2string(pp->getRestEnergy());
        case 8: return long2string(pp->getPower());
        case 9: return long2string(pp->getOldpower());
        case 10: return long2string(pp->getLqi());
        default: return "";
    }
}

bool mhcMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    mhcMessage *pp = (mhcMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setMsgType(string2long(value)); return true;
        case 1: pp->setSource(string2long(value)); return true;
        case 2: pp->setDestination(string2long(value)); return true;
        case 3: pp->setForward(string2long(value)); return true;
        case 4: pp->setTotalCount(string2long(value)); return true;
        case 5: pp->setHopCount(string2long(value)); return true;
        case 6: pp->setMsgId(string2long(value)); return true;
        case 7: pp->setRestEnergy(string2long(value)); return true;
        case 8: pp->setPower(string2long(value)); return true;
        case 9: pp->setOldpower(string2long(value)); return true;
        case 10: pp->setLqi(string2long(value)); return true;
        default: return false;
    }
}

const char *mhcMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *mhcMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    mhcMessage *pp = (mhcMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


