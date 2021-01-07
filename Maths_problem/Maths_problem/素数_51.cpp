#include<stdio.h>
#include<math.h>
#define MAXSIZE 10000
int primenum = 0;
int prime[MAXSIZE]; //�������
int flags[MAXSIZE + 1]; 
// 0����Ϊ���� 1����Ϊ���� 
// ע�������ʼ���ĳ��� ��Ϊ�˱ȽϷ���Ĵ洢 ����flags[1]�ʹ�����1�Ƿ�Ϊ����
//һ��Ҫ��ȫ�ֱ���
void init() {
	for (int i = 1; i < MAXSIZE + 1; i++) {
		flags[i] = 0; //���ȳ�ʼ��Ϊ0 ����Ϊ1-10000��������
	}

	for (int j = 2; j < MAXSIZE + 1; j++) { // ����ɸ�� ��2��ʼ
		if (flags[j] == 1) // ���������ĳ���ı��� ˵���������� ��ɸѡ��һ����
			continue;
		else {
			prime[primenum] = j;
			primenum++; 
			for (int k = j * j; k < MAXSIZE + 1; k+=j) {
				flags[k] = 1;//������������
			}
		}
	}
}
int main() {
	init();
	int bound; 

	while (scanf("%d", &bound) != EOF) {
		bool firstout = true; //��ǰ����ǵ�һ����� ע��һ��Ҫ�ŵ�ѭ�����棡��
		int m = 0; //�ֲ��������� ÿ������Ҫ��ͷ��ʼ����
		while (prime[m] < bound ) {
			if (prime[m] % 10 == 1 ) {//ĩβΪ1
				if (firstout == true) {
					printf("%d", prime[m]);
					firstout = false;
				}
				else {
					printf(" %d", prime[m]);
				}
			}
			m++;
		}

		if (firstout == true) {//�����Ϊtrue�Ļ�˵��û�Ĺ� Ҳ����û�н���ѭ���ҵ�����������
			printf("-1\n");
		}
		else printf("\n");
	}
	return 0;
}