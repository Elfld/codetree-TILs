#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int grid[10][10];
bool vt[10];

int mx{0};

vector<int> crd;

void ff (int y, int prev){
    if(y==n){
        mx = max(mx,prev);
        return;
    }

    for(int i=0;i<n;i++){
        if(!vt[i]){
            vt[i]=true;
            int tmp = prev;
            prev = min(prev,grid[y][i]);
            ff(y+1,prev);
            vt[i] = false;
            prev = tmp;
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Write your code here!
    ff(0,INT_MAX);
    cout<<mx;
    return 0;
}
