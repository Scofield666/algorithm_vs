#include<bits/stdc++.h>
using namespace std;
const int maxns = 1e5;
//判断是否为素数
bool judge(int x) {
	for (int i = 2; i < sqrt(x) + 1; i++) {
		if (x%i == 0) return false; //找到一个
	}
	return true;
}

//素数筛法 筛选出1e5以内所有的素数 保存在prime数组内
bool mark[maxns]; //true代表是素数 false为合数 初始为true
int prime[maxns];
int primesize = 0;
void shai() {
	memset(mark, true, sizeof(mark));
	for (int i = 2; i <= maxns; i++) {
		if (mark[i] == false) continue;
		prime[primesize++] = i;
		for (int j = 2 * i; j <= maxns; j += i) {
			mark[j] = false;
		}
	}
	mark[0] = mark[1] = false;
}

//求因子个数
int facnum(int x) {
	int ret = 0;
	for (int i = 1; i < sqrt(x) + 1; i++) {
		if (x%i == 0) {
			if (i == x / i) ret = ret + 2;
			else ret++;
		}
	}
	return ret;
}

//求素因子的个数 相同因子重复计算个数并且包含本身
int primefac[maxns];
int psize = 0;
int primeFacNum(int x) {
	int ret = 0;
	for (int i = 2; i < sqrt(x) + 1; i++) {
		if (x%i == 0) {
			primefac[psize++] = i;
			while (x%i == 0) {
				ret++;
				x /= i;
			}
		}
		if (x == 1) break;
	}
	if (x != 1) { //还没分解完 最后剩下的是大于sqrt(x)的素数
		primefac[psize++] = x;
		ret++;
	}
	return ret;
}

//区间素筛 1<l<r<1e9 求范围在1e6左右的动态区间[l,r]内的素数/每个数质因数的个数 
const int maxns2 = 1e6 + 1;
int a[maxns2]; // 存放偏移 把l-r的所有值存放在1e6的数组中
int primefactor[maxns2]; //1e9内的数的质因子在1e5内 用素筛找出这些
int pcnt = 0;
int num[maxns2]; //l-r内每个数的质因数个数 和 a数组对应
int l, r;
bool mark2[maxns2];
void shai2() {
	memset(mark2, true, sizeof(mark2));
	for (int i = 2; i <= 1e5; i++) {
		if (mark2[i] == false) continue;
		primefactor[pcnt++] = i;
		for (int j = 2 * i; j <= 1e5; j += i) {
			mark2[j] = false;
		}
	}
	mark2[0] = mark2[1] = false;
}
void qujiansushai() {
	for (int i = l; i <= r; i++) {
		a[i - l] = i; //偏移存到a数组中
	}

	shai2(); //筛出1e5以内的素数

	//用所有这些素数去筛保存在a中的区间值l-r 看这个素数是不是当前数的因子
	for (int i = 0; i < pcnt; i++) {
		//取当前素数去筛指定区间内的数 首先需要定位到当前素数的倍数在区间内的开始位置
		int currentp = primefactor[i];
		int start = l / currentp * currentp; 
		for (int j = start; j <= r; j+=currentp) {
			if (j < l) continue;
			if (a[j - l] % currentp == 0) {
				while (a[j - l] % currentp == 0) {
					num[j - l]++;
					a[j - l] /= currentp;
				}
			}
		}
	}
	//如果当前数不为1 剩下最后的素因子
	for (int i = 0; i <= r - l; i++) {
		if (a[i] != 1) num[i]++;
	}

	//num是素数-> mark为true
	int ans = 0;
	for (int i = 0; i <= r - l; i++) {
		if (mark[num[i]] == true) ans++;
	}
}





