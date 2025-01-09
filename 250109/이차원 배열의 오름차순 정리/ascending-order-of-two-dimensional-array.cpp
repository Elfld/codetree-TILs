#include <iostream>
using namespace std;

long long n,k;
int main() {
    cin>>n>>k;

    long long lw = 1LL;
    long long hg = n*n;
    long long ans = n*n;
    while(lw<=hg){
        long long mid = (lw+hg)/2;

        long long ct=0;
        for(int i=1;i<=n;i++){
            ct+=min(n,mid/i);
        }
        if(ct>=k){
            hg = mid-1;
            ans = min(ans,mid);
        }
        else {
            lw = mid +1;
        }
    }
    cout<<ans;
    return 0;
}
