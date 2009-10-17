
#include <string.h>
#include <omnetpp.h>


/**
 * In this class we add some debug messages to prvek. When you run the
 * simulation in the OMNeT++ GUI Tkenv, the output will appear in
 * the main text window, and you can also open separate output windows
 * for `tic' and `toc'.
 */
class prvek : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(prvek);

void prvek::initialize()
{
    if (strcmp("bla", getName()) == 0)
    {
        // The `ev' object works like `cout' in C++.
        EV << "Sending initial message JOOOO\n";
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void prvek::handleMessage(cMessage *msg)
{
    // msg->getName() is name of the msg object, here it will be "tictocMsg".
    EV << "Received messagePRIJMUTO `" << msg->getName() << "', sending it out again\n";
    send(msg, "out");
}

