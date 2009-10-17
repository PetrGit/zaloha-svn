simple Prvek3
{
    parameters:
        @display("i=block/routing,blue");
    gates:
        input dovnitr;
        output ven;

}

network Tictoc3
{
    submodules:
        tik: Prvek3;
        tak: Prvek3;
    connections:
        tik.ven --> {  delay = 100ms; } --> tak.dovnitr;
        tik.dovnitr <-- tak.ven;

}
