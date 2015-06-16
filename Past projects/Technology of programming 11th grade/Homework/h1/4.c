// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име: Едуард Федев Калфов

/*Задача: Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y.
 Да се намерят и изведат всички числа на Фибоначи в интервала [x, y].
*/

#include <stdio.h>

int main(){
	int x,y,n,c;

	printf("Enter number: ");
	scanf("%d",&y);

	x=1;
	c=1;
	n=0;
	while(c<y){
            n=n+c;
            c=c+n;
            if(n>y) break;
            printf("Fibonnaci number: %d\n",n);
            if(c>y) break;
            printf("Fibonnaci number: %d\n",c);
            x=x+1;
            }


	scanf("%d",c);
	return 0;
}

