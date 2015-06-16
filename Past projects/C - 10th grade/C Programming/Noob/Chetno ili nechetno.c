#include <stdio.h>
#include <time.h>

int main(void)
{
    int a;
    
    printf("Vuvedete chislo: ");
    scanf("%d",&a);
    
    if((a%2)==0) printf("Chisloto e chetno");
    else printf("Chisloto e nechetno");
    
    sleep(3000);
    
    return 0;
}
