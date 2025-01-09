#include <iostream>
#include <cmath>
using namespace std;

long long howmoo(int k){
    long long moo3 = k/3;
    long long moo5 = k/5;
    long long moo15 = k/15;

    return moo3+moo5-moo15;
}

int main() {
    long long N;
    cin>>N;

    long long left = 1, right = min(1LL<<30,3LL*N);

    while(left <= right){
        long long mid = (left+right)/2;
        long long res = mid-howmoo(mid);
        if(res < N){
            left = mid + 1;
        }
        else if (res == N){
            if(mid%3==0||mid%5==0){
                right = mid -1;
            }
            else {
                cout << mid;
                return 0;
            }
        } 
        else {
            right = mid-1;
        }
    }


    return 0;
}