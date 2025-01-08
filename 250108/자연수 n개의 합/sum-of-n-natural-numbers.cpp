#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long s,n;
    cin>>s;
    long long left=1,right=s;
    long long maxi{0};
    while(left<=right){
        long long mid = (left+right)/2;
        long long cs = (mid+1)*mid/2.0;
        
        if(cs > s){
            right = mid-1;
        }
        else if (cs == s){
            maxi = mid;
            break;
        }
        else {
            maxi=max(maxi,mid);
            left = mid+1;
        }
        
    }
    cout<<right;
    return 0;
}