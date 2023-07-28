#include <stdio.h>
#include <stdlib.h>

const int t = 2;

typedef struct Btree
{
	int n;
	int keys[3];
	struct Btree *child[4];
	int leaf;
} Btree;

typedef struct
{
	int index;
	Btree *node;
} found;

Btree *create()
{
	int key, i = 0;
	Btree *node = (Btree *)malloc(sizeof(Btree));
	node->n = 0;
	printf("Enter keys(press -1 to STOP)\n->");
	do
	{
		scanf("%d", &key);
		if (key == -1)
		{
			break;
		}
		node->keys[i++] = key;
		(node->n)++;
	} while (1);
	printf("Is this Node Leaf or not? (Y/N): ");
	char ok;
	scanf(" %c", &ok);
	if (ok == 'N')
	{
		node->leaf = 0;
		printf("Enter left subtree of %d\n", node->keys[0]);
		node->child[0] = create();
		for (int i = 0; i < node->n; i++)
		{
			printf("Enter right subtree of %d\n", node->keys[i]);
			node->child[i + 1] = create();
		}
	}
	else
	{
		node->leaf = 1;
	}
	return node;
}

void traverse(Btree *root)
{
	if (root != NULL)
	{
		for (int i = 0; i < root->n + 1; i++)
		{
			if (!root->leaf)
				traverse(root->child[i]);
			if (i < root->n)
				printf("|%d", root->keys[i]);
		}
	}
}

found max(Btree *root)
{
	if (root->leaf)
	{
		found here;
		here.node = root;
		here.index = root->n - 1;
		return here;
	}
	else
	{
		max(root->child[root->n]);
	}
}

found min(Btree *root)
{
	if (root->leaf)
	{
		found here;
		here.node = root;
		here.index = 0;
		return here;
	}
	else
	{
		min(root->child[0]);
	}
}

found successor(Btree *root, int ind, Btree *temp, int key)
{
	int i = 0;
	while (i < root->n && root->keys[i] < key)
		i++;
	if (i < root->n && root->keys[i] == key)
	{
		if (root->leaf)
		{
			found here;
			if (i == root->n - 1)
			{
				if (ind != -1)
					here.node = temp;
				else
					here.node = NULL;
				here.index = ind;
				return here;
			}
			else
			{
				here.index = i + 1;
				here.node = root;
				return here;
			}
		}
		else
			return min(root->child[i + 1]);
	}
	if (i == root->n)
		return successor(root->child[i], ind, temp, key);
	else
		return successor(root->child[i], i, root, key);
}

found predecessor(Btree *root, int ind, Btree *temp, int key)
{
	int i = 0;
	while (i < root->n && root->keys[i] < key)
		i++;
	if (i < root->n && root->keys[i] == key)
	{
		if (root->leaf)
		{
			found here;
			if (i == 0)
			{
				if (ind != -1)
					here.node = temp;
				else
					here.node = NULL;
				here.index = ind;
				return here;
			}
			else
			{
				here.index = i - 1;
				here.node = root;
				return here;
			}
		}
		else
			return max(root->child[i]);
	}
	if (i == 0)
		return predecessor(root->child[i], ind, temp, key);
	else
		return predecessor(root->child[i], i - 1, root, key);
}

found search(Btree *root, int key)
{
	int i = 0;
	while (i < root->n && root->keys[i] < key)
	{
		i++;
	}
	found here;
	here.index = i;
	here.node = root;
	if (i < root->n && root->keys[i] == key)
	{
		return here;
	}
	if (root->leaf)
	{
		here.node = NULL;
		return here;
	}
	search(root->child[i], key);
}

void split_child(Btree *root, int ind)
{
	Btree *extra = (Btree *)malloc(sizeof(Btree));
	extra->n = 0;
	extra->leaf = root->child[ind]->leaf;
	// printf("ok");
	// from i= t to i= 2*t-1
	// at the top t=2
	for (int i = 2; i < 2 * 2 - 1; i++)
	{
		extra->keys[extra->n++] = root->child[ind]->keys[i];
	}
	// from i= t to i= 2*t
	for (int i = 2; i < 2 * 2 && !root->leaf; i++)
	{
		// printf("ok%d ", i);
		extra->child[i - 2] = root->child[ind]->child[i];
	}
	// t-1=1
	root->child[ind]->n = 1;
	/* (t-1)th is the middle key  */
	// disk_read requires
	int key = root->child[ind]->keys[1];
	int j = root->n - 1;
	while (j >= 0 && root->keys[j] > key)
	{
		root->keys[j + 1] = root->keys[j];
		root->child[j + 2] = root->child[j + 1];
		j--;
	}
	root->keys[j + 1] = key;
	root->child[j + 2] = extra;
	root->n++;
}

void insert_in_non_full(Btree *root, int key)
{
	if (root->leaf==1)
	{
		/* this node is leaf */
		int i = root->n - 1;
		while (i >= 0 && root->keys[i] > key)
		{
			root->keys[i + 1] = root->keys[i];
			i--;
		}
		root->keys[i + 1] = key;
		root->n++;
	}
	else
	{
		int i = 0;
		while (i < root->n && root->keys[i] < key)
		{
			i++;
		}
		if (root->child[i]->n == 3)
		{
			/* if this child is full */
			split_child(root, i);
			if (root->keys[i] < key)
				i++;
			/* don't know where to insert, either in ith child or (i+1)th child */
		}
		insert_in_non_full(root->child[i], key);
	}
}

