#include <iostream>

using namespace std;

struct node_info { //구조체
	int data; //정수형 변수
	node_info *left; //왼쪽 노드
	node_info *right; //오른쪽 노드
};

node_info *makeTree(node_info *node, int data) {
	if (node == NULL) { //이번 노드가 들어가게될 위치
		node = new node_info(); //동적 할당
		node->data = data; //노드의 데이터 할당
		node->left = node->right = NULL; //왼쪽, 오른쪽 노드 null
	}
	else if (node->data > data) { //노드의 데이터가 data보다 크면
		node->left = makeTree(node->left, data); //노드의 왼쪽으로 이동
	}
	else if (node->data < data) { //반대의 경우
		node->right = makeTree(node->right, data); //노드의 오른쪽으로 이동
	}
	return node; //노드 return
}

//후위 순회
void postorder(node_info *node) {
	if (node == NULL) { //비교
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout << node->data << '\n'; //출력
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() { //main함수
	int input; //정수형 변수

	//입력 & 연산
	node_info *root = NULL;
	while (cin >> input) { //트리를 전위 순회한 결과
		root = makeTree(root, input);
	}

	//출럭
	postorder(root); //트리를 후위 순회한 결과
	return 0; //0을 return
}