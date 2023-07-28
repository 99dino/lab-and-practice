#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*  Traversal ✓
    Searching ✓
    Insertion ✓
    Predecessor ✓
    Successor ✓
    Deletion ✓
    Tree Minimum ✓
    Tree Maximum ✓
*/


typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
}tree;

tree* createnode(int data){
    tree* node=(tree*)malloc(sizeof(tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    node->parent=NULL;
    return node;
}

tree* searching(tree* root,int key){
    if(root==NULL||root->data==key)
        return root;
    else if(root->data>key){
        searching(root->left,key);
    }
    else{
        searching(root->right,key);
    }
}

void insert(tree** root,int key){
    if(*root==NULL){
        *root=createnode(key);
        // (*root)->data=key;
        // (*root)->parent=NULL;
        return;
    }
    if((*root)->data>key){
        if((*root)->left!=NULL){
            insert(&((*root)->left),key);
        }
        else{
            tree* new=createnode(key);
            new->parent=*root;
            (*root)->left=new;
        }
    }
    else{
        if((*root)->right!=NULL){
            insert(&((*root)->right),key);
        }
        else{
            tree* new=createnode(key);
            new->parent=*root;
            (*root)->right=new;
        }
    }
}

void inorder(tree* root){
    if(root!=NULL){
        inorder(root->left);
        printf("| %d ",root->data);
        inorder(root->right);
    }
}
void preorder(tree* root){
    if(root!=NULL){
        printf("| %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(tree* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("| %d ",root->data);
    }
}

tree* treemin(tree* root){
    if(root==NULL){
        printf("BST is empty.\n");
        return NULL;
    }
    if(root->left==NULL)
        return root;
    else
        return treemin(root->left);
}

tree* treemax(tree* root){
    if(root==NULL){
        printf("BST is empty.\n");
        return NULL;
    }
    if(root->right==NULL)
        return root;
    else
        return treemax(root->right);
}

tree* successor(tree* root,int key){
    tree* temp=searching(root,key);
    if(temp==NULL){
        printf("No Such Element exist in the BST\n");
        return NULL;
    }
    if(temp->right!=NULL){
        temp=temp->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    tree* node=temp->parent;
    while(node!=NULL&&node->right==temp){
        temp=node;
        node=temp->parent;
    }
    return node;
}

tree* predecessor(tree* root,int key){
    tree* temp=searching(root,key);
    if(temp==NULL){
        printf("No Such Element exist in the BST\n");
        return NULL;
    }
    if(temp->left!=NULL){
        temp=temp->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    tree* node=temp->parent;
    while(node!=NULL&&node->left==temp){
        temp=node;
        node=temp->parent;
    }
    return node;
}
void deletion(tree** root,int key){
    tree* temp=searching(*root,key);
    if(temp==NULL||*root==NULL){
        printf("No Such Element exist in the BST\n");
        // *root=NULL;
        return;
    }
    if(temp->left==NULL&&temp->right==NULL){
        if(temp->parent==NULL){
            *root=NULL;
        }
        else if(temp->parent->left==temp){
            temp->parent->left=NULL;
        }
        else{
            temp->parent->right=NULL;
        }
        free(temp);
    }
    else if(temp->left==NULL&&temp->right!=NULL){
        if(temp->parent==NULL){
            *root=temp->right;
        }
        else if(temp->parent->left==temp){
            temp->parent->left=temp->right;
        }
        else{
            temp->parent->right=temp->right;
        }
        temp->right->parent=temp->parent;
        free(temp);
    }
    else if(temp->right==NULL&&temp->left!=NULL){
        if(temp->parent==NULL){
            *root=temp->left;
        }
        else if(temp->parent->left==temp){
            temp->parent->left=temp->left;
        }
        else{
            temp->parent->right=temp->left;
        }
        temp->left->parent=temp->parent;
        free(temp);
    }
    else{
        int succ=successor(*root,temp->data)->data;
        temp->data=succ;
        deletion(&(temp->right),succ);
    }
}

void binarytrees(tree* root){
    int a,data,key,flag;
    tree* ans;
    do
    {
        printf("1.INSERTION\n2.DELETION\n3.SUCCESSOR\n4.PREDECESSOR\n5.INORDER\n6.PREORDER\n");
        printf("7.POSTORDER\n8.SEARCHING\n9.TREE_MINIMUM\n10.TREE_MAXIMUM\n0.STOP\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("->Enter an integer to be inserted: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            printf("->Enter an integer to be deleted: ");
            scanf("%d", &data);
            deletion(&root, data);
            break;
        case 3:
            printf("->kiska successor find karna hai: ");
            scanf("%d", &data);
            ans = successor(root, data);
            if (ans == NULL)
                printf("->Successor of %d doesn't exist.\n");
            else
                printf("->Successor of %d is %d\n", data, ans->data);
            break;
        case 4:
            printf("->kiska predecessor find karna hai: ");
            scanf("%d", &data);
            ans = predecessor(root, data);
            if (ans == NULL)
                printf("->Predecessor of %d doesn't exist.\n");
            else
                printf("->Predecessor of %d is %d\n", data, ans->data);
            break;
        case 5:
            if (root == NULL)
                printf("->Tree is empty.");
            else
                inorder(root);
            printf("|\n");
            break;
        case 6:
            if (root == NULL)
                printf("->Tree is empty.");
            else
                preorder(root);
            printf("|\n");
            break;
        case 7:
            if (root == NULL)
                printf("->Tree is empty.");
            else
                postorder(root);
            printf("|\n");
            break;
        case 8:
            printf("->searching for which element: ");
            scanf("%d", &data);
            ans = searching(root, data);
            if (ans == NULL)
                printf("->Not Found.\n");
            else
                printf("->Successfully Found.\n");
            break;
        case 9:
            printf("->Minimum value in the BST is %d.\n", treemin(root)->data);
            break;
        case 10:
            printf("->Maximum value in the BST is %d.\n", treemax(root)->data);
            break;
        default:
            if (a != 0)
                printf("->Incorrect choice.\n");
        }
    } while (a);
}
int main(){
    tree* root=NULL;
    int n;
    printf("No of nodes at the time of creation ?");
    scanf("%d",&n);
    printf("Enter distinct values only.\n-> ");
    while(n--){
        int x;
        scanf("%d",&x);
        insert(&root,x);
    }
    binarytrees(root);
}
// 90 1 78 2 32 67 102 7
