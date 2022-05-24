#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
	if (node == erase_node) { //비교
		return 0; //0을 return
	}
	if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) { //비교
		return 1; //1을 return
	}
	int cnt = 0; //정수형 변수
	for (int i = 0; i < tree[node].size(); i++) {  //반복
		cnt += eraseLeafCnt(tree[node][i], erase_node); 
	}
	return cnt; //cnt을 return
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() { //main 함수
	int n, par, root, erase_node; //정수형 변수

	//입력
	cin >> n; //트리의 노드 개수 n 입력
	tree.assign(n, vector<int>(0));
	for (int i = 0; i < n; i++) { //n만큼 반복
		cin >> par; //각 노드의 부모 par 입력
		if (par == -1) { //만약 par이 -1이면 (부모가 없다면)
			root = i; //root를 i로 설정
			continue;
		}
		tree[par].push_back(i);
	}
	cin >> erase_node; //지울 노드의 번호 입력

	//연산 & 출력
	cout << eraseLeafCnt(root, erase_node); //리프 노드의 개수 출력
	return 0; //0을 return
}