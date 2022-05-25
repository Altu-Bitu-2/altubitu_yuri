#include <iostream>

using namespace std;

struct node_info { //����ü
	int data; //������ ����
	node_info *left; //���� ���
	node_info *right; //������ ���
};

node_info *makeTree(node_info *node, int data) {
	if (node == NULL) { //�̹� ��尡 ���Ե� ��ġ
		node = new node_info(); //���� �Ҵ�
		node->data = data; //����� ������ �Ҵ�
		node->left = node->right = NULL; //����, ������ ��� null
	}
	else if (node->data > data) { //����� �����Ͱ� data���� ũ��
		node->left = makeTree(node->left, data); //����� �������� �̵�
	}
	else if (node->data < data) { //�ݴ��� ���
		node->right = makeTree(node->right, data); //����� ���������� �̵�
	}
	return node; //��� return
}

//���� ��ȸ
void postorder(node_info *node) {
	if (node == NULL) { //��
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout << node->data << '\n'; //���
}

/**
 * �ʰ� �� PPT �� BST ��� ���� ���� ����
 *
 * [���� �˻� Ʈ��]
 *
 * 1. �����ͷ� ����, ������ ����Ʈ���� ����Ű�� ����ü ����
 * 2. NULL ���� ������ ���ǿ� ���� ���� �Ǵ� ���������� �̵�
 * 3. ��尡 �� ��ġ�� ã���� �����Ҵ� �� ��� �����
 * 4. �ϼ��� Ʈ���� ���� ��ȸ
 */

int main() { //main�Լ�
	int input; //������ ����

	//�Է� & ����
	node_info *root = NULL;
	while (cin >> input) { //Ʈ���� ���� ��ȸ�� ���
		root = makeTree(root, input);
	}

	//�ⷰ
	postorder(root); //Ʈ���� ���� ��ȸ�� ���
	return 0; //0�� return
}