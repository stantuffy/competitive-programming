/**
Given an integer k, print all binary sequences of size k, without consecutive 1s. 

For more info (eg. idea behind the algorithm) take a look @
https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/
**/

#include <iostream>

using namespace std;

void solution(int k, string seq) {
  if(k == 0) {
    cout << seq << " ";
    return;
  }
  
  if(!seq.length() || (seq.length() && seq[seq.length() - 1] == '0'))
    solution(k - 1, seq + '1');
  
  solution(k - 1, seq + '0');
}

int main() {
  solution(4, "");
  cout << endl;
}
