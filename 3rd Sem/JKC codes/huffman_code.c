#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
struct message
{
    char data[50];
    int freq;
    struct message *left, *right;
    char code[50];
    int ind;
} typedef message;

void swap(message **a, message **b)
{
    message *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(message *arr[], int i, int n)
{
    int min = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[left]->freq < arr[min]->freq)
        min = left;
    if (right <= n && arr[right]->freq < arr[min]->freq)
        min = right;
    if (min != i)
    {
        swap(&arr[min], &arr[i]);
        min_heapify(arr, min, n);
    }
}

void build_min_heap(message *arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        min_heapify(arr, i, n);
}

message *extract_min(message *msg[], int *n)
{
    message *temp = msg[1];
    msg[1] = msg[*n];
    (*n)--;
    min_heapify(msg, 1, *n);
    return temp;
}

void increase_key(message *msg[], int i, int size, int key)
{
    if (msg[i]->freq >= key)
    {
        printf("-->Invalid Operation.\n");
    }
    else
    {
        msg[i]->freq = key;
        while (i > 1 && msg[i / 2]->freq > key)
        {
            swap(&msg[i], &msg[i / 2]);
            i /= 2;
        }
    }
}

void inorder(message *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("| %d ", root->freq);
        inorder(root->right);
    }
}

void insert(message *msg[], message *temp1, message *temp2, int *size)
{
    (*size)++;
    message *new = (message *)calloc(1, sizeof(message));
    new->freq = INT_MIN;
    new->left = temp1;
    new->right = temp2;
    msg[*size] = new;
    increase_key(msg, *size, *size, temp1->freq + temp2->freq);
}

message *huffmantree(message *msg[], int *n)
{
    build_min_heap(msg, *n);
    const int c = *n;
    for (int i = 0; i < c - 1; i++)
    {
        message *temp1 = extract_min(msg, n);
        message *temp2 = extract_min(msg, n);
        insert(msg, temp1, temp2, n);
    }
    return msg[1];
}

void huffmancode(message *root, message *msg[], char codes[], int ind)
{
    if (root->left == root->right && root->right == NULL)
    {
        msg[root->ind] = root;
        for (int i = 0; i < ind; i++)
        {
            msg[root->ind]->code[i] = codes[i];
        }
    }
    else
    {
        codes[ind] = '0';
        huffmancode(root->left, msg, codes, ind + 1);
        codes[ind] = '1';
        huffmancode(root->right, msg, codes, ind + 1);
    }
}

int main()
{
    int n, m;
    printf("Total distinct character(data): ");
    scanf("%d", &n);
    m = n;
    message *msg[n + 1];
    printf("Enter character-frequency pair\n");
    for (int i = 1; i <= n; i++)
    {
        msg[i] = (message *)calloc(1, sizeof(message));
        scanf("%s %d", &(msg[i]->data), &(msg[i]->freq));
        msg[i]->left = NULL; // leaf node honge ye saare
        msg[i]->right = NULL;
        msg[i]->ind = i; // to prevent data loss while inserting interanl nodes
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%s-%d\n", msg[i]->data, msg[i]->freq);
    // }

    message *root = huffmantree(msg, &n);

    printf("\nInorder traversal \n ");
    inorder(root);
    printf(" |\n");

    char code[11] = "000000000";
    int ind = 0;
    huffmancode(root, msg, code, ind);

    for (int i = 1; i <= m; i++)
    {
        printf("%s %s\n", msg[i]->data, msg[i]->code);
    }

    return 0;
}

/*
ashish 45
saksham 15
dsp 10
murari 16
priyanshu 9
akshat 5
 */

// in tools - compiler- setting-generate debugging informatio-yes kardo isko

// implement fractional kanpsack/ activity selection -- greedy algo ✓✓
// implement huffman using 2 modules
// 1) generate huffman tree 2)generate huffmann codes
// generate huffman tree should retrun a pointer to the huffman tree using priority queue of array of pointers to structures
// *structure can be using union also* of those feilds which don't exist simultaneously
// try with structure first then use union
// priority queue can also be implemented using array of structures
// in that case the extracted structures need to be copied into the left and right children every time.
// priority queue funtion are to be resued with some modifications
//