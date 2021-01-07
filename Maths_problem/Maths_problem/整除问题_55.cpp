#include<stdio.h>
#include<math.h>
int prime[1000];//1-1000�����е�����
int primesize=0;// 1-1000�����е���������
int flags[1001];

void init() { // ɸѡ��1000�������е�������Ϊʲô��1000����?��Ϊn�׳˵�������һ��С��n
	for (int i = 1; i < 1001; i++) {
		flags[i] = 0;
	}
	for (int i = 2; i < 1001; i++) {
		if (flags[i] == 1)
			continue;
		else {
			prime[primesize] = i;
			primesize++;
			for (int j = i * i; j < 1001; j+=i) {
				flags[j] = 1;
			}
		}
	}
}

int main() {
	init();
	int a, n;
	while (scanf("%d%d", &n, &a) != EOF) {
		int a_prime_size[1001]; //С��n��������a�еĴ���������Ϊ0
		int n_prime_size[1001]; //С��n��������n�׳��еĴ���������Ϊ0

		for (int i = 0; i < primesize; i++) {
			a_prime_size[i] = n_prime_size[i] = 0;//�ȰѴ�������Ϊ0
		}
		//��������������a�еĴ���
		//int size = 0;
		for (int i = 0; i < primesize; i++) {
			if (a%prime[i] == 0) { // ����ܱ�������������˵��Ϊһ��������
				a_prime_size[i]++;
				a = a / prime[i];
				while (a%prime[i] == 0) {
					a_prime_size[i]++;
					a = a / prime[i];
				}
				if (a == 1) break;
			}
			else continue;
		}

		//��������������n�׳��еĴ���
		for (int i = 0; i < primesize; i++) {
			int j = 1;
			int m = pow(prime[i], j);
			while (n / m != 0) {
				n_prime_size[i] += n / pow(prime[i], j);
				j++;
				m = pow(prime[i], j);
			}
		}
		//����ÿ��������Ӧ�����ĳ���
		int k=123123132;//���ȡһ����������Ϊȡ��Сֵ��׼��
		int tmp;
		for (int i = 0; i < primesize; i++) {
			if (a_prime_size[i] == 0) {
				//k = n_prime_size[i];
				continue;
			}
			tmp = n_prime_size[i] / a_prime_size[i];
			if (tmp <= k) {
				k = tmp;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}