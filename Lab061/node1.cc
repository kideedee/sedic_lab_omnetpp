/*
 * node1.cc
 *
 *  Created on: May 12, 2020
 *      Author: kidee
 */
#include<omnetpp.h>
#include"lab061Msg_m.h"

using namespace omnetpp;

class Node1: public cSimpleModule{
protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Node1);

void Node1:: handleMessage(cMessage *msg){
    lab061Msg *lmsg = check_and_cast<lab061Msg *> (msg);
    send(lmsg, "out");
}

