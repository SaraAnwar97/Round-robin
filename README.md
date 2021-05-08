# LinkedList-based-queue
## About
A queue differs from a stack in that its insertion and removal routines follow the first-in, first
out (FIFO) principle Elements may be inserted at any time, but only the element, which has
been in the queue the longest, may be removed.
Elements are inserted at the rear (enqueued) and removed from the front (dequeued). So there
are 2 main operations in queue Enqueue and Dequeue.<br>
A Queue linked list based C program is implemented with the following functions:- <br>
1• Initialize<br>
It initializes queue, and make the head pointer equals NULL.<br>
Prototype: void initialize(Queue *s);<br>
2• Dequeue<br>
It removes the first inserted element in the Queue and return it, and deletes its node.<br>
Prototype: int dequeue (Queue *s);<br>
3• Enqueue<br>
It allocates a new node and attach it to the queue,then it inserts element at the end of<br>
the queue.<br>
Prototype : void enqueue(Queue *s,int value)<br>
4• isEmpty<br>
It returns 1 if queue is empty or 0 otherwise.<br>
Prototype: int isEmpty(Queue *s);<br>
## Application(Round Robin)<br>
One of the main functions of the operation system is to schedule processes that the processor
executes. One of the very popular algorithms for this scheduling is called Round Robin, where
each process enters a queue, executes in a FIFO order, and after a specified time its execution
stops and returns back at the end of the queue if it still need time to continue execution or
aborts if it has finished its required time of execution.
A file is given with the name of the processes that needs execution, time slot that it
will enter the queue, and the needed time for it’s execution.
## Algorithm<br>
The given input file has the watching time slots in the first line, then in the successive
lines , the name of the process, time it enters the queue, and the needed time for
execution respectively.
The output is the scheduling of the processes, showing when does each process abort
and when does the processor is idle(no processes in the queue).<br>
Each process should enter the queue whenever its execution time comes.<br>
Each process will be grant 1 time slot on execution, if its execution time finishes it will abort,
else it will be sent again to the queue and its execution time will be subtracted by 1.

## Example:<br>
### Input:<br>
watching time slots = 15<br>
P1 0 3<br>
P2 0 2<br>
P3 3 1<br>
P4 10 3<br>
### Output:<br>
P1 (0-->1)<br>
P2 (1-->2)<br>
P1 (2-->3)<br>
P2 (3-->4) P2 aborts<br>
P3 (4-->5) P3 aborts<br>
P1 (5-->6) P1 aborts<br>
idle (6-->7)<br>
idle (7-->8)<br>
idle (8-->9)<br>
idle (9-->10)<br>
P4 (10-->11)<br>
P4 (11-->12)<br>
P4 (12-->13) P4 aborts<br>
idle (13-->14)<br>
idle (14-->15)<br>
stop<br>
