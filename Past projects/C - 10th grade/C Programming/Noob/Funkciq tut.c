#include <stdio.h>
#include <time.h>

void func1(void);
void func2(void);

int main(void)
{
    func1();
    func2();
    sleep(2000);
    
    return 0;
}

void func1(void)
{
     printf("The summer soldier,");
}

void func2(void)
{
     printf("the sunshine patriot.");
}    
