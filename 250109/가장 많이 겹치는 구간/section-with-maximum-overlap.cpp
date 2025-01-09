#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    int ln[200000];

int main() {
    int n,x1,x2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x1>>x2;
        ln[x1]++;
        ln[x2]--;
    }
    int lns=0;
    int ans=0;
    for(int i=1;i<=200000;i++){
        lns+=ln[i];
        ans=max(ans,lns);
    }
    cout<<ans;
    return 0;
}