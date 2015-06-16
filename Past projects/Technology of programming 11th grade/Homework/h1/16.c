// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име: Едуард Федев Калфов

/*Задача: Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където x e интервала [0; +∞).
Да се намерят първите 10 нечетни числа делители на x и да се запишат в масив. Масивът да се изведе на екрана и да се намерят простите числа в този масив.

*/

#include <stdio.h>

int checkPrime(int n){
   int c,isPrime=0;
   for ( c = 2 ; c <= n - 1 ; c++ ){
      if ( n%c == 0 ){
         break;
      }
   }
   if ( c == n ){
     isPrime=1;

   }
   return isPrime;
}

int main(){
    int x,y,z,count=0,i=0;
    int arr[10];
    for(y=0;y<10;y++){
       arr[y]=0;
    }
    printf("Enter a number: ");
    scanf("%d",&x);

    for(z=0;z<x;z++){
        if(z%2!=0 && x%z==0 ){
          if(count>10) break;
          arr[i]=z;
          i++;
          count++;
          }
    }
    for(y=0;y<10;y++){
       printf("Number: %d\n",arr[y]);
    }


    for(y=0;y<10;y++){
       z = checkPrime(arr[y]);
       if(z==1){
       printf("Number is prime: %d\n",arr[y]);
       }
    }
    scanf("%d",x);
    return 0;
}
