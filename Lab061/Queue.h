/*
 * Queue
 *
 *  Created on: May 9, 2020
 *      Author: kidee
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include<bits/stdc++.h>
#include<omnetpp.h>
#include"lab061Msg_m.h"

using namespace std;
using namespace omnetpp;

class SourceQueue: public cSimpleModule{
private:
    int counter;
    double cycle;
    queue <lab061Msg *> queue;
protected:
    virtual lab061Msg *generateMessage();
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(SourceQueue);



#endif /* QUEUE_H_ */
