/*
 * node2.h
 *
 *  Created on: May 12, 2020
 *      Author: kidee
 */

#ifndef NODE2_H_
#define NODE2_H_

#include<bits/stdc++.h>
#include<omnetpp.h>
#include<lab061Msg_m.h>

using namespace std;
using namespace omnetpp;

class Node2: public cSimpleModule{
private:
    vector<int> msgPerInterval;
protected:
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

Define_Module(Node2);

#endif /* NODE2_H_ */
