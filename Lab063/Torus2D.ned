simple Switch
{
    parameters:
        @display("i=device/switch");
    gates:
        inout gate[];
}

network Torus2D
{
    parameters:
        int nRow;
        int nCol;
        int N = nRow*nCol;
    types:
        channel C extends ned.DelayChannel
        {
            delay = 100ms;
        }
    submodules:
        switch[N]: Switch {
            parameters:
                @display("p=10,10,m,4,100");
        }
    connections allowunconnected:
        for row=0..nRow-1, for col=0..nCol-1 {
            switch[row*nCol+col].gate++ <--> C <--> switch[row*nCol + (col+1)%nCol].gate++;
            switch[row*nCol+col].gate++ <--> C <--> switch[((row+1)%nRow)*nCol + col].gate++;
        }
}

