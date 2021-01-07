#include<bits/stdc++.h>
using namespace std;
const int maxns = 101;
int dis[maxns]; //��ʾԴ�㵽�õ����̾���
int mark[maxns]; //��ʾ�Ƿ�����K������
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
		// 1. ��ʼ���ڽ�����
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

		// 2. �����һ����
		dis[1] = 0;
		mark[1] = 1;
		int newp = 1;
		
		for (int i = 1; i < n; i++) {//������n-1���㣬��n-1�α���������dis
			for (int j = 0; j < edge[newp].size(); j++) {//3. ���¼���ĵ�������ڽӱߣ�����Դ�㵽�õ�ľ������
				E tmp = edge[newp][j];
				int c = tmp.next;
				int w = tmp.weight;
				if (mark[c] == 1) continue;
				if (dis[c] == -1 || dis[newp] + w < dis[c]) { //�Ƚϴ�Դ�㵽A+A��C ��Դ��ֱ�ӵ�C�ľ���
					dis[c] = dis[newp] + w;
				}
			}
			// 4. �����е�dis������̵ļ���K���ϣ�ע���֦���Ѿ�����ĺ�dis==-1
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