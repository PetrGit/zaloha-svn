simple Txc7
{
    parameters:
        volatile double delayTime @unit(s);   // delay before sending back message
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

network Tictoc7
{
    submodules:
        tic: Txc7 {
            parameters:
                @display("i=,cyan");
        }
        toc: Txc7 {
            parameters:
                @display("i=,gold");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
