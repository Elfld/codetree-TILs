#include <iostream>
#include <cmath>
using namespace std;

int N, M, C;
int **room;
int max_value{0};

int calculate_max(int row, int startCol){
    int tmp_max=0;
    for(int i=0;i<(1<<M);i++){
        int weight=0;
        int value=0;
        for(int j=0;j<M;j++){
            if(i&(1<<j)){
                if(weight+room[row][startCol + j]<=C){
                weight += room[row][startCol + j];
                value += room[row][startCol + j]*room[row][startCol + j];
                }
                else{
                    value=0;
                    break;
                }
            }
        }

        if(value>tmp_max) tmp_max=value;
    }
    return tmp_max;
}

int robberies()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<=N-M;j++){
            int firstRobber=calculate_max(i,j);

            for(int k=i;k<N;k++){
                for(int p=(k==i?j+M:0);p<=N-M;p++){
                    int secondRobber=calculate_max(k,p);
                    
                    max_value=max(max_value,firstRobber+secondRobber);
                }
            }
        }
    }

    return 0;
}

int main()
{
    cin >> N >> M >> C;

    room = new int *[N];
    for (int i = 0; i < N; i++)
    {
        room[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> room[i][j];
        }
    }

    robberies();

    cout<<max_value;

     for (int i = 0; i < N; i++)
    {
        delete[] room[i];
    }
    delete[] room;

    return 0;
}