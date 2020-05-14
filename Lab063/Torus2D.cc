/*
 * Torus2D.cc
 *
 *  Created on: May 9, 2020
 *      Author: kidee
 */
#include<bits/stdc++.h>
#include<omnetpp.h>

using namespace std;
using namespace omnetpp;

class Switch: public cSimpleModule{
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Switch);

void Switch:: initialize(){}

void Switch::handleMessage(cMessage *msg){}
