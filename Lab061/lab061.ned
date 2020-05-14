//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
simple SourceQueue
{
    parameters:
        double cycle  @unit(ms);
        @display("i=block/queue");
    gates:
        output out;
}

simple ExitBuffer extends SourceQueue
{
    parameters:
        @display("i=block/routing");
        int sizeOfEXB = 2;
        bool isFull = default(false);
    gates:
        input in;
}

module Node1
{
    parameters:
        @display("i=misc/node_vs, gold");
    gates:
        output out;
    submodules:
        queue: SourceQueue;
        buffer: ExitBuffer;
    connections:
        queue.out --> buffer.in;
        buffer.out --> out;
}

simple Node2
{
    parameters:
        @display("i=misc/node_vs, cyan");
        bool msgArrived = default(false);
    gates:
        input in;
}

network Lab061
{
    parameters:
        double delay @unit(ms);
        double intervalTime @unit(ms);
        double maxTime @unit(ms);
    types:
        channel WAB extends ned.DelayChannel
        {
            delay = delay;
        }
    submodules:
        source: Node1;
        destination: Node2;
    connections:
        source.out --> WAB --> destination.in;
}
