// �������: ���� ( http://www.elsys-bg.org/ )
// ����: 11 �
// �����: 16
// ���: ������ ����� ������

/*������: �� �� ��������� ��������,  ����� ������� �� ����������� �� ������ ������ ����� x, y, w, h ������ x>0, y>0, w>0, h>0.
������� x � ��������� �� ����� ���������, � ������� y � ����������. �� �� �������� �� ����� ���� ����� � ������� w, h ���� �� �� ������� �������� �����.
 �� �� ������������ ����� �� 10 ��������.
����������� �� ���������� �� ������ �� �� ������� 10 ���������� �� ������� �� �������, � ����� �� ������ �� �� �������, �� �� �� ������� ��-������� �����.
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
