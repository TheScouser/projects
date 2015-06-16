#include <stdio.h>
#include <time.h>

int main(void)
{
    int a,b,choice;
    
    printf("1.Subirane\n2.Umnojenie");
    scanf("%d",&choice);
    
    printf("Vuvedete chislo 1: ");
    scanf("%d",&a);
   
    printf("Vuvedete chislo 2: ");
    scanf("%d",&b);
    
    if(choice==1) printf("Sumata e: %d",a+b);
    if(choice==2) printf("Prozivedenieto e : %d",a*b);
    
    sleep(3000);
    return 0;
}
