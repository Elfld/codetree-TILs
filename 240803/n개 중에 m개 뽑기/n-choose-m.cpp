#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> line;
vector<int> vec_data;

void rec(int idx){
    if(line.size()==M){
        for(const auto& elem : line) cout<<elem<<" ";
        cout<<'\n';
        return;
    }

    for(int i=idx;i<N;i++){
        line.push_back(vec_data[i]);
        rec(i+1);
        line.pop_back();
    }
}

int main() {
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        vec_data.push_back(i);
    }
    rec(0);

    return 0;
}