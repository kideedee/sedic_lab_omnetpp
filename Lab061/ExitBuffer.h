/*
 * ExitBuffer.h
 *
 *  Created on: May 9, 2020
 *      Author: kidee
 */
#ifndef __EXITBUFFER_H_
#define __EXITBUFFER_H_

#include<bits/stdc++.h>
#include<omnetpp.h>
#include"lab061Msg_m.h"

using namespace std;
using namespace omnetpp;

class ExitBuffer: public cSimpleModule{
private:
    int counter;
    int sizeOfBuffer;
    queue<lab061Msg *> buffer;
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(ExitBuffer);

#endif //EXITBUFFER


