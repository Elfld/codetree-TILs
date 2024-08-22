#include <iostream>
#include<vector>

using namespace std;

int n;
vector<int> permut;
bool* visited;

void recur(int idx){
    if (idx==n){
        for(int i=0;i<n;i++){
            cout<<permut[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<n;i++){
        if(visited[i]) continue;

        permut.push_back(i+1);
        visited[i]=true;

        recur(idx+1);

        permut.pop_back();
        visited[i]=false;
    }
}


int main() {    
    cin>>n;
    visited=new bool[n]{0,};

    recur(0);
    delete[] visited;
    return 0;
}