#include <iostream>
#include <vector>

using namespace std;

int n,m,k,highScore{0};

int *dist;
vector<int> moves;

int counts(){
    int *panel=new int[k];
    for(int i=0;i<k;i++){
        panel[i]=1;
    }
    
    for(int i=0;i<n;i++){
        panel[moves.at(i)]+=dist[i];
    }
    int count{0};
    for(int i=0;i<k;i++){
        if(panel[i]>=m) count++;
    }
    delete[] panel;
    return count;
}

void play(int num){
    if(num==n){
        int score=counts();
        if(score>highScore){highScore=score;}
        return;
    }

    for(int i=0;i<k;i++){
        moves.push_back(i);
        play(num+1);
        moves.pop_back();
    }
}

int main(){
    cin>>n>>m>>k;

    dist=new int[n];
    for(int i=0;i<n;i++){
        cin>>dist[i];
    }

    play(0);


    cout<<highScore;

    delete[] dist;
    return 0;
}