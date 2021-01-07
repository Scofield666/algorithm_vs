#include<bits/stdc++.h>
using namespace std;
const int maxns = 1000, inf = 0x3f3f3f3f;
// �ֽ�������
int prime[maxns];
int cnt = 0;
int num[maxns];
void divfac(int x) {
	for (int i = 2; i < sqrt(x) + 1; i++) {
		if (x%i == 0) {
			prime[cnt] = i;
			while (x%i == 0) {
				num[cnt]++;
				x /= i;
			}
			cnt++;
			if (x == 1) break;
		}
	}
	if (x != 1) {
		prime[cnt] = x;
		num[cnt] = 1;
		cnt++;
	}
}

//������������
int calcfac(int x) {
	int ret = 0;
	for (int i = 1; i < sqrt(x) + 1; i++) {
		if (x%i == 0) {
			if (x / i == i) {
				ret += 1;
			}
			else ret += 2;
		}
	}
	return ret;
}

int digit[250]; //mod1000 ֻ��Ҫ��250ÿλ����4λ��
int dsize = 0;
//��λ
void set(string s) {
	int len = s.size();
	int weight = 1;
	int cnt = 0;
	int tmp = 0;
	for (int i = len - 1; i >= 0; i--) {
		tmp = tmp + weight * (s[i] - '0');
		weight *= 10;
		cnt++;
		if (cnt == 4) {
			digit[dsize++] = tmp;
			tmp = 0;
			weight = 1;
			cnt = 0;
		}
	}
	if (cnt != 0) digit[dsize++] = tmp;
}

int moddigit(int digit[], int x) {
	int ret = 0;
	for (int i = dsize - 1; i >= 0; i--) {
		ret = (ret * 10000 + digit[i]) % x;
	}
	return ret;
}

//digit����*x  �������digit������
void multidigit(int digit[], int x) {
	int carry = 0;
	for (int i = 0; i < dsize; i++) {
		int tmp = carry + digit[i] * x;
		digit[i] = tmp % 10000;
		carry = tmp / 10000;
	}
	if (carry && dsize < 250) digit[dsize++] = carry; //ֻ�豣��250λ����
}

bool mark[maxns];
void shai() {
	for (int i = 2; i <= maxns; i++) {
		if (mark[i] == true) continue;
		prime[cnt++] = i;
		for (int j = 2 * i; j <= maxns; j++) {
			mark[j] = true;
		}
	}
	mark[0] = mark[1] = true;
}

