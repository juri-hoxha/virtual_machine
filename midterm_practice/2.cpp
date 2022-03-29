#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;


  int findx(vector<int> R, vector<int> M) {
  size_t n;
  n=R.size();
  int product;
  product=1;
  // calculate product of M[0]*M[1]...M[n-1]
  for (size_t j=0; j<n; j++){
    product*=M[j];
  }

  //Brute force test
  int x;
  bool a=1;
  for (x=1; x<product; x++){
    a = 1;
    for (size_t i=0; i<n; i++){
      if ((x%M[i])!=R[i]) {
        a = 0; // set boolean a to 0 if its not true
        break;
      }
    }
    if (a==1){
      return x;
      break;
    }
  }
  return -1;
}

int main(){

  vector<int> M = {10,5};
  vector<int> R = {0,4};
  int b;
  b=findx(R,M);
  cout << b << "\n";
}

