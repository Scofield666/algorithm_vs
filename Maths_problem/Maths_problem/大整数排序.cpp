#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define N 1000
using namespace std;
int cmp(const void *a, const void *b) {//ע������ĸ������ķ���ֵ��int
	char *c = (char *)a;//ǿ������ת����ʹaָ���ַ���
	char *d = (char *)b;
	int l1 = strlen(c);
	int l2 = strlen(d);
	if (l1 != l2) {//����ַ�����һ��������ֱ�ӷ��أ����ȳ���Ϊ�󣬷���ֵΪ��
		return l1 - l2;
	}
	else {
		return (strcmp(c, d));
	}
}
char str[N][10001];//��ά���鶨�� һ����һ��str[i]������һ���ַ���
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", str[i]);
	}
	qsort(str, n, sizeof(str[0]),cmp); //ע�����������Ϊ��Ԫ�ص�ռ�ÿռ��С �����Ԫ��ָ����һ���ַ���
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << endl;
	}
	return 0;
}