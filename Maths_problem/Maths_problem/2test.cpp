#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<iostream>
typedef long long ll;
using namespace std;
const int maxns = 50;
ll digit[maxns]; //每一位代表十位数字 用ll防止超精度
int dsize = 0;
void iniset(string a) {
	int len = a.size();
	ll tmp = 0;
	int cnt = 0;
	int weight = 1;
	for (int i = len - 1; i >= 0; i--) {
		tmp = tmp + (a[i] - '0')*weight;
		weight *= 10;
		cnt++;
		if (cnt == 10) {
			digit[dsize++] = tmp;
			tmp = 0;
			weight = 1;
			cnt = 0;
		}
	}
	if (cnt != 0) digit[dsize++] = tmp;
}
void multi(ll digit[], int x) {
	int carry = 0;
	for (int i = 0; i < dsize; i++) {
		ll tmp = carry + digit[i] * x;
		digit[i] = tmp % (ll)1e10;
		carry = tmp / (ll)1e10;
	}
	if (carry && dsize < maxns) digit[dsize++] = carry;
}

int main() {
	string s = "1";
	iniset(s);
	int n;
	cin >> n;
	while (n--) { //计算2的n次方
		multi(digit, 2);
	}
	for (int i = 49; i >= 0; i--) {
		printf("%010lld", digit[i]);
	}
	printf("\n");
	return 0;
}
