#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find ����
int findParent(int node) { 
	if (parent[node] < 0) { //�����϶�
		return node; //node�� return
	}
	return parent[node] = findParent(parent[node]); //��Ʈ ���� ã��
}

//Union ����
bool unionInput(int x, int y) {
	int xp = findParent(x); //find����
	int yp = findParent(y); //find����

	if (xp == yp) { //������
		return false;
	}
	if (parent[xp] < parent[yp]) { //���ο� ��Ʈ xp
		parent[xp] += parent[yp]; //yp������ xp�� ����
		parent[yp] = xp; //����
	}
	else { //���ο� ��Ʈ yp
		parent[yp] += parent[xp]; //xp������ yp�� ����
		parent[xp] = yp; //����
	}
	return true;
}

/**
 * [����Ŭ ����]
 *
 * ����Ŭ�� �߻��� ���� = ���� ���տ� �ִ� ���� �� ���� ���Ͽ��Ϸ� �� ��
 * unionInput �Լ��� ��ȯ���� bool�� �����Ͽ� cycle�� �����Ǵ� ���� �߰��ϱ�
 */

int main() { //main�Լ�
	int n, m, x, y; //������ ����

	//�Է�
	cin >> n >> m; //���� ������ ����� ������ �� �Է�
	parent.assign(n, -1); //���� ��ȣ �ο�
	for (int i = 0; i < m; i++) { //�ݺ�
		cin >> x >> y; //�ش� �÷��̾ ������ �� ���� ��ȣ �Է�

		//���� & ���
		if (!unionInput(x, y)) { //����Ŭ�� ������
			cout << i + 1; //m ��° ���ʱ��� ������ ������ ��Ȳ���� �̹� ������ ����Ǿ��ٸ� ����Ŭ�� ó������ ������� ������ ��ȣ�� ���� ������ ���
			return 0;
		}
	}
	cout << 0; //m ���� ���ʸ� ��� ó���� ���Ŀ��� ������� �ʾҴٸ� 0�� ���
	return 0;
}