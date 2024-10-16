#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> p(n,vector<int>(m,0));
    vector<vector<long long>> tc(n,vector<long long>(m,0));

    int a,b,c,d;
    for(int i=0;i<k;i++){
        cin>>a>>b>>c>>d;
        switch(a-c){
            case 1:
                p[c][d]|=2;
                break;
            case -1:
                p[a][b]|=2;
                break;
        }
        switch(b-d){
            case 1:
                p[c][d]|=1;
                break;
            case -1:
                p[a][b]|=1;
                break;
        }
    }
    for(int i=1;i<m;i++){
        if(p[0][i]&1) break;
        tc[0][i]=1;
    }

    for(int i=1;i<n;i++){
        if(p[i][0]&2) break;
        tc[i][0]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            tc[i][j]=tc[i-1][j]+tc[i][j-1];
        }
    }

    cout<<tc[n-1][m-1];

    return 0;
}