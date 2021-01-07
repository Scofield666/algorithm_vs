#include<bits/stdc++.h>
using namespace std;
int cnt = 0; //entry的长度
int n; //n个点
int tree[101];
void init() {
	for (int i = 0; i < n; i++) {
		tree[i] = -1;
	}
}
int findroot(int x) {
	int ret;
	int tmp = x;
	while (tree[x] != -1) {
		x = tree[x];
	}
	ret = x;
	x = tmp;
	while (tree[x] != -1) {
		int temp = tree[x];
		tree[x] = ret;
		x = temp;
	}
	return ret;
}

struct P {
	float x;
	float y;
}point[101];
struct Node {
	int a;
	int b; //两个点的序号
	float w;
}entry[5050];
bool cmp(Node &A, Node &B) {
	return A.w < B.w;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%f%f", &point[i].x, &point[i].y);
		}
		//1. 计算两个点之间的距离
		cnt = 0; //entry长度
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				entry[cnt].a = i;
				entry[cnt].b = j;
				entry[cnt].w = sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y));
				cnt++;
			}
		}
		//2. 排序 
		sort(entry, entry + cnt, cmp);
		init();
		float ans = 0;
		//3.遍历
		for (int i = 0; i < cnt; i++) {
			int roota = findroot(entry[i].a);
			int rootb = findroot(entry[i].b);
			if (roota != rootb) {
				tree[roota] = rootb;
				ans += entry[i].w;
			}
		}
		printf("%f\n", ans);
	}
}
