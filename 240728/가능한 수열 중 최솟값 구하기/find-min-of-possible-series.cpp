#include <iostream>
#include <vector>
using namespace std;

int n;
bool printed {false};
vector<int> permutation;

bool duplicated(){
    for(int length=2;length<=(permutation.size()-1)/2;length++){
        for(int j=1;j<=permutation.size()-length*2;j++){
            int k=0;
            for(;k<length;k++){
                if(permutation.at(j+k)!=permutation.at(j+k+length)) break;
            }
            if (k==length) return true;
        }
    }
    return false;
}


void lining(int count){
    if(count==n){
        for(int i=1;i<permutation.size();i++){
            cout<<permutation.at(i);
        }
        printed=true;
        return;
    }

    for(int i=4;i<=6&&!printed;i++){
        if(permutation.back()==i) continue;
        permutation.push_back(i);
        if(duplicated()) {
            permutation.pop_back();
            continue;
        }
        lining(count+1);
        permutation.pop_back();
    }

}

int main() {
    cin>>n;
    
    permutation.push_back(0);
    
    lining(0);

    return 0;

}