// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име: Едуард Федев Калфов

/*Задача: Да се разработи програма,  която изисква от потребителя да въведе четири числа x, y, w, h където x>0, y>0, w>0, h>0.
Числото x е дължината на плоча дървесина, а числото y е височината. Да се определи на колко цели плочи с размери w, h може да се разреже голямата плоча.
 Да се инициализира масив от 10 елемента.
Стойностите на елементите на масива да са първите 10 координати по дължина на плочата, в които тя трябва да се разреже, за да се получат по-малките плочи.
*/

#include <stdio.h>

int main(){
    int x,y,w,h;
    int a,b,c,i;
    int arr[10];
    printf("Vuvedete x>0: ",x);
    scanf("%d",&x);
    printf("Vuvedete x>0: ",y);
    scanf("%d",&y);
    printf("Vuvedete x>0: ",w);
    scanf("%d",&w);
    printf("Vuvedete x>0: ",h);
    scanf("%d",&h);

    a=x/w;
    b=y/h;
    c=a*b;
    printf("Golqmata plocha moje da se razreje na %d malki plochi\n",c);
    a=0;
    for(i=0;i<10;i++){
       arr[i]=a+w;
       a=a+w;
       }
       for(i=0;i<10;i++){
       printf("%d\n",arr[i]);
       }
    scanf("%d",a);
    return 0;
}
