/*
 * node2.cc
 *
 *  Created on: May 12, 2020
 *      Author: kidee
 */
#include"node2.h"

void Node2::handleMessage(cMessage *msg) {
    lab061Msg *lmsg = check_and_cast<lab061Msg*>(msg);
    if (lmsg != NULL) {
        double intervalTime =
                this->getParentModule()->par("intervalTime").doubleValue();
        int interval = simTime().dbl() * 1000 / intervalTime;
        msgPerInterval[interval]++;
    }
}

void Node2::finish() {
    for (int i = 0; i < msgPerInterval.size(); i++) {
        EV << "Inteverl " << i << ": " << msgPerInterval[i] << " message"
                  << endl;
    }
}

