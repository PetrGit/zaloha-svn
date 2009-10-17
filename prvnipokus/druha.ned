simple prvek
{
    parameters:
        @display("i=block/wheelbarrow,red"); // add a default icon

    gates:
        input in;
        output out;

}
network Druha
{
    @display("bgl=2");
    submodules:
        bla: prvek {
            @display("i=block/routing,cyan");
        }
        bli: prvek;
    connections:
        bla.out --> bli.in;
        bla.in <-- bli.out;
}
