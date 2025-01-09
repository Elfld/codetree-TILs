#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n,x1,x2;
    cin>>n;
    map<int,int> ln;

    for(int i=0;i<n;i++){
        cin>>x1>>x2;
        ln[x1]++;
        ln[x2]--;
    }

    int lns{0};
    int sec{0};
    for(auto i : ln){
        lns+=i.second;
        if(lns == 0){
            sec++;
        }
    }
    cout<<sec;
    return 0;
}