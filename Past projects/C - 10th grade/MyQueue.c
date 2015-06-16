#include <stdio.h>
#include<stdlib.h>
#include <time.h>
struct queue{
  int data;
  struct queue* next;     
       
};

struct queue* head=NULL;
struct queue* tail=NULL;

struct queue* create(int data){
       struct queue* next=malloc(sizeof(struct queue));
       next->data=data;
       next->next=NULL;
       return next;
       }
void Enqueue(int data){
     if(head == NULL){
             head = create(data);
             tail=head;
     }
      tail->next= create(data);
      tail = tail->next;
}

int Dequeue(){
     int i;
     if(head == NULL){
             printf("No data in the queue\n");        
             exit(1);
             }   
     else{          
     i=head->data;
     head=head->next;
     }
     return i;
}

int main(){
    Enqueue(5);
	Enqueue(10);
	Enqueue(132);
	printf("%d\n",Dequeue());
	printf("%d\n",Dequeue());	
 	printf("%d\n",Dequeue());
 	Enqueue(13414);
 	Enqueue(13234);
	printf("%d\n",Dequeue());
	printf("%d\n",Dequeue());
	sleep(6000);
    
 return 0;   
}
