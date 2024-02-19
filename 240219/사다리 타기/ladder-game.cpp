#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int humanNum, lineNum;

int ladder[17][12]{ 0, };
vector<pair<int, int>> lines;
bool* lineCkd;
int lineCount = 0;

int iniV;
int lowestNum;

int game() {
	int sum{ 0 };

	for (int i = 1; i <= humanNum; i++) {
		int x{ i };
		for(int y=1;y<=16;y++) {
			switch (ladder[y][x]) {
			case 1:
				x++;
				break;
			case -1:
				x--;
				break;
			}
		}
		sum += i * pow(10, humanNum - x);
	}
//	cout << sum << endl;
	return sum; 
}

void task(int cmd) {
	if (cmd == lineNum) {
		lineCount = 0;
		for (int i = 0; i < lineNum; i++) {
	//		cout<<"["<<lineCkd[i] << "]";
			lineCount+=lineCkd[i];
		}
	//	cout<<":"<<lineCount << ":" << endl;
		if (game() == iniV && lineCount<lowestNum) {
			lowestNum = lineCount;
		}
		return;
	}

	int y = lines[cmd].first;
	int x = lines[cmd].second;

	{
		lineCkd[cmd] = 1;
		ladder[y][x] = 1;
		ladder[y][x + 1] = -1;
	}
	task(cmd + 1);

	{
		lineCkd[cmd] = 0;
		ladder[y][x] = 0;
		ladder[y][x+1]=0;
	}
	task(cmd + 1);
}


int main() {
	
	cin >> humanNum >> lineNum;
	
	lineCkd = new bool[lineNum] {true, };

	for (int i = 0; i < lineNum; i++) {
		int x, y;
		cin >> x >> y;
		lines.push_back({ y,x });
		ladder[y][x] = 1;
		ladder[y][x+1] = -1;
	}

	iniV = game();
	lowestNum = lineNum;
	task(0);
	cout << lowestNum;

}