#include <stdio.h>
int main(){
    
    char c;
    
    while((c=getchar()) != EOF){
          switch(c){
                    case'\n':printf("\\n");
                             break;              
                    case'\t':printf("\\t");
                             break;              
                    }
                    
    
    
   }

    return 0;
}
