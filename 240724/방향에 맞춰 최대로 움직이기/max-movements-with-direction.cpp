#include <iostream>

using namespace std;

int n;
int **cube;
int **direction;

int highestMoved{0};

int directionVectors[9][2] = {
        {},
        {-1,  0}, // 1: 위쪽
        {-1,  1}, // 2: 오른쪽 전방 대각선
        { 0,  1}, // 3: 오른쪽
        { 1,  1}, // 4: 오른쪽 후방 대각선
        { 1,  0}, // 5: 아래쪽
        { 1, -1}, // 6: 왼쪽 후방 대각선
        { 0, -1}, // 7: 왼쪽
        {-1, -1}  // 8: 왼쪽 전방 대각선
};
bool in_range(int x,int y){
    return (x>=0&&x<n)&&(y>=0&&y<n);
}
void game(int r,int c, int moved){
    int y=r;
    int x=c;
    while(in_range(x,y)){
        if(cube[y][x]>cube[r][c]){game(y,x,moved+1);}
        y+=directionVectors[direction[r][c]][0];
        x+=directionVectors[direction[r][c]][1];
    }
    if(moved>=highestMoved){highestMoved=moved;}
}


int main() {
    cin>>n;
    cube=new int*[n];
    for(int i=0;i<n;i++){
        cube[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cube[i][j];
        }
    }

    direction=new int*[n];
    for(int i=0;i<n;i++){
        direction[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>direction[i][j];
        }
    }

    int r,c;
    cin>>r>>c;

    game(r-1,c-1,0);

    cout<<highestMoved;

    return 0;
}