#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, shortest(INT32_MAX);
vector<pair<int,int>> coor;
vector<pair<int,int>> pickedCoor;

void checkDist(){
    int longest=0;
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            int distX=pow((pickedCoor[i].first-pickedCoor[j].first),2);
            int distY=pow((pickedCoor[i].second-pickedCoor[j].second),2);
            longest=max(longest,distX+distY);
        }
    }
    shortest=min(shortest,longest);
}

void pickDist(int tmp){
    if(pickedCoor.size()==m){
        checkDist();
        return;
    }

    for(int i=tmp;i<n;i++){
        pickedCoor.push_back(coor[i]);
        pickDist(i+1);
        pickedCoor.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    coor.assign(n,make_pair(0,0));
    for (int i = 0; i < n; i++)
    {
        cin>>coor[i].first>>coor[i].second;
    }
    pickDist(0);
    cout<<shortest;

    return 0;
}