#include<omnetpp.h>
#include<string.h>
#include <stdio.h>

class Prvek3: public cSimpleModule {
private:
	int pocitadlo;
protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
};

Define_Module(Prvek3)
;

void Prvek3::initialize() {

	pocitadlo = par("limit");
	WATCH(pocitadlo);

	if (par("sendMsgOnInit").boolValue() == true) {
		// The `ev' object works like `cout' in C++.
		EV<< "Sending initial message JOOOO\n";
		cMessage *msg = new cMessage("tictocMsg");
		send(msg, "ven");
	}
}

void Prvek3::handleMessage(cMessage *msg) {
	// decrement counter and check value.
	pocitadlo--;
	if (pocitadlo == 0) {
		// If counter is zero, delete message. If you run the model, you'll
		// find that the simulation will stop at this point with the message
		// "no more events".
		EV<< getName() << "'s pocet reached zero, deleting message\n";
		delete msg;
	}
	else
	{
		EV << getName() << "'s pocitadlo is " << pocitadlo <<", sending back message\n";
	        send(msg, "ven");
	    }

	}
