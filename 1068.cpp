#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//�־��� ������ ������ ���� ���� ����� ��
int eraseLeafCnt(int node, int &erase_node) {
	if (node == erase_node) { //��
		return 0; //0�� return
	}
	if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) { //��
		return 1; //1�� return
	}
	int cnt = 0; //������ ����
	for (int i = 0; i < tree[node].size(); i++) {  //�ݺ�
		cnt += eraseLeafCnt(tree[node][i], erase_node); 
	}
	return cnt; //cnt�� return
}

/**
 * [Ʈ��]
 *
 * ���� ���� ��� ������ ���� dfs Ž������ ����� ������ ������ �� �̻� Ž������ �ʰ� 0�� ����
 *
 * !����! ����� ������ �ش� �θ� ����� ������ �ڽ� ��忴�� ���, �ش� ������ ����� �θ� ��尡 ���� ��尡 �ż� ������ 1 �������� ����
 * !����! ��Ʈ ��尡 �׻� 0�� �ƴ��� ����
 */

int main() { //main �Լ�
	int n, par, root, erase_node; //������ ����

	//�Է�
	cin >> n; //Ʈ���� ��� ���� n �Է�
	tree.assign(n, vector<int>(0));
	for (int i = 0; i < n; i++) { //n��ŭ �ݺ�
		cin >> par; //�� ����� �θ� par �Է�
		if (par == -1) { //���� par�� -1�̸� (�θ� ���ٸ�)
			root = i; //root�� i�� ����
			continue;
		}
		tree[par].push_back(i);
	}
	cin >> erase_node; //���� ����� ��ȣ �Է�

	//���� & ���
	cout << eraseLeafCnt(root, erase_node); //���� ����� ���� ���
	return 0; //0�� return
}