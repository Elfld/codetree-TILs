#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, highest{0};
vector<int> ints, cur;
void letsXOR(int count)
{
    if (cur.size() == m)
    {
        int prev = cur[0];
        for (int i = 1; i < cur.size(); i++)
        {
            prev = (prev ^ cur[i]);
        }
        highest=max(highest,prev);
        return;
    }

    for(int i=count;i<n;i++){
        cur.push_back(ints[i]);
        letsXOR(i+1);
        cur.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        ints.push_back(k);
    }

    letsXOR(0);
    cout<<highest;
    return 0;
}