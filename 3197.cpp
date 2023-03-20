/*
1. 얼음과 인접한 물 Queue 유지
2. 녹을 얼음 유지
3. 얼음 녹임 -> 녹을 얼음을 인접한 물로 교체
4. 백조 입장에서 reachable한 물로 이동 (-> 어떻게?)
5. 백조 둘이 reachable이 되나?

! 양쪽에서 만날 필요가 없음

백조 한 마리를 기준으로
1. 물에 인접한 ICE를 Queue로 유지
--- Loop 2-4 ---
2. Reachability Test: 백조를 물에서 이동시키고, 상대 백조를 만날 경우 종료  
3. 방문한 모든 Water를 VISITED로 표시
4. Queue에 존재하는 모든 ICE를 녹이고, 인접한 ICE를 Queue에 다시 넣음

문제점: Melting ICE 중 인접한 것을 모두 추적해야만 가능
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

#define WATER 0
#define ICE 1
#define SWAN 2

static int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C;
    int swans[2][2];
    char swan_idx = 0;
    cin >> R >> C;
    char grid[1500][1500] = {0,};
    
    queue<pair<int, int>> water_queue;
    queue<pair<int, int>> swan_queue;
    bool visited[1500][1500] = {false,};

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                grid[i][j] = ICE;
            } else if (c == '.') {
                grid[i][j] = WATER;
                water_queue.push(make_pair(i, j));
            } else { 
                water_queue.push(make_pair(i, j));
                grid[i][j] = WATER;
                swans[swan_idx][0] = i;
                swans[swan_idx++][1] = j;
            }
        }
    }

    swan_queue.push(make_pair(swans[0][0], swans[0][1]));
    visited[swans[0][0]][swans[0][1]] = true;

    int days = 0;
    while (1) { // Days will be at most 1499
        bool other_swan_found = false;

        queue<pair<int, int>> swan_ice_queue;
        while (!swan_queue.empty() && !other_swan_found) {
            pair<int, int> swan_pos = swan_queue.front();
            swan_queue.pop();
            for (int k=0; k<4; k++) {
                int u = swan_pos.first+directions[k][0];
                int v = swan_pos.second+directions[k][1];
                if (u >= 0 && u < R && v >= 0 && v < C && !visited[u][v]) {
                    visited[u][v] = true;
                    if (u == swans[1][0] && v == swans[1][1]) {
                        other_swan_found = true;
                        break;
                    } else if (grid[u][v] == WATER) {
                        swan_queue.push(make_pair(u, v));
                    } else if (grid[u][v] == ICE) {
                        swan_ice_queue.push(make_pair(u, v));
                    }
                }
            }
        }
        if (other_swan_found) {
            break;
        }
        swan_queue = swan_ice_queue;

        int n_water_queue = water_queue.size();

        while (n_water_queue--) {
            pair<int, int> pos = water_queue.front();
            water_queue.pop(); 
            
            int i = pos.first;
            int j = pos.second;
            for (int k=0; k<4; k++) {
                int u = i+directions[k][0];
                int v = j+directions[k][1];
                if (u >= 0 && u < R && v >= 0 && v < C) {
                    if (grid[u][v] == ICE) {
                        grid[u][v] = WATER;
                        water_queue.push(make_pair(u, v));
                    } 
                } 
            }
        }
        days++;
    }

    cout << days << "\n";

    return 0;
}