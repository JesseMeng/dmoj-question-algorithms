// converts decimal to binary
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;

int twospow(int m){
	int result = 1;
	for(int i = 0; i<m; ++i) result*=2;
	return result;
}
int main(){  
    int n;
    cin >> n;
    vector<long int> v;
    for(int i = 0; i < n; ++i){
    	int z;
        cin >> z;
        v.emplace_back(z);
    }
    for(auto a : v){
       int blocks = ceil(ceil(log(a+1)/log(2))/4.0);
       int actualNum = ceil(log(a+1)/log(2));
       if(blocks == 0) blocks++;
       vector<int> binary;
       for(int i =0; i < blocks*4-actualNum; ++i){
             binary.emplace_back(0);
       }
       for(int i = actualNum; i>=1; --i){
            if(a >=twospow(i-1)){
            	 a-=twospow(i-1);
                 binary.emplace_back(1);
            }else{
                binary.emplace_back(0);
            } 
       }
       int i = 0;
       for(auto b : binary){
       	cout << b;
       	++i;
       	if(i%4 == 0) cout << " ";
       }
       cout << endl;
    }
    return 0;
}