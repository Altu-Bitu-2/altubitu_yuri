#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) { 
	if (parent[node] < 0) { //음수일때
		return node; //node을 return
	}
	return parent[node] = findParent(parent[node]); //루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
	int xp = findParent(x); //find연산
	int yp = findParent(y); //find연산

	if (xp == yp) { //같을때
		return false;
	}
	if (parent[xp] < parent[yp]) { //새로운 루트 xp
		parent[xp] += parent[yp]; //yp정점을 xp에 연결
		parent[yp] = xp; //결합
	}
	else { //새로운 루트 yp
		parent[yp] += parent[xp]; //xp정점을 yp에 연결
		parent[xp] = yp; //결합
	}
	return true;
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() { //main함수
	int n, m, x, y; //정수형 변수

	//입력
	cin >> n >> m; //점의 개수와 진행된 차례의 수 입력
	parent.assign(n, -1); //고유 번호 부여
	for (int i = 0; i < m; i++) { //반복
		cin >> x >> y; //해당 플레이어가 선택한 두 점의 번호 입력

		//연산 & 출력
		if (!unionInput(x, y)) { //사이클이 생성됨
			cout << i + 1; //m 번째 차례까지 게임을 진행한 상황에서 이미 게임이 종료되었다면 사이클이 처음으로 만들어진 차례의 번호를 양의 정수로 출력
			return 0;
		}
	}
	cout << 0; //m 번의 차례를 모두 처리한 이후에도 종료되지 않았다면 0을 출력
	return 0;
}