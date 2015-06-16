#include <stdio.h>


int main(){
    
    int currentTemp=300;
    float far;
    printf("From Farenhait to Celsius\n");
    while(currentTemp>=0)
    {
        far=(9.0*currentTemp/5.0)+32;
        
        if (far==60) {printf("BINGO!!!");}
        
        printf("%d %f\n",currentTemp,far);
        currentTemp -=20;
        
        }
        
        return 0;
    }
