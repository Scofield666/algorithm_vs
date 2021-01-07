#include<bits/stdc++.h>
using namespace std;
/*
	s.insert(Node)
	s.erase(iterator)
	s.lower_bound(target_node) 返回第一个大于等于(根据cmp规则)target_node的iterator
-	s.upper_bound(target_node)
*/
struct Node {
	int x;
	char y[10];
};

struct cmp {
	//单独出去的比较函数 就要用()支持两个比较对象
	bool operator () (const Node &a, const Node &b) {
		if (a.x != b.x) return a.x < b.x; //先按照x从小到大排序
		int res = strcmp(a.y, b.y); //x相等，按照y从小到大排序
		return res < 0;
	}
};
set<Node, cmp>s;
int main() {
	Node tmp = { 5,"ab" }; //这样初始化 而不是下面那种
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