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
	// 더 이상 분할 할 수 없는 경우 return
	if (inStart > inEnd || postStart > postEnd)
		return;
	// postorder의 끝 값이 root값
	// Index 배열을 통해 inorder에서의 root index를 쉽게 구할 수 있다.
	int rootIndex = Index[postorder[postEnd]];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;
	cout << inorder[rootIndex] << ' '; // root 값 출력

									   // 재귀 함수 호출
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