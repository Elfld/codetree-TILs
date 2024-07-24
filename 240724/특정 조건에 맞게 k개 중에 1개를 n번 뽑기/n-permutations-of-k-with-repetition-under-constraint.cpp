#include <iostream>
#include <vector>
using namespace std;

int K,N;
vector<int> answer;

bool three_in_row(){
    if(answer.empty())return false;
    int prev=answer.front();
    int isThree=1;
    for(int i=1;i<answer.size();i++){
        if(answer.at(i)==prev) isThree++;
        else {
            isThree=1;
            prev=answer.at(i);
        }
        if (isThree==3) return true;
    }
    return false;
}


void print_answer(int num){
    if(num==N+1){
        for(int i=0;i<N;i++){
            cout<<answer.at(i)<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=1;i<=K;i++){
        answer.push_back(i);
        if(three_in_row()){
            answer.pop_back();
            continue;
        }
        print_answer(num+1);
        answer.pop_back();
    }
}


int main() {
    cin>>K>>N;

    print_answer(1);

    return 0;
}