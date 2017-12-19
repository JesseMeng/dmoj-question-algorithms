//this code, from showing the number of ways of distributing the pie,
// permits us to calculate the number of ways of dividing n to k integers
// where each integer is greater or qual to 1 and the k integers are weakly
// increasing
//we store these results so that our solution can be calculated efficiently
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<vector<vector<int>>> store;

int ways(int pieces, int people, int min){
    int sum = 0;
    if(pieces == people) store[pieces-1][people-1][min-1] = 1;
    if(people == 1) store[pieces-1][people-1][min-1] = 1;
    int cap = pieces/people;
    if(store.at(pieces-1).at(people-1).at(min-1) == 0){
        for(int i = min; i <= cap; ++i){
        sum+=ways(pieces-i, people-1, i);
        }
        store[pieces-1][people-1][min-1] = sum;
    }
    return store.at(pieces-1).at(people-1).at(min-1);
}


int main(){    
    int pieces, people;
    cin >> pieces >> people;
    store = vector<vector<vector<int>>>(pieces, vector<vector<int>>(people, vector<int>(pieces, 0)));
    int answer = ways(pieces, people, 1);
    cout << answer;
    return 0;
}