#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int from[10000], to[10000];
bool vt[1001];
int main() {
    cin >> n >> m;
    vector<vector<int>> nd(n+1);
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
        nd[from[i]].push_back(to[i]);
        nd[to[i]].push_back(from[i]);
    }

    // Write your code here!
    stack<int> s;
    s.push(1);
    int count{-1};
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vt[cur]) continue;
        vt[cur] = true;
        count++;
        for(int cn : nd[cur]){
            if(vt[cn])continue;
            s.push(cn);
        }
    }

    cout<<count;

    return 0;
}
