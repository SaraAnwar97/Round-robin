#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
 char word[50];
 int count=0;
typedef struct{
    char name[50];
    int start_time;
    int execution_time;
}Process; // Structure of Process
#define TYPE Process
int timeslots;
Process p[100];
typedef struct Node{
TYPE data;
struct Node *next;
}Node; // Structure of Node

typedef struct {
Node *front,*rear;
}Queue; // Structure of Queue

Node* newNode(TYPE value){
Node *n=(Node*)malloc(sizeof(Node));
n->data=value;
n->next=NULL;
return n;} // A function to add a new node to the linked list
void initialize(Queue *q){
q->front=q->rear=NULL;
 } // A function to initialize the queue
 int isEmpty(Queue *q){
return q->front==NULL? TRUE:FALSE;
} // A function to check wether the queue is empty of nodes or not
void enqueue(Queue* q,TYPE value){
Node* n=newNode(value);
if(isEmpty(q))
    q->front=q->rear=n;
    else{
        q->rear->next=n;
        q->rear=n;
    }} // A function to insert a node to the queue
TYPE dequeue(Queue* q){
if(!isEmpty(q))
    {
        TYPE value=q->front->data;
        Node *n=q->front;
        q->front=q->front->next;
        free(n);
        if(isEmpty(q))
            q->rear=q->front=NULL;
        return value;
    }
    else{
        printf("[UNDERFLOW] Can't dequeue cause queue is empty!\n");
        exit(1);
    }
} // A function to remove a node from queue and return the value of node removed

void readFile(){
FILE *f;
f=fopen("roundrobin.txt","r");
if(f!=NULL){
    fscanf(f,"%[^=]=%d",word,&timeslots);
    while(!feof(f)){
        fscanf(f,"%s %d %d",p[count].name,&p[count].start_time,&p[count].execution_time);
        count++;
    }

     fclose(f);

}}// A function to read from text document "roundrobin"
void scheduleRR(){
    int j,i;
    Queue q;
    initialize(&q);
    Process temp;
for(j=0;j<count;j++){
        if(p[j].start_time==0)
            enqueue(&q,p[j]);
    }
for(i=0;i<timeslots;i++){
            if(isEmpty(&q)){
                printf("idle (%d-->%d)\n",i,i+1);
                for(j=0;j<count;j++){
                        if(p[j].start_time==i+1)
                            enqueue(&q,p[j]);}}
            else {
                temp=dequeue(&q);
                printf("%s (%d-->%d)\n",temp.name,i,i+1);
                temp.execution_time--;
                for(j=0;j<count;j++){
                         if(p[j].start_time==i+1)
                        enqueue(&q,p[j]);}
               if(temp.execution_time==0)
                printf("%s aborts\n",temp.name);
                else
                    enqueue(&q,temp);}}

        printf("stop\n");
} // A function to calculate the round robin scheduling algorithm
int main()
{ //TYPE p[100];
readFile();
scheduleRR();

    return 0;
}
