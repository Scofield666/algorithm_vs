#include<bits/stdc++.h>
using namespace std;
char mat[8][8];
int n, m, t;
bool mark[8][8];
int go[][2] = {
	-1,0,
	1,0,
	0,1,
	0,-1
};
bool success;
//�ݹ�����
void DFS(int x, int y, int time) {
	for (int i = 0; i < 4; i++) {
		int newx = x + go[i][0];
		int newy = y + go[i][1];

		if (newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
		if (mark[newx][newy] == true) continue;
		if (mat[newx][newy] == 'X') continue;
		
		if (mat[newx][newy] == 'D') {
			if (time + 1 == t) {
				success = true;
				return; //�ݹ����
			}
			else continue; //����D�㣬����mark�����ٴε���
		}
		mark[newx][newy] = true; //�õ���.�����Ե�����ȱ��
		DFS(newx, newy, time + 1);//�ݹ鷵�غ����һ��success�������
		mark[newx][newy] = false; //return֮�����,��������һ��״̬����״̬ת��
		if (success) return;//�жϱ���״̬ת�Ƶݹ������Ľ��
	}
}
int main() {
	int sx, sy;
	int dx, dy;
	while (scanf("%d%d%d", &n, &m, &t) != EOF) {
		if (n == 0 && m == 0 && t == 0) break;
		//��Ϊÿ���ַ�֮���и��س���������scanf���ж����ַ������������һ�����о�ֹͣ
		//���Ҫ���ַ�����Ļ���ÿ�ж�����Ҫgetchar
		getchar();//�������һ�л������еĻس�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%c", &mat[i][j]);
				mark[i][j] = false;
			}
			getchar(); //�������������һ�������Ļس�
		}
		//memset(mark, false, sizeof(mark));
		//����ʼ���Ŀ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'S') {
					sx = i;
					sy = j;
					continue;
				}
				if (mat[i][j] == 'D') {
					dx = i;
					dy = j;
				}
			}
		}
		mark[sx][sy] = true;
		//����T�����յ�����͵���ż�Խ��м�֦
		int sxy = sx + sy;
		int dxy = dx + dy;
		if ((t % 2 == 0 && (dxy - sxy) % 2 != 0) || (t % 2 != 0 && (dxy - sxy) % 2 == 0)) {
			success = false;
		}
		else DFS(sx, sy, 0);
		
		if (success) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}