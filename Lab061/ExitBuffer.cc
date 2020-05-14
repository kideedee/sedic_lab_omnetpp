/*
 * ExitBuffer.cc
 *
 *  Created on: May 9, 2020
 *      Author: kidee
 */
#include"ExitBuffer.h"

void ExitBuffer::initialize() {
    this->sizeOfBuffer = par("sizeOfEXB").intValue();
    counter = 0;
}

void ExitBuffer::handleMessage(cMessage *msg) {
    lab061Msg *lmsg = check_and_cast<lab061Msg*>(msg);
    counter++;
    if (counter <= this->sizeOfBuffer) {
        this->buffer.push(lmsg);
    }
    if (counter == this->sizeOfBuffer) {
        par("isFull") = true;
    }
    if (this->getParentModule()->getSubmodule("destination")->par("msgArrived").boolValue()
            == true) {
        this->getParentModule()->getSubmodule("destination")->par("msgArrived") = false;
        this->send(msg, "out");
        counter--;
    }
}

