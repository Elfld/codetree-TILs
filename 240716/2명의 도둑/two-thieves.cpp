#include <iostream>
#include <cmath>
using namespace std;

int N, M, C;
int **room;
int max_value{0};

int robberies()
{
    int weight{0};
    int first_value{0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j + M > N)
                break;

            for (int k = 0; k < M; k++)
            {
                if (weight+room[i][j + k] <= C)
                {
                    weight += room[i][j + k];
                    first_value += pow(room[i][j + k], 2);
                }
                else
                    break;
            }
            weight=0;
            int l = j + M;
            int p = i;
            int second_value{0};
            while (p < N)
            {
                if (l + M > N){
                    if(p==N-1){break;}
                    l=0;
                    p++;
                }

                for(int k=0;k<M;k++){
                    if(room[p][l+k] + weight <= C){
                        weight+=room[p][l+k];
                        second_value+=pow(room[p][l+k],2);
                    }
                    else break;
                }
                
                if(first_value+second_value>max_value) {
                    max_value=first_value+second_value;
                }
                weight=0;
                second_value=0;
                l++;
            }
            first_value=0;
        }
    }

    return max_value;
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

    cout<<robberies();

     for (int i = 0; i < N; i++)
    {
        delete[] room[i];
    }
    delete[] room;

    return 0;
}