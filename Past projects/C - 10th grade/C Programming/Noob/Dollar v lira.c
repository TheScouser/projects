#include <stdio.h>
#include <time.h>

int dol_pou(void);

int main(void)
{
    int pound;
    
    pound=dol_pou();
    printf("%d dollars are equal to %d pounds",pound*2,pound);
    sleep(3000);
    
    return 0;
}

int dol_pou(void)
{ 
    int dollar;
    printf("Vuvedete chislo: ");
    scanf("%d",&dollar);
    return dollar/2;
}
