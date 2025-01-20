#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
vector<bool> visited;
void rec(int k){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<v[i]<<' ';
        }
        cout<<"\n";
        return;
    }

    for(int i=n-1;i>=0;i--){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(i+1);
            rec(k+1);
            v.pop_back();
            visited[i]=false;
        }
    }
}

int main() {
    cin >> n;
    // Write your code here!
    visited.resize(n,false);
    rec(0);
    return 0;
}
