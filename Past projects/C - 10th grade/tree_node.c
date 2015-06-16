#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct tree_node{
	int val;
	struct tree_node* l_child;
	struct tree_node* r_child;
};

int tree_search(int val,struct tree_node* root){
		while(root != NULL){
			if(val==root->val){
				return 1;
			}
		    else if(val > root->val){
			root=root->r_child;
			
			}
			else{
				root=root->l_child;
				
			}
				
		}
return -1;
	
	
}

struct tree_node* insert(struct tree_node* root,int key){
	if ( root == NULL ) {
    root = malloc ( sizeof*root );
    
    root->val = key;
    root->l_child = root->r_child = NULL;
  }
	
	else if(key < root->val){
		root->l_child=insert(root->l_child,key);
	}
	else{
		root->r_child=insert(root->r_child,key);
	}

return root;
}


int main(){
	int i;
	struct tree_node* tree=malloc(sizeof(struct tree_node)*7);
	for(i=0;i<7;i++){
		int j;
		j=i+1;
		tree[i].val=j;
		if(j==2 || j==6){
			tree[i].l_child = &tree[i-1];
			tree[i].r_child = &tree[i+1];
		}
		else {
			tree[i].l_child= NULL;
			tree[i].r_child= NULL;
		}
		
	}
	struct tree_node* root;
	root=&tree[3];
	root->l_child =&tree[1];
	root->r_child =&tree[5];
	root = insert(root,21);
	root = insert(root,22);
	int result = tree_search(22,root);
	if(result==1){
		printf("The element is found");
	}
	else{
		printf("The element is not found");
	}
	sleep(6000);
	return 0;
}
		
		
