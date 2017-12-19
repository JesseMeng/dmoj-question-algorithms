//following is very useful code that, given a set of numbers,  //  //computes the two subsets the would yield the smallest differenc //in set total

#include<iostream>
#include<map>
#include<bitset>
#include<vector>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main(){  
   int N;
   cin >> N;
   vector<long int> v;
   long int Ai;
   for(int i = 1; i <=N ; ++i){
      cin >> Ai;
      v.emplace_back(Ai);
   }
   vector<pair<long int, long int>> m;
   for(int i = 1; i<=(pow(2, N)-1);++i){
    pair <long int, long int> p;
    p.first = i;
       long int total = 0;
       auto k = bitset<20>(i);
       for(int i = 0; i<N; ++i){
           if(k[i] == 1){
              total+=v[i];
           }  
       }
      p.second  = total;
      m.emplace_back(p);
    }
    sort(m.begin(), m.end(), sortbysec);
    long int mindiff = m[0].second;
    bitset<20> set1;
    bitset<20> set2;
   for(size_t i = 0; i < m.size()-1; ++i){
    bool dis = true;
        auto first = bitset<20>(m[i].first);
        auto second = bitset<20>(m[i+1].first);
         for(int l = 0; l < N-1; ++l){
             if ( first[l]==1 && first[l]==second[l]) {
                dis = false; break;
             }    
        }
        if(dis){
           if(abs(m[i].second-m[i+1].second) < mindiff){
                mindiff = abs(m[i].second-m[i+1].second);
                set1 = bitset<20>(m[i].first);
                set2 = bitset<20>(m[i+1].first);
            }
        }
        dis =true;
      }

   for(int i = 0; i < N; ++i){
       if(set1[i] == 1) cout <<i+1 <<" ";
   }
   cout << endl;
   for(int i = 0; i < N; ++i){
       if(set2[i] == 1) cout <<i+1 <<" ";
   }
   return 0;
}