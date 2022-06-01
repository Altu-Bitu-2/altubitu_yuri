#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //ģ�� ���谡 ��� �ٸ� ����ڷ� ������ ���� ���� �ִ�

vector<int> parent(MAX + 1, -1);
map<string, int> people;

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
		parent[xp] += parent[yp]; //yp������ xp�� ����
		parent[yp] = xp; //����
	}
	else { //���ο� ��Ʈ yp
		parent[yp] += parent[xp]; //xp������ yp�� ����
		parent[xp] = yp; //����
	}
}

/**
 * [ģ�� ��Ʈ��ũ]
 *
 * 1. weighted union find -> ��Ʈ ������ ģ���� ��(���� ���� ��) ����
 * 2. ģ�� ��Ʈ��ũ�� �� �� �ִ��� ���ϱ� -> ��Ʈ ������ parent�� ����
 *
 * !����! ������ ���ڿ��� �����Ƿ� map�� Ȱ���� string�� int�� ����
 */

int main() { //main�Լ�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f; //������ ����
	string a, b; //���ڿ� ����

	//�Է�
	cin >> t; //�׽�Ʈ���̽��� ���� �Է�
	while (t--) { //�ݺ�
		int idx = 1; //������ ������ ��
		parent.assign(MAX + 1, -1);

		cin >> f; //ģ�� ������ �� �Է�
		while (f--) { //�ݺ�
			cin >> a >> b; //������� ���̵� �Է�
			if (!people[a]) { //�迭 a�� ������
				people[a] = idx++; //�߰�
			}
			if (!people[b]) { //�迭 b�� ������
				people[b] = idx++; //�߰�
			}

			//����
			int x = people[a], y = people[b]; //�� �迭 ����
			unionInput(x, y); //���Ͽ� ����

			//���
			cout << -parent[findParent(x)] << '\n'; //ģ�� ���谡 ���� ������, �� ����� ģ�� ��Ʈ��ũ�� �� ���� �ִ��� ���
		}
	}
	return 0;
}