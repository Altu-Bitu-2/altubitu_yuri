#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //친구 관계가 모두 다른 사용자로 들어왔을 때의 정점 최댓값

vector<int> parent(MAX + 1, -1);
map<string, int> people;

//Find 연산
int findParent(int node) {
	if (parent[node] < 0) { //음수일때
		return node; //node을 return
	}
	return parent[node] = findParent(parent[node]); //루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
	int xp = findParent(x); //find 연산
	int yp = findParent(y); //find 연산

	if (xp == yp) { //같을때
		return;
	}
	if (parent[xp] < parent[yp]) { //새로운 루트 xp
		parent[xp] += parent[yp]; //yp정점을 xp에 연결
		parent[yp] = xp; //결합
	}
	else { //새로운 루트 yp
		parent[yp] += parent[xp]; //xp정점을 yp에 연결
		parent[xp] = yp; //결합
	}
}

/**
 * [친구 네트워크]
 *
 * 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 * 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근
 *
 * !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
 */

int main() { //main함수
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f; //정수형 변수
	string a, b; //문자열 변수

	//입력
	cin >> t; //테스트케이스의 개수 입력
	while (t--) { //반복
		int idx = 1; //정점과 매핑할 수
		parent.assign(MAX + 1, -1);

		cin >> f; //친구 관계의 수 입력
		while (f--) { //반복
			cin >> a >> b; //사용자의 아이디 입력
			if (!people[a]) { //배열 a에 없으면
				people[a] = idx++; //추가
			}
			if (!people[b]) { //배열 b에 없으면
				people[b] = idx++; //추가
			}

			//연산
			int x = people[a], y = people[b]; //각 배열 저장
			unionInput(x, y); //유니온 연산

			//출력
			cout << -parent[findParent(x)] << '\n'; //친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 출력
		}
	}
	return 0;
}