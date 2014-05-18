/*
approach:
i traverse the given binary tree in "inorder manner"
and store the element in an array
and then later check if the array is sorted in ascending order or not?
if it is sorted-> the tree is binary search tree
if not-> the tree is not a binary search tree

space complexity  O(n)
time complexity O(n) {because we are hitting the n elements of the tree one time and then we are going through the for loop n;
}

*/


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int arr[50]; 

int arr_l=0;
void inorder(struct node *root){
if(root==NULL) return;

inorder(root->left);
arr[arr_l]=root->data;
arr_l++;
inorder(root->right);

}

int main(){
int i,j=0,k;

struct node *root = newnode(8);
 /* root->left        = newnode(-1);
  root->right       = newnode(56);
  root->left->left  = newnode(11);
  root->left->right = newnode(89);
                                      //the above tree is not a binary search tree
  */
  root->left        = newnode(4);
  root->right       = newnode(12);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left=newnode(10);
   root->right->right=newnode(14);
 
 inorder(root);
 
 printf("inorder traversal of the tree is:\n");
 for(i=0;i<arr_l;i++){printf("%d ",arr[i]);} 
 
 for(i=1;i<arr_l;i++){
 
 if(arr[i]<arr[i-1]) {j=1; break;}
 }
 
 if(j==1) printf("\nthis is not a binary search tree");
 else printf("\nthis is a binary search tree");
  getchar();
  return 0;



 


}




