// �������: ���� ( http://www.elsys-bg.org/ )
// ����: 11 �
// �����: 16
// ���: ������ ����� ������

/*������: �� �� ��������� ��������, ����� ������� �� ����������� �� ������ ��� ����������� �����, x � y, ������ x < y.
�� �� ������� � ������� ������ ������ ����� ���������� �� 3 � �������� [x,y].
*/

#include <stdio.h>

int main(){
	int x,y,n,c;
	while(x>y){
	printf("Enter two numbers: ");
	scanf("%d %d",&x,&y);
	}

		  for (n=x; n<=y; n++){

        if(n%10==3){
            for ( c = 2 ; c <= n - 1 ; c++ ){
                      if ( n%c == 0 ){

                 break;
                      }
               }
               if ( c == n )
                      printf("%d is prime.\n", n);

                      }
                      }

	scanf("%d",c);
	return 0;
}

