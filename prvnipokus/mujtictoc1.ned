
//Describe your example network by creating a topology file. 
//A topology file is a text file that identifies the network's nodes and the links between them

simple Txc1
{
    gates:
        input in;
        output out;
}

simple Tx2 //moje
{
    gates:
        input in;
        //input in2;		//# mozna ze bude problem s tim ze neni vyuzit
        output out;
}

channel notIdealChannel extends ned.DatarateChannel //moje
{
    datarate = 10Mbps;
    ber = 5e-10;

}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network Tictoc1
{
    submodules:
        tic: Txc1;
        toc: Txc1;
        tam: Tx2;
        zpet: Tx2;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
        tam.out --> {  delay = 10ms; } --> zpet.in;
        tam.in <-- notIdealChannel <-- zpet.out;





}
