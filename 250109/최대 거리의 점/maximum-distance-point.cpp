#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int arr[200000];

bool tt(int dist){
    int obj{1};
    int lst{0};
    for(int i=1;i<n;i++){
        if(arr[i]-arr[lst]>=dist){
            obj++;
            lst = i;
        }
    }
    return obj>=m;
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    int left = 0;
    int right = 1'000'000'000;
    int mx=0;

    while(left<=right){
        int mid = (left+right)/2;
        if(tt(mid)){
            mx=max(mx,mid);
            left = mid+1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << mx;

    return 0;
}