//obsahuje i veci z kroku 5

simple Prvek4
{
    parameters:
        @display("i=block/routing,blue");
        bool sendMsgOnInit = default(false); // whether the module should send out a message on initialization
        int limit = default(5);  // another parameter with a default value
    gates:
        input dovnitr;
        output ven;

}

simple Prvek5 extends Prvek4
{
parameters:
        @display("i=block/routing,red");
}

network Tictoc4
{
    submodules:
        tik: Prvek4 {
            parameters:
                sendMsgOnInit = true;
        }
        tak: Prvek5 {
            parameters:
                sendMsgOnInit = false;
        }
    connections:
        tik.ven --> {  delay = 100ms; } --> tak.dovnitr;
        tik.dovnitr <-- tak.ven;

}
