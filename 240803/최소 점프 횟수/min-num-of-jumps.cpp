#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int shortest{-1};
vector<int> vct;

void jumping(vector<int>::const_iterator cur,int count){
    if(cur==vct.end()-1){
        shortest=(shortest==-1)?count:min(shortest,count);
        return;
    }
    
    for(int i=1;i<=*cur;i++){
        if((cur+i)>=vct.end()) break;
        jumping(cur+i,count+1);
    }
}


int main() {
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        vct.push_back(tmp);
    }

    jumping(vct.begin(),0);

    cout<<shortest;

    return 0;
}