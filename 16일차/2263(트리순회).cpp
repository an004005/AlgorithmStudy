#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int Index[100001]{};
int inorder[100001]{};
int postorder[100001]{};

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
	// �� �̻� ���� �� �� ���� ��� return
	if (inStart > inEnd || postStart > postEnd)
		return;
	// postorder�� �� ���� root��
	// Index �迭�� ���� inorder������ root index�� ���� ���� �� �ִ�.
	int rootIndex = Index[postorder[postEnd]];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;
	cout << inorder[rootIndex] << ' '; // root �� ���

									   // ��� �Լ� ȣ��
	getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
	getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> inorder[i];
		Index[inorder[i]] = i;
	}

	for (int i = 1; i <= n; i++)
		cin >> postorder[i];

	getPreOrder(1, n, 1, n);

	return 0;
}