#include <stdio.h>
#include <time.h>
int main(){
    
           int x=1,p,n1,n2,n3,n4;
           int temp1,temp2;
          
           printf("Vuvedete P(2<P<50): ");
           scanf("%d", &p);
           printf("Vuvedete N1: ");
           scanf("%d", &n1);
         /*  printf("Vuvedete N2: ");
           scanf("%d", &n2);
           printf("Vuvedete N3: ");
           scanf("%d", &n3);
           printf("Vuvedete N4: ");
           scanf("%d", &n4); */
           
           temp1 = p*x;               
           temp2 = (p*x)+1; 
                        
           printf("\n %d %d",temp1,temp2);
           
           
           
           
    sleep(6000);
    return 0;   
}
