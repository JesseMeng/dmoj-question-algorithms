//the following code allows us to add 2 numbers that are up to 100000 digits in decimal

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;
class BigNumPair{
  public:   
    vector<int>num1;
    vector<int>num2;
    bool firstNeg = false;
    bool secondNeg = false;
    unsigned int store = 0;
    void reset(){
      num1.clear();
      num2.clear();
      firstNeg= false;
      secondNeg = false;
      store = 0;
    }
    bool onegreatertwo(){
       if (num1.size() < num2.size()) return false;
       if (num1.size() > num2.size()) return true;
       for(unsigned int i = 0; i < num1.size(); ++i){
         if(num1[i] > num2[i]) return true;
         if(num1[i] < num2[i]) return false;
       }
     return false;
    }
    void diff(){
       vector<int> sum;
       bool onegtwo= false;
       if(onegreatertwo()){
            onegtwo  = true;
            bool take = 0;
            for(int i = num2.size()-1; i >=0; --i){
              int b = num2[i];
              int a = num1[num1.size()-(num2.size()-i)];
              if(take == 1 && a ==0){
                 take = 1;
                 sum.emplace_back(9-b);
              }else{
              if(a-take >= b){
                 sum.emplace_back(a-take-b);
                 take = 0;
              }else{
                sum.emplace_back(a-take+10-b);
                take = 1;
              }
              }
            }
            for(int i = num1.size()-num2.size()-1; i >=0; --i){
            if(num1[i]-take < 0){
               sum.emplace_back(9);
               take = 1;
            }else{
               sum.emplace_back(num1[i]-take);
               take = 0;
            }
         }
       }else {
            bool take = 0;
            for(int i = num1.size()-1; i >=0; --i){
              int b = num1[i];
              int a = num2[num2.size()-(num1.size()-i)];
              if(take == 1 && a ==0){
                 take = 1;
                 sum.emplace_back(9-b);
              }else{
              if(a-take >= b){
                 sum.emplace_back(a-take-b);
                 take = 0;
              }else{
                sum.emplace_back(a-take+10-b);
                take = 1;
              }
             }
            }
            for(int i = num2.size()-num1.size()-1; i >=0; --i){
            if(num2[i]-take < 0){
               sum.emplace_back(9);
               take = 1;
            }else{
               sum.emplace_back(num2[i]-take);
               take = 0;
            }
         }    
       }      
       bool remove = true;
        unsigned int myI = sum.size()-1;
        while(remove && myI < sum.size()){
 
             if(sum[myI] == 0){
                sum.erase(sum.begin()+myI);  
                myI = sum.size()-1;
             }else{
              remove = false;
             }
        }      

        if(sum.size() == 0){
             cout << 0;
        }else{
          if(firstNeg){
            if(onegtwo) cout << '-';
          }else{
            if(!onegtwo) cout << '-';
          }       
          for(int i = sum.size()-1; i>=0; --i){
            cout << sum[i];
        }
        }
        cout << endl;

    }
    void sum(){
      vector<int> sum;
        if(num1.size() >= num2.size()){
          bool feed = 0;
           for(int i = num2.size()-1; i >=0; --i){
              int a = num2[i];
              int b = num1[num1.size()-(num2.size()-i)];
              if(a+b+feed < 10){
                  sum.emplace_back(a+b+feed);
                  feed = 0;
              }else{
                sum.emplace_back(a+b+feed-10);
                feed = 1;
              }
           }
         for(int i = num1.size()-num2.size()-1; i >=0; --i){
            if(num1[i]+feed < 10){
               sum.emplace_back(num1[i]+feed);
               feed = 0;
            }else{
               sum.emplace_back(num1[i]+feed-10);
               feed = 1;
            }
         }
         if(feed == 1) {
           sum.emplace_back(1);
         }
        }else{
          bool feed = 0;
           for(int i = num1.size()-1; i >=0; --i){
              int a = num1[i];
              int b = num2[num2.size()-(num1.size()-i)];
              if(a+b+feed < 10){
                  sum.emplace_back(a+b+feed);
                  feed = 0;
              }else{
                sum.emplace_back(a+b+feed-10);
                feed = 1;
              }
           }
         for(int i = num2.size()-num1.size()-1; i >=0; --i){
            if(num2[i]+feed < 10){
               sum.emplace_back(num2[i]+feed);
               feed = 0;
            }else{
               sum.emplace_back((num2[i]+feed-10));
               feed = 1;
               
            }
        }
            if(feed == 1) {
           sum.emplace_back(1);
           }  
        }
        bool remove = true;
        unsigned int myI = sum.size()-1;
        while(remove && myI < sum.size()){
             if(sum[myI] == 0){
                sum.erase(sum.begin()+myI);  
             }else{
              remove = false;
             }
        }      
        if(sum.size() == 0){
             cout << 0;
        }else{
          if(firstNeg){
              cout << '-';
          }
          for(int i = sum.size()-1; i>=0; --i){
            cout << sum[i];
        }
        }
        cout << endl;
    }
};

istream& operator>>(istream& in, BigNumPair &j){
  string line;
  getline(in, line);
  if(line[0] == '-') {
    j.firstNeg = true;
  }
  bool k = true;
  for(unsigned int i=0; i < line.length(); ++i){   
    if(i == 0 && j.firstNeg) continue;
    if(line[i] == ' ') {
      k =false;
      if(line[i+1] == '-'){
            j.secondNeg = true;
            j.store = i+1;
      }
     continue;
   }
   if(j.secondNeg && i == j.store) continue;
      if(k){
         j.num1.emplace_back(line[i]-'0');
      }else{
         j.num2.emplace_back(line[i]-'0');
      }
  }
      return in;
}
int main(){  
   int n;
   string dum;
   cin >> n;
   getline(cin, dum);
   vector<int>num1;
   vector<int>num2;
   BigNumPair a;
   a.num1 = num1;
   a.num2 = num2;
   for(int i = 0; i< n;++i){
        cin >> a;
        if(a.firstNeg && a.secondNeg){
          a.sum();
        }else if(a.firstNeg){
             a.diff();
        }else if(a.secondNeg){
            a.diff();
        }else{
          a.sum();
        }
        a.reset();
    }
   return 0;
}