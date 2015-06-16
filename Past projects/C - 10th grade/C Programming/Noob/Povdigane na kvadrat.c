#include <stdio.h>
#include <time.h>

int get_sqr(void);

int main(void)
{
    int sqr;
    
    sqr=get_sqr();
    printf("%d",sqr);
    sleep(2000);   
    return 0;
}

int get_sqr(void)
{
    int num;
    printf("Vuvedete chislo: ");
    scanf("%d",&num);
    return num*num;
}
