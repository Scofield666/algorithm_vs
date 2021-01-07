#include<bits/stdc++.h>
using namespace std;
const int maxns = 1e5;
string add(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.size() < b.size()) {
		a += "0";
	}
	while (b.size() < a.size()) {
		b += "0";
	}
	string ret = "";
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		int tmp = a[i] - '0' + b[i] - '0' + carry;
		ret += to_string(tmp % 10);
		carry = tmp / 10;
	}
	if (carry != 0) ret += to_string(carry);
	reverse(ret.begin(), ret.end());
	return ret;
}
int cmp(string a, string b) {
	if (a.size() > b.size()) {
		return 1;
	}
	else if (a.size() < b.size()) {
		return -1;
	}
	else {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i]) return 1;
			else if (a[i] < b[i]) return -1;
		}
	}
	return 0;
}
string subs(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (b.size() < a.size()) {
		b += "0";
	}
	string ret = "";
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		int tmp = a[i] - '0' - carry - (b[i] - '0');
		if (tmp < 0) {
			ret += to_string(tmp + 10);
			carry = 1;
		}
		else {
			ret += to_string(tmp);
			carry = 0;
		}
	}
	reverse(ret.begin(), ret.end());
	while (ret[0] == '0') ret.erase(0, 1);
	return ret;
}
string sub(string a, string b) {
	string ret;
	if (cmp(a, b) == 1) ret = subs(a, b);
	else if (cmp(a, b) == 0) ret = "0";
	else {
		ret = subs(b, a);
		ret.insert(0, "-");
	}
	return ret;
}
string multi(string a, int x) {
	string ret = "";
	reverse(a.begin(), a.end());
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		int tmp = (a[i] - '0')*x + carry;
		ret += to_string(tmp % 10);
		carry = tmp / 10;
	}
	if (carry != 0) { //�ǳ���Ҫ carryҪ����������
		string c = to_string(carry);
		reverse(c.begin(), c.end());
		ret += c;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string multiply(string a, string b) {
	string ret = "";
	reverse(b.begin(), b.end());
	string carry = "0";
	for (int i = 0; i < b.size(); i++) {
		string tmp = add(multi(a, b[i] - '0'), carry);
		ret += tmp[tmp.size() - 1];
		carry = tmp.erase(tmp.size() - 1, 1); //ȥ�����һ���ַ�
	}
	reverse(carry.begin(), carry.end());
	ret += carry;
	reverse(ret.begin(), ret.end());
	return ret;
}

int mod(string a, int x) {
	int r = 0;
	for (int i = 0; i < a.size(); i++) {
		int tmp = r * 10 + (a[i] - '0');
		r = tmp % x;
	}
	return r;
}


int mod2(string a, int x) {
	int ret = 0;
	for (int i = 0; i < a.size(); i++) {
		//�����10��ΪĿ�����kҲ��һ����
		ret = (ret * 10 + a[i] - '0') % x; //�Ӹ�λ���� 192%8=(19*10)mod8 + 2mod8 = (19mod8 * 10) + 2mod8
	}
	return ret;
}

string div(string a, int x) {
	int r = 0;
	string ret = "";
	for (int i = 0; i < a.size(); i++) {
		int tmp = r * 10 + a[i] - '0';
		ret += to_string(tmp / x);
		r = tmp % x;
	}
	while (ret[0] == '0') ret.erase(0, 1);
	return ret;
}
int main() {
	string a, b;
	int c;
	cin >> a >> b;
	cin >> c;
	cout << "�ӷ���" << add(a, b) << endl;
	cout << "������" << sub(a, b) << endl;
	cout << "�˷���" << multi(a, c) << endl;
	cout << "��˷���" << multiply(a, b) << endl;
	cout << "ģ��" << mod(a, c) << endl;
	cout << "ģ2��" << mod2(a, c) << endl;
	cout << "������" << div(a, c) << endl;
	return 0;
}