#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
const int maxns = 1e6 + 10;
/*
	�Ҹ������䳤���µ���ֵ
	��С����������
	��󣺵����ݼ�
*/
deque<int>dq1; //����С
deque<int>dq2;//�����
int n, k;
int a[maxns];
int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		dq1.clear();
		dq2.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		//����������Сֵ
		for (int i = 0; i < n; i++) {
			while (!dq1.empty() && a[dq1.back()] >= a[i]) dq1.pop_back(); //ά����������
			dq1.push_back(i);
			if (i >= k - 1) { //���������䳤��ʱ����Ҫ�жϵ�ǰͷ�Ƿ���������
				while (!dq1.empty() && dq1.front() <= i - k) dq1.pop_front();
				if(i != n - 1) printf("%d ", a[dq1.front()]);
				else printf("%d\n", a[dq1.front()]);
			}
		}
		//�����������ֵ
		for (int i = 0; i < n; i++) {
			while (!dq2.empty() && a[dq2.back()] <= a[i]) dq2.pop_back(); //ά���ݼ�����
			dq2.push_back(i);
			if (i >= k - 1) { //���������䳤��ʱ����Ҫ�жϵ�ǰͷ�Ƿ���������
				while (!dq2.empty() && dq2.front() <= i - k) dq2.pop_front();
				if (i != n - 1) printf("%d ", a[dq2.front()]);
				else printf("%d\n", a[dq2.front()]);
			}
		}
	}
	return 0;
}