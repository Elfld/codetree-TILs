#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long s;
    cin>>s;
    long long n = (-1+sqrt(1+8*s))/2;
    cout<<n;
    
    return 0;
}

/*
(n+1)*n/2 =s
n²+n = 2s
(n+1/2)² = -1/4 + 2s = (-1+8s)/4
n+1/2 = sqrt(-1+8s)/2


*/