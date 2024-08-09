#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;

int n, shortest{INT32_MAX};
pair<int,int> src;
pair<int,int> dst;
vector<pair<int,pair<int,int>>> coordinates;
vector<pair<int,pair<int,int>>> picked_coordinates;

void combination(int count){
    if(picked_coordinates.size()>=3&&picked_coordinates.size()<=9){
        int dist=abs(picked_coordinates[0].second.first-src.first)+
        abs(picked_coordinates[0].second.second-src.second);
        for(int i=1;i<picked_coordinates.size();i++){
            dist+=abs(picked_coordinates[i].second.first-picked_coordinates[i+1].second.first)+
            abs(picked_coordinates[i].second.second-picked_coordinates[i+1].second.second);
        }
        dist+=abs(picked_coordinates[picked_coordinates.size()-1].second.first-dst.first)+
        abs(picked_coordinates[picked_coordinates.size()-1].second.second-dst.second);
        shortest=min(shortest,dist);
        return;
    }

    for(int i=count;i<coordinates.size();i++){
        picked_coordinates.push_back(coordinates[i]);
        combination(i+1);
        picked_coordinates.pop_back();
    }
};

bool compare(pair<int,pair<int,int>> a1,pair<int,pair<int,int>>a2){
    return a1.first<a2.first;
}

int main()
{
    cin >> n;
    string input;
    for (int i = 0; i < n; i++)
    {
        cin>>input;
        for (int j = 0; j < n; j++)
        {   
            switch (input[j])
            {
            case 'S':
                src.first=i;
                src.second=j;
                break;
            case 'E':
                dst.first=i;
                dst.second=j;
                break;
            case '.':
                break;
            default:
                coordinates.push_back(make_pair(input[j]-'0',make_pair(i,j)));
                break;
            }
        }
    }
    sort(coordinates.begin(),coordinates.end());

    combination(0);

    cout<<((shortest==INT32_MAX)?(-1):shortest);

    return 0;
}