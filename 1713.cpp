#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const pair<int, ci> &c1, const pair<int, ci> &c2) { //�� �Լ�
	if (c1.second.first != c2.second.first) { //��
		return c1.second.first < c2.second.first;
	}
	return c1.second.second < c2.second.second; //first�� ������ second ��
}

/**
 * [�ĺ� ��õ�ϱ�]
 *
 * 1. ����ִ� ����Ʋ�� ���� ���, ���� ��õ���� ���� �л� �� �Խ� �ð��� ������ �л��� ����
 * -> min_element() �Լ��� Ȱ���ؼ� ������ �����ϴ� �л� ã��
 * -> min_element(x.begin(), x.end(), cmp): x �����̳� ������ �ּڰ��� ã���ִ� �Լ��� ���İ� ����ϰ� cmp�Լ� �Ἥ ���� ���� ����!
 *
 * 2. �ĺ� �л��� �ٷ� ã�� ���� �� Ǯ�̴� map �����̳ʸ� ����� ����
 *
 * !����! �Խ� �ð� ���� ���� ��, �ĺ��� �ö� ���� ù �ð��� ����. �̹� �ĺ��� �ִµ� �Խ� �ð��� ���ŵ��� �ʵ��� ����.
 */

int main() { //main�Լ�
	int n, m, input; //������ ����

	//�Է� & ����
	cin >> n >> m; //�Է�
	map<int, ci> candidate; //first: �ĺ� �л�, second: {��õ Ƚ��, �Խ� �ð�}
	for (int i = 0; i < m; i++) { //m��ŭ �ݺ�
		cin >> input; //�Է�
		//����ִ� ����Ʋ�� ���� ���
		if (candidate.size() == n && candidate.find(input) == candidate.end()) {
			candidate.erase(min_element(candidate.begin(), candidate.end(), cmp)); //���� ��õ���� ���� �л� �� �Խ� �ð��� ������ �л��� ����
		}
		//ù �Խö��
		if (candidate.find(input) == candidate.end()) {
			candidate[input].second = i; //��õ���� �л��� ������ �����鿡 �Խ�
		}
		candidate[input].first++; //��õ Ƚ�� ����
	}

	//���
	for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {
		cout << iter->first << ' '; //���
	}
	return 0; //0�� return
}