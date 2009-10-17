#include <string.h>
#include <omnetpp.h>


class Tx2 : public cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize();
    virtual void handleMessage(cMessage *msgmoje);
};

// The module class needs to be registered with OMNeT++
Define_Module(Tx2);

void Tx2::initialize()
{
    // Initialize is called at the beginning of the simulation.
    // To bootstrap the tic-toc-tic-toc process, one of the modules needs
    // to send the first message. Let this be `tic'.

    // Am I Tic or Toc?
    if (strcmp("ticmoje", getName()) == 1)
    {
        // create and send first message on gate "out". "tictocMsg" is an
        // arbitrary string which will be the name of the message object.
        cMessage *msgmoje = new cMessage("tictocMsgmoje");
        send(msgmoje, "out");
    }
}

void Tx2::handleMessage(cMessage *msgmoje)
{
    // The handleMessage() method is called whenever a message arrives
    // at the module. Here, we just send it to the other module, through
    // gate `out'. Because both `tic' and `toc' does the same, the message
    // will bounce between the two.
    send(msgmoje, "out");
}
