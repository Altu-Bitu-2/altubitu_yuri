#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>map[11][11];			//각 좌표별 심어진 나무를 벡터로 저장할 예정
int a[11][11] = { 0, };			//매년 더해질 양분 ( 입력으로 값 받음)
int ground[11][11] = { 0, };		//땅의 현재 남은 양분을 저장할 배열
struct tree { int x, y, age; };		//죽은 나무벡터를 위한 구조체
int n, m, k;				//땅 크기, 나무개수, k년
vector<tree>dead;			//죽은 나무 벡터

int dx[8] = { -1,-1,-1,0,0,+1,+1,+1 };
int dy[8] = { -1,0,+1,-1,+1,-1,0,+1 };

void input();
void spring();
void summer();
void fall();
void winter();

void input() {
	cin >> n >> m >> k;
	//맨 처음 땅 양분은 모두 5
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			ground[r][c] = 5;
		}
	}
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			cin >> a[r][c];
		}
	}
	//m개 나무 입력
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x][y].push_back(z);//z는 age
	}
}

void spring() {
	//나이어린순 나무 정렬
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			sort(map[r][c].begin(), map[r][c].end());
		}
	}
	//각 칸별로 양분 먹는 나무와 죽는 나무 확인
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			for (int i = 0; i < map[r][c].size(); i++) {
				if (ground[r][c] >= map[r][c][i]) {//양분먹기가능
					ground[r][c] = ground[r][c] - map[r][c][i];//양분먹고
					map[r][c][i]++;//나이 1증가
				}
				else {//양분 못먹음
					dead.push_back({ r,c,map[r][c][i] });
					map[r][c].erase(map[r][c].begin() + i);//죽음
					i--;//vector.erase에 성질에 따라 i인덱스 줄여야 함
				}
			}
		}
	}
}

void summer() {
	for (int i = dead.size() - 1; i >= 0; i--) {
		int r = dead[i].x;
		int c = dead[i].y;
		ground[r][c] = ground[r][c] + dead[i].age / 2;
	}
	dead.clear(); dead.resize(0);//매 해 죽는 나무 업데이트를 위해
}

void fall() {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			for (int i = 0; i < map[r][c].size(); i++) {
				if (map[r][c][i] % 5 == 0 && map[r][c][i] >= 5) {
					for (int j = 0; j < 8; j++) {
						int nx = r + dx[j];
						int ny = c + dy[j];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
							map[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			ground[r][c] = ground[r][c] + a[r][c];
		}
	}
}

int main() {
	input();
	while (k > 0) {
		k--;
		spring();
		summer();
		fall();
		winter();
	}
	int answer = 0;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			answer = answer + map[r][c].size();
		}
	}
	cout << answer;
	return 0;
}