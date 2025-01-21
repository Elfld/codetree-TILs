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

bool ca(int a, int b){
    if(A[a][b]==0){
        return false;
    }
    return true;
}

void qq(int k){
    if(k==n-1){
        od.push_back(0);
        int ct{0};
        for(int i=0;i<od.size()-1;i++){
            int cur = A[od[i]][od[i+1]];
            if (cur==0) return;
            ct+=cur;
        }
        mins = min(mins,ct);
        od.pop_back();
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
    od.push_back(0);

    qq(0);

    cout<<mins;
    return 0;
}
