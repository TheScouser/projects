// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име: Едуард Федев Калфов

/*Задача: Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<=x<10.
Да се инициализира масив от 10 елемента. Да се намерят първите 10 числа на Фибоначи в [0; +∞), които се делят на x без остатък.
Намерените стойности да се зададат като стойности на елементите в масива. Елементите на масива да се изведат на стандартния изход.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
 int a,b,x,z,y,n=0,c=0,count=0;
 int arr[10];
 for(z=0;z<10;z++){
   arr[z]=0;
 }

 printf("Enter a number(0<=x<10): ");
 scanf("%d",&y);

   	x=0;
	b=1;
	a=0;

	while(n<45){
            c=a+b;

            a=b;
            b=c;
            if(c%y==0){
               arr[x]=c;
               x++;
            }
            n++;
    }
	for(z=0;z<10;z++){
       printf("Number: %d \n",arr[z]);
    }

	scanf("%d",c);
    return 0;
}
