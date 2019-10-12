/**
This piece of code computes the length of Longest Increasing Subsequence
of a given array.

Space complexity: linear in the size of the array.
Time complexity: approx. n^2 using Dynamic Programming.

For further details, you can take a look @ https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
**/

#include <iostream>
#include <algorithm>
using namespace std;

int LIS(int arr[], int size) {
    int D[size];
    
    for(int i=0; i<size; i++)
        D[i] = 1;
    
    for(int i=1; i<size; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i])
                D[i] = max(D[i], 1 + D[j]);
        }
    }
    
    return *max_element(D, D+size);
}

int main() {
	int T, N;
	
	scanf("%d", &T);
	while(T--) {
	    scanf("%d", &N);
	    int seq[N];
	    
	    for(int i=0; i<N; i++) scanf("%d", &(seq[i]));
	    
	    printf("%d\n", LIS(seq, N));
	}
	
	return 0;
}
