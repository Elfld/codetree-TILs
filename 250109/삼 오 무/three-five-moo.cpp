#include <iostream>
#include <cmath>
using namespace std;

int howmoo(int k){
    int moo3 = k/3;
    int moo5 = k/5;
    int moo15 = k/15;

    return moo3+moo5-moo15;
}

int main() {
    long long N;
    cin>>N;

    int left = 1, right = min(1LL<<30,3LL*N);

    while(left <= right){
        int mid = (left+right)/2;
        int res = mid-howmoo(mid);
        if(res < N){
            left = mid + 1;
        }
        else if (res == N){
            while(mid/3==0||mid/5==0){
                mid--;
            }
            cout << mid;
            return 0;
        } 
        else {
            right = mid-1;
        }
    }


    return 0;
}