#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

char map[51][51] = {0,};
int dist[51][51] = {0,};
int R, C;
int sx, sy, ex,ey; // start, end
queue<pair<int,int>> q;

void init() {
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') { // start
				sx = i; sy = j; 
				dist[i][j] = 1;
			}
			else if (map[i][j] == 'D') { // end
				ex = i; ey = j;
			}
			else if (map[i][j] == '*') { // water start
				q.push({i, j}); 
				dist[i][j] = 1;
			}
			else if (map[i][j] == 'X') { // X
				dist[i][j] = -1; 	
			}
		}
	}
    q.push({sx, sy});
}

void BFS() {
	while(!q.empty()) {
		pair<int,int> p = q.front();
		q.pop();
		int x, y, nx, ny;

		x = p.first; y = p.second;
		
		for (int i=0; i<4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			
			if (map[x][y] == '*' && map[nx][ny] == 'D') continue;
			
			if (dist[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				map[nx][ny] = map[x][y];
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	init();
	BFS();
	if (map[ex][ey] == 'S') cout << dist[ex][ey] - 1;
	else cout << "KAKTUS";
	return 0;
}