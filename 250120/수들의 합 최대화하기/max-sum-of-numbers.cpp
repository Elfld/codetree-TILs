#include <bits/stdc++.h>

using namespace std;

int n, maxi{0};
int grid[10][10];
vector<bool> vt;

void qq(int k, int prev){
    if(k==n){
        maxi=max(maxi,prev);
        return;
    }
    for(int i=0;i<n;i++){
        if(!vt[i]){
            vt[i]=true;
            prev+=grid[k][i];
            qq(k+1,prev);
            prev-=grid[k][i];
            vt[i]=false;
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Write your code here!

    vt.resize(n,false);
    qq(0,0);
    cout<<maxi;
    return 0;
}
