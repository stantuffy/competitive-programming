#include <stdio.h>
#include <math.h>
#include <functional>

using namespace std;

int A[8]; // A[i] = column index corresponding to i-th row.
int n_sol_found;

bool validate(int row) {
    
    function<bool(int, int, int, int)> same_diagonal = [](int r1, int c1, int r2, int c2) {
        
        return abs(r1 - r2) == abs(c1 - c2);
    };
    
    for(int i=0; i<row; i++) {
        if(same_diagonal(row, A[row], i, A[i]) || row == i || A[row] == A[i])
            return false;
    }
    
    return true;
}

void print_sol() {
    for(int i=0; i<8; i++)
        printf("(%d , %d)  ", i, A[i]);
    
    printf("\n");
}

// r: number of queens placed in array A
void backtrack(int r) {
    // Discard current solution if two queens attack each other
    if(!validate(r - 1))
        return;
        
    // Total solution found, print result
    if(r == 8) {
        print_sol();
        n_sol_found ++;
        return;
    }
        
    // Explore the entire decision space(ie. for each row index [r], try all possible column indexes [i])
    for(int i=0; i<8; i++) {
        A[r] = i; // try to put queen at (r, i)
        backtrack(r + 1); // move one step forward
    }
}

int main()
{
    n_sol_found = 0;
    backtrack(0);
    printf("Number of found solutions: %d\n", n_sol_found);

    return 0;
}
