#include "Queue.h"

void InitQueue()
{
     head = NULL;
     tail = NULL;
     
}

Link New(Item item,Link next)
{
     Link newNode = (Link)malloc(sizeof(*newNode));
     newNode->item=item;
     newNode->next=next;
     return newNode;
}

void Enqueue(Item item)
{
     if(head==NULL){
        tail=New(item,NULL);
        head = tail;
     }
     tail->next= New(item,tail->next);
     tail = tail->next;
}

Item Dequeue()
{
     Item result = head->item;
     Link tmp = head;
     head = head->next;
     free(tmp);
     return result;
}
