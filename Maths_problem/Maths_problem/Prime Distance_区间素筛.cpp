#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxns = 1e6 + 10, inf = 0x3f3f3f3f;
//ɸѡ��1e6����������
int prime[maxns];
int pcnt = 0;
bool mark[maxns];
void sushai() {
	memset(mark, true, sizeof(mark));
	for (int i = 2; i < maxns; i++) {
		if (mark[i] == false) continue;
		prime[pcnt++] = i;
		for (int j = i + i; j < maxns; j += i) {
			mark[j] = false;
		}
	}
	mark[0] = mark[1] = false;
}

int a[maxns]; //�������ֵ
bool isprime[maxns]; //����ֵ�Ƿ�Ϊ���� ��a��Ӧ
int finalprime[maxns];
int fcnt = 0;
int main() {
	int l, r;
	sushai();
	while (scanf("%d%d", &l, &r) != EOF) {
		for (int i = l; i <= r; i++) {
			a[i - l] = i;
		}
		memset(isprime, true, sizeof(isprime));
		for (int i = 0; i < pcnt; i++) {
			if (prime[i] > r) break;
			int currentp = prime[i];
			int start = l / currentp * currentp; //�ҵ���һ���������ڵı�����λ��
			start = max(start,currentp);
			//���������
			for (int j = start; j <= r; j += currentp) {
				if (j < l || j == currentp) continue;
				isprime[j - l] = false; //��Ӧλ�����ϱ��
			}
		}

		fcnt = 0;
		for (int i = l; i <= r; i++) {
			if (isprime[i - l] == true) finalprime[fcnt++] = i;
		}

		int minn = inf;
		int maxn = 0;
		int minl, minr;
		int maxl, maxr;
		for (int i = 0; i < fcnt - 1; i++) {
			if (finalprime[i + 1] - finalprime[i] < minn) {
				minl = finalprime[i];
				minr = finalprime[i + 1];
				minn = finalprime[i + 1] - finalprime[i];
			}
			if (finalprime[i + 1] - finalprime[i] > maxn) {
				maxl = finalprime[i];
				maxr = finalprime[i + 1];
				maxn = finalprime[i + 1] - finalprime[i];
			}
		}
		if(fcnt > 1) printf("%d,%d are closest, %d,%d are most distant.\n", minl, minr, maxl, maxr);
		else printf("There are no adjacent primes.\n");
	}
	return 0;
	
}