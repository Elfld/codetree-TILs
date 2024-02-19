#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, result{ 0 };
int ladder[16][15];

bool *ladderIncluded;
int currentLadderCount{ 0 };
int smallestLadderCount;

vector<pair<int, int>> locations;

int ladder_go() {
	int sum{ 0 };
	for (int i = 1; i <= n; i++) {
		int x = i;
		int y = 1;
		while (y <= m) {
			switch (ladder[y][x]) {
			case 1:
				x++;
				y++;
				break;
			case -1:
				x--;
				y++;
				break;
			case 0:
				y++;
				break;
			}
		}
		sum += i*pow(10, n - x); // (3|4|1|2 =>3412)
	}
	return sum;
}

void task(int cnt) {
	
	if (cnt == m) {
		int k = ladder_go();
		if (k == result) {
			currentLadderCount = 0;
			for (int i = 0; i < m; i++) {
				currentLadderCount +=ladderIncluded[i];
			}
			if (currentLadderCount < smallestLadderCount) {
				smallestLadderCount = currentLadderCount;
			}
		}
		return;
	}

	{
		ladderIncluded[cnt] = 1;
		ladder[locations[cnt].first][locations[cnt].second] = 1;
		ladder[locations[cnt].first][locations[cnt].second+1] = -1;
		currentLadderCount++;
	}
	
	task(cnt + 1);
	
	{
		ladderIncluded[cnt] = 0;
		ladder[locations[cnt].first][locations[cnt].second] = 0;
		ladder[locations[cnt].first][locations[cnt].second + 1] = 0;
	}

	task(cnt + 1);
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m;i++) {
		for (int k = 0; k < n; k++) {
			ladder[i][k] = 0;
		}
	}

	ladderIncluded = new bool[m] {1, };
	smallestLadderCount = m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		ladder[y][x] = 1;
		ladder[y][x + 1] = -1;
		locations.push_back({y, x});
	}

	result = ladder_go(); 

	currentLadderCount = 0;
	task(0);

	cout << smallestLadderCount;

}