void insert(Btree **root, int key)
{
	if ((*root)->n == 3)
	{
		/* root_split */
		Btree *new_root = (Btree *)malloc(sizeof(Btree));
		new_root->leaf = 0;
		new_root->n = 0;
		new_root->child[0] = *root;
		*root = new_root;
		split_child(*root, 0);
	}
	insert_in_non_full(*root, key);
}

void BTREE(Btree *root)
{
	int a, data, key, flag;
	found ans;
	do
	{
		printf("\n\n1.INSERTION\n2.SUCCESSOR\n3.PREDECESSOR\n4.INORDER\n");
		printf("5.SEARCHING\n6.TREE_MINIMUM\n7.TREE_MAXIMUM\n0.STOP\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("->Enter an integer to be inserted: ");
			scanf("%d", &data);
			insert(&root, data);
			break;
		case 2:
			printf("->kiska successor find karna hai: ");
			scanf("%d", &key);
			ans = search(root, key);
			if (ans.node == NULL)
			{
				printf("->Given element Not Found.\n");
				break;
			}
			ans = successor(root, -1, NULL, key);
			if (ans.node == NULL)
				printf("->Successor of %d doesn't exist.\n", key);
			else
				printf("->Successor of %d is %d\n", key, ans.node->keys[ans.index]);
			break;
		case 3:
			printf("->kiska predecessor find karna hai: ");
			scanf("%d", &key);
			ans = search(root, key);
			if (ans.node == NULL)
			{
				printf("->Given element Not Found.\n");
				break;
			}
			ans = predecessor(root, -1, NULL, key);
			if (ans.node == NULL)
				printf("->Predecessor of %d doesn't exist.\n", key);
			else
				printf("->Predecessor of %d is %d\n", key, ans.node->keys[ans.index]);
			break;
		case 4:
			if (root == NULL)
				printf("->Tree is empty.\n");
			else
				traverse(root);
			printf("|\n");
			break;
		case 5:
			printf("->searching for which element: ");
			scanf("%d", &key);
			ans = search(root, key);
			if (ans.node == NULL)
				printf("->Not Found.\n");
			else
				printf("->Successfully Found.\n");
			break;
		case 6:
			ans = min(root);
			printf("->Minimum value in the BST is %d.\n", ans.node->keys[ans.index]);
			break;
		case 7:
			ans = max(root);
			printf("->Maximum value in the BST is %d.\n", ans.node->keys[ans.index]);
			break;
		default:
			if (a != 0)
				printf("->Incorrect choice.\n");
		}
	} while (a);
}

int main()
{
	int key;
	printf("Entered Btree should be valid\n");
	printf("maximum 3 keys and minimum 1 keys are permissible\n");
	Btree *root = create();
	BTREE(root);
}

/*
valid Btree sample case , just copy paste after running

500 1000 -1 N
100 200 -1 N
50 -1 Y
150 -1 Y
250 350 -1 Y
600 700 800 -1 N
550 -1 Y
650 -1 Y
750 -1 Y
900 -1 Y
1500 2500 -1 N
1001 -1 Y
1569 -1 Y
2969 -1 Y
*/

/*
hard coded node child connections
Btree* root=(Btree*)malloc(sizeof(Btree));
root->n=-1;
root->keys[++root->n]=500;
root->child[root->n]==NULL;
root->keys[++root->n]=1000;
root->child[root->n]==NULL;
root->child[root->n+1]==NULL;


Btree* root1=(Btree*)malloc(sizeof(Btree));
root->child[0]=root1;//connecting with 0th child
root1->n=-1;
root1->keys[++root1->n]=100;
root1->child[root1->n]=NULL;
root1->keys[++root1->n]=200;
root1->child[root1->n]=NULL;
root1->child[root1->n+1]=NULL;


Btree* root2=(Btree*)malloc(sizeof(Btree));
root->child[1]=root2;//connecting with 1st child
root2->n=-1;
root2->keys[++root2->n]=600;
root2->child[root2->n]=NULL;
root2->keys[++root2->n]=700;
root2->child[root2->n]=NULL;
root2->keys[++root2->n]=800;
root2->child[root2->n]=NULL;
root2->child[root2->n+1]=NULL;


Btree* root3=(Btree*)malloc(sizeof(Btree));
root->child[2]=root3;//connecting with 2nd child
root3->n=-1;
root3->keys[++root3->n]=1500;
root3->child[root3->n]=NULL;
root3->keys[++root3->n]=2500;
root3->child[root3->n]=NULL;
root3->child[root3->n+1]=NULL;


Btree* root4=(Btree*)malloc(sizeof(Btree));
root1->child[0]=root4;
root4->n=-1;
root4->keys[++root4->n]=50;
root4->child[root4->n]=NULL;
root4->child[root4->n+1]=NULL;


Btree* root5=(Btree*)malloc(sizeof(Btree));
root1->child[1]=root5;
root5->n=-1;
root5->keys[++root5->n]=150;
root5->child[root5->n]=NULL;
root5->child[root5->n+1]=NULL;


Btree* root6=(Btree*)malloc(sizeof(Btree));
root1->child[2]=root6;
root6->n=-1;
root6->keys[++root6->n]=250;
root6->child[root6->n]=NULL;
root6->keys[++root6->n]=350;
root6->child[root6->n]=NULL;
root6->child[root6->n+1]=NULL;
 */