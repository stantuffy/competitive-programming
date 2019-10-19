/**
Given a number n, find all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits.
For more details, take a look @ 
https://www.geeksforgeeks.org/find-all-even-length-binary-sequences-with-same-sum-of-first-and-second-half-bits/
**/

#include <iostream>

using namespace std;

/**
n -> such that 2*n is the length of binary sequences of our interest
l -> string representation of the first(ie. most significative) n binary digits
r -> string representation of the last n binary digits
lsum -> base-10 sum of l's binary digits
rsum -> base-10 sum of r's binary digits
**/
void _solution(int n, int lsum, int rsum, string l, string r) {
  if(n <= 0) {
    if(lsum == rsum)
      cout << l << r << " ";
    return;
  }

  // First, last bit = 0
  _solution(n - 1, lsum, rsum, l + '0', r + '0');

  // First, las bit = 1
  _solution(n - 1, lsum + 1, rsum + 1, l + '1', r + '1');

  // First bit = 1, last bit = 0
  _solution(n - 1, lsum + 1, rsum, l + '1', r + '0');

  // First bit = 0, last bit = 1
  _solution(n - 1, lsum, rsum + 1, l + '0', r + '1');
}

void solution(int n) {
  _solution(n, 0, 0, "", "");
}

int main() {
  solution(3);
}
