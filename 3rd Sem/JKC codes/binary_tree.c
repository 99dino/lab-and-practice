#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}tree;

tree* create(){
    int data;
    printf("Enter data(press -1 for no data/to stop): ");
    scanf("%d",&data);
    if(data==-1)
        return NULL;
    
    tree* node=(tree*)malloc(sizeof(tree));
    node->data=data;
    
    printf("Left Subtree of %d.\n",data);
    node->left=create();

    printf("Right Subtree of %d.\n",data);
    node->right=create();

    return node;
}

void find_max(tree* root,int *MAX){
    if(root==NULL)
        return;
    find_max(root->left,MAX);
    if(root->data>*MAX){
        *MAX=root->data;
    }
    find_max(root->right,MAX);
}

void traverse_inorder(tree* root){
    if(root==NULL)
        return;
    traverse_inorder(root->left);
    printf("|%d",root->data);
    traverse_inorder(root->right);
}

void find_height(tree* root,int n,int *height){
    if(root==NULL)
        return;
    if(n>*height){
        *height=n;
    }
    find_height(root->left,n+1,height);
    find_height(root->right,n+1,height);
}

void find_no_of_nodes(tree* root,int *nodes,int* leaf){
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL){
        (*leaf)++;
    }
    (*nodes)++;
    find_no_of_nodes(root->left,nodes,leaf);
    find_no_of_nodes(root->right,nodes,leaf);
}

int main(){
    // driver code
    tree* root=create();
    
    printf("\n\nInorder traversal is : ");
    traverse_inorder(root);
    printf("|\n\n");

    int max=INT_MIN;
    find_max(root,&max);
    printf("maximum element is %d\n",max);

    int height=0;
    find_height(root,1,&height);
    printf("height %d\n",height);
    
    int nodes=0,leaf=0,nonleaf;
    find_no_of_nodes(root,&nodes,&leaf);
    nonleaf=nodes-leaf;
    
    printf("No of Nodes %d\n",nodes);
    printf("No of Leaf Nodes %d\n",leaf);
    printf("No of Non Leaf Nodes %d\n",nonleaf);

}
// sample test case(just copy paste)
// 50 21 -1 41 98 -1 -1 -1 40 30 -1 -1 20 -1 -1