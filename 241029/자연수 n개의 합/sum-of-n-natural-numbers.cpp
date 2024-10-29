#include <iostream>
using namespace std;

int main() {
    long long s;
    cin>>s;

    long long left=1;
    long long right=s;
    while(left<=right){
        long long mid = (left + right)/2;
        if((mid*mid+1)/2 < s) left = mid+1;
        else right = mid - 1;
    }
    cout<<right;
    return 0;
}