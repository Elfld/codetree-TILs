#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n,m, total{0};
    cin>>n>>m;
    vector<int> ls;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ls.push_back(a);
        total+=a;
    }

    int left{1}, right{total}, mx{0};

    while(left<=right){
        int mid = (left+right)/2;

        int count = 0;
        for(int i=0;i<n;i++){
            count += ls[i]/mid;
        }

        if(count<m) {
            right = mid - 1;
        }
        else {
            left = mid+1;
            mx = max(mx, mid);
        }
    }

    cout<<mx;

    return 0;
}