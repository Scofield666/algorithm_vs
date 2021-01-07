#include<bits/stdc++.h>
using namespace std;
/*
	s.insert(Node)
	s.erase(iterator)
	s.lower_bound(target_node) ���ص�һ�����ڵ���(����cmp����)target_node��iterator
-	s.upper_bound(target_node)
*/
struct Node {
	int x;
	char y[10];
};

struct cmp {
	//������ȥ�ıȽϺ��� ��Ҫ��()֧�������Ƚ϶���
	bool operator () (const Node &a, const Node &b) {
		if (a.x != b.x) return a.x < b.x; //�Ȱ���x��С��������
		int res = strcmp(a.y, b.y); //x��ȣ�����y��С��������
		return res < 0;
	}
};
set<Node, cmp>s;
int main() {
	Node tmp = { 5,"ab" }; //������ʼ�� ��������������
	//tmp.x = 1; tmp.y = "ab";
	s.insert(tmp);
	tmp = { 4,"abcde" };
	s.insert(tmp);
	tmp = { 4,"abc" };
	s.insert(tmp);
	tmp = { 4,"ac" };
	s.insert(tmp);
	tmp = { 2,"def" };
	s.insert(tmp);

	set<Node, cmp>::iterator it;
	it = s.begin();
	while (it != s.end()) {
		printf("%d %s\n", it->x, it->y);
		it++;
	}
	return 0;
}