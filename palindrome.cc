//following code efficiently computes number of palindromes
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;
int main(){  
  int n;
  cin >> n;
  if(n == 1){
    cout << 9;
  }else if(n ==2){
    cout << 18;
  }else if(n == 3){
    cout << 108;
  }else if(n ==4){
    cout << 198;
  }else{
      vector<int> v;
      v.emplace_back(1);
      if(n%2 != 0) v.emplace_back(0);
      for(int i = 0; i < n/2-1; ++i){
        if(i > 20) break;
      v.emplace_back(9);
      }
      v.emplace_back(8);
      if(v.size() > 9){
         for(unsigned int i = v.size()-9; i< v.size(); ++i) cout << v[i];
      }else{
        for(auto i : v) cout << i;
      }
  }
  return 0;
}