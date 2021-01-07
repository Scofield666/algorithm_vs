#include<bits/stdc++.h>
using namespace std;
const int maxns = 1e5 + 10;
int cycle[] = { 0,1,1,2,3,1 }; //fib取模 循环节
vector<int>sum; //发现循环节也是6
int sumc[] = { 0,1,2,0,3,0 };
int mod(string a, int x) {
	int ret = 0;
	for (int i = 0; i < a.size(); i++) {
		ret = (ret * 10 + a[i] - '0') % x;
	}
	return ret;
}
int main() {
	string l, r;
	sum.push_back(0);
	for (int i = 1; i < maxns; i++) {
		int t = cycle[i % 6];
		sum.push_back((sum[i - 1] + t) % 4);
	}
	while (cin >> l >> r) {
		int lidx = mod(l, 6);
		lidx--;
		if (lidx < 0) lidx = 5;
		int ridx = mod(r, 6);
		int ans = sumc[ridx] - sumc[lidx];
		if (ans < 0) ans += 4;
		printf("%d\n", ans);
	}
	return 0;
}
