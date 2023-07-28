#include <stdio.h>

int abs(int a)
{
    return (a < 0 ? -a : a);
}

int possible(int pos[], int kth_queen, int ind)
{
    for (int i = 0; i < kth_queen; i++)
    {
        // ith queen on pos[i]
        // kth queen on pos[ind]
        // checking possible attacks
        // queens on same column, that is y co-ordinate is same
        if (pos[i] == ind || abs(kth_queen - i) == abs(ind - pos[i]))
            return 0;
    }
    return 1;
}
int c = 0;
void display(int pos[], int n)
{
    c++;// to count no of possible ways
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (pos[i] == j)
                printf("%c ", 'Q');
            else
                printf("%c ", '.');
        }
        printf("\n");
    }
    printf("\n----------------\n");
}

void N_Queen(int pos[], int k, int n)
{
    for (int i = 0; i < n; i++){
        if (possible(pos, k, i)){
            pos[k] = i;
            if (k < n - 1)
                N_Queen(pos, k + 1, n);
            else
                display(pos, n);
            // a flag is required to stop invoking display multiple times
            // otherwise it will print every possible combination 
        }
    }
}

int main(){
    int n;
    printf("Size of Chessboard (N x N ?) :");
    scanf("%d", &n);
    int pos[n];
    printf("N-Queen on NxN chessboard\n");
    N_Queen(pos, 0, n);
    printf("\nTotal possible no of ways : %d\n", c);
    return 0;
}

// implement nqueen solution using 2 modules and ensure the display of all solution vs single solution 
// implement m-coloring problem using modules similar to n-queen modules and using modules in a way that all possible values for x[k] are also explored in module 2(as given in the book)
// compare and understand the working difference between these two approaches 
// implement hamiltonian cycle backtracking solution using both alternates as done in question 2 