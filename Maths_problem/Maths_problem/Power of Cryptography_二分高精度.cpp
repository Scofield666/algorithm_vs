#include<bits/stdc++.h>
using namespace std;
//����*С��  ����������������һ��ѭ��
int n;
string p;
string multi(string a, int x) {
	string ret = "";
	reverse(a.begin(), a.end());
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		int tmp = carry + (a[i] - '0') * x;
		ret += to_string(tmp % 10);
		carry = tmp / 10;
	}
	if (carry) {
		string c = to_string(carry);
		reverse(c.begin(), c.end());
		ret += c;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int cmp(string a, string b) {
	if (a.size() < b.size()) return -1;
	else if (a.size() > b.size()) return 1;
	else {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i]) return 1;
			else if (a[i] < b[i]) return -1;
		}
		return 0;
	}
}

//����a��t�η�
string mypow(int a, int t) {
	string ret = "1";
	while (t--) {
		ret = multi(ret, a);
	}
	return ret;
}

int binarysearch(string target) {
	int l = 1;
	int r = 1e9;
	while (l < r) {
		int mid = l + (r - l) / 2;
		int cmpres = cmp(mypow(mid, n), p);
		if ( cmpres == 0) return mid;
		else if (cmpres == 1) r = mid;
		else l = mid + 1;
	}
	return -1;
}
int main() {
	while (cin >> n >> p) {
		int ans = binarysearch(p);
		if (ans != -1) printf("%d\n", ans);
	}
	return 0;
}