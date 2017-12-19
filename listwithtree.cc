//following code implements a list with a tree and can remove and // add elements efficiently to the list
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;
struct MyTree{
public:
  int num;
  MyTree *left;
  MyTree *right;
};
void add(MyTree& a, int n){
       if(n > a.num) {
        if(a.right == nullptr){
           a.right = new MyTree{n, nullptr, nullptr};
        }
        else add(*(a.right),n);
       }
       if(n < a.num) {
        if(a.left == nullptr){
           a.left = new MyTree{n, nullptr, nullptr};
        }
        else add(*(a.left),n);
       }
}
void inorderTraverse(const MyTree& a){
       if(a.left != nullptr) inorderTraverse(*(a.left));
       cout << a.num << endl;
       if(a.right != nullptr) inorderTraverse(*(a.right));
  }
int main(){  
   int n;
   cin >> n;
   int j;
   cin >> j;
   MyTree t{j, nullptr, nullptr};
   for(int i = 1; i < n; ++i){   
       cin >> j;
       add(t,j);
   }
   inorderTraverse(t);
   return 0;
}