 #include <stdio.h>
 #include "item.h"
 #include <stdlib.h>
 typedef struct QueueNode* Link;
 struct QueueNode{
        Item item;
        Link next;
 };
 
 static Link head,tail;
 
 void InitQueue();
 void Enqueue(Item item);
 Item Dequeue();
 Item Peek();
