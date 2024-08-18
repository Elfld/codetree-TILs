#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int n, total{0}, smallest{INT32_MAX};
vector<int> two, one;

void recur(int t)
{
    if (one.size() == n)
    {
        int tmpTotal{0};
        for (int i = 0; i < n; i++)
        {
            tmpTotal+=one[i];
        }
        int diff=abs(total-2*tmpTotal);
        if(diff<smallest){
            smallest=diff;
        }
        return;
    }

    for (int i = t; i < 2 * n; i++)
    {
        one.push_back(two[i]);
        recur(i + 1);
        one.pop_back();
    }
}

int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> tmp;
        total += tmp;
        two.push_back(tmp);
    }

    recur(0);

    cout<<smallest;

    return 0;
}