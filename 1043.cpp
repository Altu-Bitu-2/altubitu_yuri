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
void unionInput(int x, int y) {
	int xp = findParent(x); //find ����
	int yp = findParent(y); //find ����

	if (xp == yp) { //������
		return;
	}
	if (parent[xp] < parent[yp]) { //���ο� ��Ʈ xp
		parent[xp] += parent[yp]; //yp ������ xp�� ����
		parent[yp] = xp; //����
	}
	else { //���ο� ��Ʈ yp
		parent[yp] += parent[xp]; //xp ������ yp�� ����
		parent[xp] = yp; //����
	}
}

int liarParty(vector<int> &parties) {
	int cnt = 0; //������ ����
	for (int i = 0; i < parties.size(); i++) { //��Ƽ�� ����ŭ �ݺ�
		if (findParent(parties[i]) != findParent(0)) { //find����+0�� �ٸ���
			cnt++; //����
		}
	}
	return cnt; //cnt�� return
}

/**
 * [������]
 *
 * 1. �� ������� �پ��� ��Ƽ�� ���� ����ƴٰ� �� �� ����
 * 2. ����� ������� ���� ���տ� ����
 * 3. �� ���տ� ���� ����� �� �� ���̶� ������ �ȴٸ� �� ������ ������� ���� ��Ƽ���� �������� �� �� ����
 * -> ���Ͽ� ���ε�� ������� �������� ���� ��, ��Ƽ���� �������� �� �� �ִ��� Ȯ���ϱ�
 * -> �̶�, ������ �ƴ� ������� ��Ʈ ������ 0���� �����ؼ� ���Ͽ� ���ε带 ���� �������� ���� ����
 * -> 0�� ���� ������ �ƴϾ�� �������� �� �� ����
 *
 * !����! ��Ƽ ������ �Է¹����� �ٷ� ������ ���� ���θ� �Ǵ��� �� ���� (���� �Է� 4)
 *       �� ��Ƽ���� �� ����� �����ص� ��, �������� ������ ���� ���� �� ���� �Ǵ�
 */

int main() { //main�Լ�
	int n, m; //������ ����

	//�Է�
	cin >> n >> m; //����� ���� ��Ƽ�� �� �Է�
	parent.assign(n + 1, -1); //�θ� ���� ũ�� ����, �ʱ�ȭ

	int init, p; //������ ����
	cin >> init; //�̾߱��� ������ �ƴ� ����� �� �Է�
	while (init--) { //������ �ƴ� �����
		cin >> p; //��ȣ �Է�
		unionInput(0, p); //���Ͽ� ����
	}

	int cnt, first_person, person; //������ ����
	vector<int> parties;
	while (m--) { //m��ŭ �ݺ�
		cin >> cnt >> first_person; //�� ��Ƽ���� ���� ����� ���� ��ȣ �Է�

		//����
		parties.push_back(first_person); //��Ƽ ������ �� ��Ƽ�� ù��° ����� ����
		while (--cnt) { //��� ����ŭ �ݺ�
			cin >> person; //��� ��ȣ �Է�
			unionInput(first_person, person); //���Ͽ� ����
		}
	}

	//���� & ���
	cout << liarParty(parties); //������ ���� ���
	return 0; //0�� return
}