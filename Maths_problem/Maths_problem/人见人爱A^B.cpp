#include<stdio.h>
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		int ans = 1;
		if (a == 0 && b == 0) break;
		while (b != 0) {// һ�߼���b�Ķ�����ֵ��һ�߼���a��2^k�Σ�������Ҫ�Ĳ����۳˵�����ans��
			if (b % 2 != 0) {//��ǰ������λΪ1
				ans = ans * a;
				ans = ans % 1000; // ÿ��ֻȡ�����λ���������㼴��
			}
			a = a * a; //ÿ�ζ�������λ����ҪȨ�ظ���
			a = a % 1000;
			b = b / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}