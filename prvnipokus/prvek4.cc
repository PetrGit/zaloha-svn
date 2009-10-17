#include<omnetpp.h>
#include<string.h>
#include <stdio.h>

class Prvek4: public cSimpleModule {
private:
	int pocitadlo;
	cMessage *mujevent; //ukazatel na objekt pro casovani
	cMessage *mojeMsg; // variable to remember the message until we send it back
protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
public:
	Prvek4();
	virtual ~Prvek4();
};

Define_Module(Prvek4);

Prvek4::Prvek4()
{
    // Set the pointer to NULL, so that the destructor won't crash
    // even if initialize() doesn't get called because of a runtime
    // error or user cancellation during the startup process.
    mujevent = mojeMsg = NULL;
}

Prvek4::~Prvek4()
{
    // Dispose of dynamically allocated the objects
    cancelAndDelete(mujevent);
    delete mojeMsg;
}

void Prvek4::initialize() {

	pocitadlo = par("limit");
	WATCH(pocitadlo);

	 // Create the event object we'll use for timing -- just any ordinary message.
	    mujevent = new cMessage("mujevent");

	    // No tictoc message yet.
	    mojeMsg = NULL;


	if (par("sendMsgOnInit").boolValue() == true) {
		// The `ev' object works like `cout' in C++.		ZAKOMENTOVANO ptz to prekazi pro krok 6.
//		EV<< "Sending initial message JOOOO\n";
//		cMessage *msg = new cMessage("tictocMsg");
//		send(msg, "ven");

		 // We don't start right away, but instead send an message to ourselves
		        // (a "self-message") -- we'll do the first sending when it arrives
		        // back to us, at t=5.0s simulated time.
		        EV << "Scheduling first send to t=5.0s\n";
		        mojeMsg = new cMessage("mojeMsg");
		        scheduleAt(5.0, mujevent);
	}
}

void Prvek4::handleMessage(cMessage *msg) {
	// decrement counter and check value.
//	pocitadlo--;
//	if (pocitadlo == 0) {
//		// If counter is zero, delete message. If you run the model, you'll
//		// find that the simulation will stop at this point with the message
//		// "no more events".
//		EV<< getName() << "'s pocet reached zero, deleting message\n";
//		delete msg;
//	}
//	else
//	{
//		EV << getName() << "'s pocitadlo is " << pocitadlo <<", sending back message\n";
//	        send(msg, "ven");
//	    }
	 // There are several ways of distinguishing messages, for example by message
	    // kind (an int attribute of cMessage) or by class using dynamic_cast
	    // (provided you subclass from cMessage). In this code we just check if we
	    // recognize the pointer, which (if feasible) is the easiest and fastest
	    // method.
	    if (msg==mujevent)
	    {
	        // The self-message arrived, so we can send out tictocMsg and NULL out
	        // its pointer so that it doesn't confuse us later.
	        EV << "Wait period is over, sending back message\n";
	        send(mojeMsg, "ven");
	        mojeMsg = NULL;
	    }
	    else
	    {
	        // If the message we received is not our self-message, then it must
	        // be the tic-toc message arriving from our partner. We remember its
	        // pointer in the tictocMsg variable, then schedule our self-message
	        // to come back to us in 1s simulated time.
	        EV << "Message arrived, starting to wait 1 sec...\n";
	        mojeMsg = msg;
	        scheduleAt(simTime()+1.0, mujevent);
	    }


	}
