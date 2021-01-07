#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q1; //С����

/*-------------------------------------------------------------------*/
struct cmp1 {
	//����ģ��� �������Ϊ<�����ȼ���a�����ȼ�<b�����ȼ� ��a>b��ʱ��
	bool operator () (const int &a, const int &b) {
		return a > b; //Խ�� ���ȼ�Խ�ͣ�Ҳ����С����
	}
};
priority_queue<int, vector<int>, cmp1>q2;//С����

/*-------------------------------------------------------------------*/
struct Node {
	int x;
	char y;
	//friend ��Ҫ�������Ƚ϶���
	friend bool operator < (const Node &a, const Node &b) {
		return a.x > b.x; //Խ�����ȼ�ԽС
	}
};
priority_queue<Node>q3;

int main() {
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	while (!q3.empty()) q3.pop();

	for (int i = 5; i >= 0; i--) {
		q1.push(i);
		q2.push(i);
		Node tmp;
		tmp.x = i; //y���⣬�����ǲ���С����
		tmp.y = 'a' + i;
		q3.push(tmp);
	}
	printf("q1: ");
	while (!q1.empty()) {
		int t = q1.top();
		q1.pop();
		printf("%d ", t);
	}
	printf("\n");
	printf("q2: ");
	while (!q2.empty()) {
		int t = q2.top();
		q2.pop();
		printf("%d ", t);
	}
	printf("\n");
	printf("q3: ");
	while (!q3.empty()) {
		Node t = q3.top();
		q3.pop();
		printf("%d ", t);
	}
	printf("\n");
	return 0;
}

