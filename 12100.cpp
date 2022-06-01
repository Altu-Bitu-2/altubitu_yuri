#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0; //������ ����

int getMaxBlock(matrix &board) { //�ִ� ���ϴ� ����
	int max_block = 0; //������ ����
	for (int i = 0; i < n; i++) { //�ݺ�
		for (int j = 0; j < n; j++) { //�ݺ�
			max_block = max(max_block, board[i][j]); //�ִ� ��
		}
	}
	return max_block; //�ִ��� return
}

matrix transposeMatrix(matrix &board) { //��ġ��� ���ϴ� ����
	matrix board_t(n, vector<int>(n, 0)); //����
	for (int i = 0; i < n; i++) { //�ݺ�
		for (int j = 0; j < n; j++) { //�ݺ�
			board_t[i][j] = board[j][i]; //�Ųٷ� ����
		}
	}
	return board_t; //��ġ����� return
}

/**
 * ������ �̵��ϴ� �Լ�
 * - �� ���� �˻��ϸ鼭 ���� ����� 2���� ���� �� �ִٸ� ��ġ��
 * - �̶� ��� ���� �κ��� �Ѿ��, ����� �����ߴ� ���� �����ؼ� ���ϴ� ���� �߿�!
 */
matrix upMove(matrix board) {
	matrix temp(n, vector<int>(n, 0)); //���Ӱ� ��� ������ �迭
	for (int j = 0; j < n; j++) { //�ݺ�
		int idx = 0; //��ǥ
		int prev = 0; //���� ��� ��ȣ
		for (int i = 0; i < n; i++) { //�ݺ�
			if (!board[i][j]) { //0�϶�
				continue;
			}
			if (board[i][j] == prev) { //���� ��� ��ȣ�� ������
				temp[idx - 1][j] *= 2; //�迭�� ����
				prev = 0; //�ʱ�ȭ
			}
			else {
				temp[idx++][j] = board[i][j]; //�ٸ���
				prev = board[i][j]; //����
			}
		}
	}
	return temp; //temp�� return
}

//��Ʈ��ŷ Ž��
void backtracking(int cnt, matrix board) {
	if (cnt == 5) { //5���϶�
		ans = max(ans, getMaxBlock(board)); //�ִ� ����
		return;
	}
	//Transpose matrix ���ϱ� (��->��)
	matrix board_t = transposeMatrix(board); //��ġ ��� ����
	//��
	backtracking(cnt + 1, upMove(board)); //��Ʈ��ŷ
	//��
	reverse(board.begin(), board.end()); //������
	backtracking(cnt + 1, upMove(board)); //��Ʈ��ŷ
	//��
	backtracking(cnt + 1, upMove(board_t)); //��ġ ��� ���� ��Ʈ��ŷ
	//��
	reverse(board_t.begin(), board_t.end()); //��ġ ��� ���� ������
	backtracking(cnt + 1, upMove(board_t)); //��ġ ��� ���� ��Ʈ��ŷ
}

/**
 * [2048 (Easy)]
 *
 * - ��, ��, ��, ��� �̵��ϴ� ��쿡 ���� �ִ� 5�� �̵���Ű�� ��� ��츦 ���� ��, ���� ū ��� ã�� ���� - ��Ʈ��ŷ
 * - �����̴� �Լ��� �ϳ��� ¥��, ���带 �������鼭 ��, ��, ��, �� ��� ������ �������� ����
 *
 * - �� <-> ��: �� ������ ����� �ذ�
 * - ��/�� <-> ��/��: Transpose Matrix Ȱ��
 *
 * - ex. 2 2 1 �� ��, ��, ��, ��� �̵��ϴ� ��� ���ϴ� ��
 *       2 2 2
 *       4 4 4
 *  -��: ���� �迭���� ������ �����̴� �Լ� ����
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -��: ���� �迭�� �� ������ ������ ��, ������ �����̴� �Լ� ����
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -��: ���� �迭�� ��ġ ����� ���� ��, ������ �����̴� �Լ� ����
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -��: ���� �迭�� ��ġ ��Ŀ��� �� ������ ������ ��, ������ �����̴� �Լ� ����
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() { //main�Լ�
	//�Է�
	cin >> n; //������ ũ�� �Է�
	matrix board(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) { //�ݺ� 
		for (int j = 0; j < n; j++) { //�ݺ�
			cin >> board[i][j]; //�ʱ� ���� �Է�
		}
	}

	//����
	backtracking(0, board); //��Ʈ��ŷ

	//���
	cout << ans; //�ִ� 5�� �̵����Ѽ� ���� �� �ִ� ���� ū ����� ���
	return 0;
}