#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int A[10][10];

vector<int> od;
vector<bool> vs;

int mins{INT_MAX};

void qq(int k){
    if(k==n-1){
        int total = A[0][od[0]];
        for(int i=0;i<n-2;i++){
            total+=A[od[i]][od[i+1]];
        }
        total+=A[od[n-2]][0];
        mins = min(mins,total);
        return;
    }

    for(int i=1;i<n;i++){
        if(!vs[i]){
            vs[i]=true;
            od.push_back(i);
            qq(k+1);
            od.pop_back();
            vs[i]=false;
        }
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Write your code here!
    vs.resize(n,false);

    qq(0);

    cout<<mins;
    return 0;
}
