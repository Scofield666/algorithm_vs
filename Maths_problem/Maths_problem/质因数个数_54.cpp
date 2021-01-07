#include<stdio.h>
#define MAXSIZE 100001 // 10�ľŴη�������
int prime[MAXSIZE];
int primesize=0;
int flags[MAXSIZE];
//����ɸ��
void init() {
	for (int i = 1; i < MAXSIZE; i++) {
		flags[i] = 0;//��ʼ��Ϊ0 0����Ϊ����
	}
	for (int j = 2; j < MAXSIZE; j++) {
		if (flags[j] == 0) {//�������������ô������������
			prime[primesize] = j;
			primesize++;
			if (j >= 1000) continue; //���ӵĻ��ᵼ��k̫�� ���������
			for (int k = j * j; k < MAXSIZE; k += j) {//�������ı���ɸ��ȥ
				flags[k] = 1;
			}
		}
		else continue; //�����������
	}
}
int main() {
	init();
	int n; //���ֽ����
	while (scanf("%d", &n) != EOF) {
		int j=0;//������������
		int ans_prime_size[30] = { 0 }; // ����ÿ���������Ĵ���
		int ans_prime[30]; // ����������
		int ans_idx = 0;
		for (j = 0; j < MAXSIZE; j++) {
			if (n % prime[j] == 0) {
				ans_prime[ans_idx] = prime[j];//����������ӣ�����ans_prime����
				ans_prime_size[ans_idx]++;
				n = n / prime[j]; //�������������
				while (n%prime[j] == 0) {//��������������������
					ans_prime_size[ans_idx]++;
					n = n / prime[j];
				}				
				ans_idx++;
				if (n == 1) break; //nΪ1 �ֽ����1
			}
		}
		if (n != 1) { //�����û���ֽ��1�� ˵��2-100000֮�������û������������ ֻ����һ������100000������
			ans_prime[ans_idx] = n;
			ans_prime_size[ans_idx] = 1;
		}

		int ans = 0;
		for (int m = 0; m <= ans_idx; m++) {
			ans += ans_prime_size[m];
		}
		printf("%d\n", ans);
	}
	return 0;
}