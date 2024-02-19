#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, result{ 0 };
int ladder[17][12]{ 0, };

bool *ladderIncluded;
int currentLadderCount{ 0 };
int smallestLadderCount;

vector<pair<int, int>> locations;

int ladder_go() {
	int sum{ 0 };
	for (int i = 1; i <= n; i++) {
		int x = i;
		int y = 1;
		while (y <= 16) {
			switch (ladder[y][x]) {
			case 1:
				x++;
				break;
			case -1:
				x--;
				break;
			}
				y++;
		}
		sum += i * pow(10, x);
	}
	return sum;
}

void update() {
	for (int i = 0; i < m; i++) {
		int x = locations[i].first;
		int y = locations[i].second;
		if (ladderIncluded[i]) {
			ladder[y][x] = 1;
			ladder[y][x+1] = -1;
		}
		else {
			ladder[y][x] = 0;
			ladder[y][x+1] = 0;
		}
	}
}

void task(int cnt) {
	
	if (cnt == m) {
		update();
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

	ladderIncluded[cnt] = 1;
	task(cnt + 1);
	
	ladderIncluded[cnt] = 0;
	task(cnt + 1);
} 



int main() {

	cin >> n >> m;
	for (int i = 0; i < 16;i++) {
		for (int k = 0; k < n; k++) {
			ladder[i][k] = 0;
		}
	}

	ladderIncluded = new bool[m] {1, };
	smallestLadderCount = m;
	currentLadderCount = m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		ladder[y][x] = 1;
		ladder[y][x + 1] = -1;
		locations.push_back({x, y});
	}


	result = ladder_go(); 
	task(0);

	cout << smallestLadderCount;

}