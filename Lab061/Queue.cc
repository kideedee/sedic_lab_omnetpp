/*
 * Queue.cc
 *
 *  Created on: May 9, 2020
 *      Author: kidee
 */
#include"Queue.h"

lab061Msg* SourceQueue::generateMessage() {
    lab061Msg *msg = new lab061Msg("message");
    msg->setId(counter);
    counter++;
    return msg;
}

void SourceQueue::initialize() {
    counter = 0;
    cycle = par("cycle").doubleValue();
    for (int i = 0;; i++) {
        if (simTime().dbl()*1000 == cycle * i) {
            lab061Msg *msg = generateMessage();
        }
    }
}

void SourceQueue::handleMessage(cMessage *msg) {
    lab061Msg *lmsg = check_and_cast<lab061Msg*>(msg);
    this->queue.push(lmsg);
    if (this->getParentModule()->getSubmodule("exitBuffer")->par("isFull").boolValue()
            == false) {
        send(msg, "out");
    }
}

