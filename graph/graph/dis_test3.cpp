#include<bits/stdc++.h>
using namespace std;
const int maxns = 101;
int dis[maxns]; //表示源点到该点的最短距离
int mark[maxns]; //表示是否已在K集合中
int n, m;
struct E {
	int weight;
	int next;
};
vector<E> edge[maxns];
void init() {
	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
		mark[i] = 0;
		edge[i].clear();
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		// 1. 初始化邻接链表
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			E tmp;
			tmp.next = b;
			tmp.weight = c;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}

		// 2. 加入第一个点
		dis[1] = 0;
		mark[1] = 1;
		int newp = 1;
		
		for (int i = 1; i < n; i++) {//对其他n-1个点，做n-1次遍历，更新dis
			for (int j = 0; j < edge[newp].size(); j++) {//3. 对新加入的点的所有邻接边，进行源点到该点的距离更新
				E tmp = edge[newp][j];
				int c = tmp.next;
				int w = tmp.weight;
				if (mark[c] == 1) continue;
				if (dis[c] == -1 || dis[newp] + w < dis[c]) { //比较从源点到A+A到C 和源点直接到C的距离
					dis[c] = dis[newp] + w;
				}
			}
			// 4. 从所有的dis中找最短的加入K集合，注意剪枝（已经加入的和dis==-1
			int mintmp = 123456;
			for (int i = 1; i <= n; i++) {
				if (mark[i] == 1) continue;
				if (dis[i] == -1) continue;
				if (mintmp >= dis[i]) {
					mintmp = dis[i];
					newp = i;
				}
			}
			mark[newp] = 1;
		}
		printf("%d\n", dis[n]);
	}
}