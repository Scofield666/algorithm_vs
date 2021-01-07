#include<bits/stdc++.h>
using namespace std;
struct Node {
	int x;
	char y[10];
	
	bool operator < (const Node &a) const{
		if (a.x != x) return x < a.x;
		return strcmp(y, a.y) < 0;
	}
};
map<Node, int>mp; //��map�д�Žṹ���ʱ�򣬺����value�൱����û�õ�

bool cmp(const pair<Node, int> &a, const pair<Node, int> &b) {
	return a.second > b.second; //����value����
}

int main() {
	int cnt = 0;
	Node tmp = { 5,"ab" };
	mp.insert(make_pair(tmp,cnt));
	cnt++;
	tmp = { 4,"abcde" };
	mp.insert(make_pair(tmp, cnt));
	cnt++;
	tmp = { 4,"abc" };
	mp.insert(make_pair(tmp, cnt));
	cnt++;
	tmp = { 4,"ac" };
	mp.insert(make_pair(tmp, cnt));
	cnt++;
	tmp = { 2,"cb" };
	mp.insert(make_pair(tmp, cnt));
	cnt++;
	map<Node, int>::iterator it;
	it = mp.begin();
	printf("map�ṹ�尴��key����:\n");
	while (it != mp.end()) {
		printf("key: %d %s, value:%d\n", it->first.x, it->first.y, it->second);
		it++;
	}

	vector<pair<Node, int>>vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), cmp);
	vector<pair<Node, int>>::iterator it2 = vec.begin();
	printf("map�ṹ�尴��value����:\n");
	while (it2 != vec.end()) {
		printf("value:%d, key:%d %s\n", it2->second, it2->first.x, it2->first.y);
		it2++;
	}
	return 0;
}