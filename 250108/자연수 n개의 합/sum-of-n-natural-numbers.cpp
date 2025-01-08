#include <iostream>
using namespace std;

int main() {
    long long s,n;
    cin>>s;
    long long left=0,right=s;
    while(left<=right){
        long long mid = (left+right)/2;
        long long cs = (mid+1)*mid/2;

        if(cs >= s){
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    cout<<right;
    return 0;
}