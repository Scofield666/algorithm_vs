#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxns = 1e6 + 2;
int a[maxns]; //�������4n+1
int b[maxns]; //a�Ŀ���
int cnta = 0;

int prime[1005]; //�������4n+1 Ϊ��������
int pcnt = 0;
bool mark[maxns];
bool is[maxns]; //true������4n+1 
void init() {
	memset(is, false, sizeof(is));
	for (int i = 1; i < maxns; i++) {
		if ((i - 1) % 4 == 0) {
			a[cnta++] = i;
			is[i] = true;
		}
	}
	memset(mark, true, sizeof(mark));
	for (int i = 5; i < 1e3 + 1; i++) {
		if (mark[i] == false || is[i] == false ) continue;
		prime[pcnt++] = i;
		
		for (int j = i + i; j < 1e3 + 1; j += i ) {
			if (is[j]) mark[j] = false;
		}
	}
	mark[1] = false;
}

int num[maxns];//��¼a������ÿ��������������

int main() {
	int h;
	init();
	while (scanf("%d", &h) != EOF) {
		memset(num, 0, sizeof(num));
		if (h == 0) break;
		for (int i = 0; i < cnta; i++) b[i] = a[i];

		//��a���ҵ�h��λ�� ����h֮ǰ��������
		int p = 0;
		for (int i = 0; i < cnta; i++) {
			if (b[i] > h) {
				p = i;
				break;
			}
		}

		for (int i = 0; i < pcnt; i++) {
			if (prime[i] >= h) break; //��ǰ����h���� ֱ��break
			for (int j = 0; j < p; j++) {
				if (b[j] % prime[i] == 0) {
					while (b[j] % prime[i] == 0) {
						num[j]++;
						b[j] /= prime[i];
					}
				}
			}
		}
		for (int i = 0; i < cnta; i++) {
			if (b[i] != 1) num[i]++;
		}
		int ans = 0;
		for (int i = 0; i < cnta; i++) {
			if (num[i] == 2) ans++;
		}
		printf("%d %d\n", h, ans);
	}
	return 0;
}