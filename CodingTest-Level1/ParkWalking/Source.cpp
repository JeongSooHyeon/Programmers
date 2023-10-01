#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
map<char, int> mapping = {
	{'E',0},{'W',1},{'S',2},{'N',3}
};

vector<int> solution(vector<string> park, vector<string> routes) {
	int cx, cy;
	for (int i = 0; i < park.size(); i++) {
		for (int j = 0; j < park[i].size(); j++) {
			if (park[i][j] == 'S') {
				tie(cx, cy) = { i,j };
				i = park.size();
				break;
			}
		}
	}

	for (int i = 0; i < routes.size(); i++) {
		int num = routes[i][2] - '0';
		int dir = mapping[routes[i][0]];

		int nx = cx, ny = cy;
		while (num--) {
			nx += dx[dir];
			ny += dy[dir];

			// 범위 검사
			if (!(nx >= 0 && nx < park.size()) || !(ny >= 0 && ny < park[0].size()))
				break;
			// 장애물 검사
			if (park[nx][ny] == 'X')
				break;
		}

		// 시작 지점 초기화
		if (num < 0) {
			cx = nx;
			cy = ny;
		}
	}

	return { cx ,cy };
}
