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

#define VISITED 0
#define WATER 1
#define ICE 2
#define WILL_BE_MELT 3
#define SWAN 4

static short directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int R, C;
    short swans[2][2];
    char swan_idx = 0;
    int u, v;
    cin >> R >> C;
    char **grid = new char*[R];
    
    for (int i=0; i<R; i++) {
        grid[i] = new char[C];
        for (int j=0; j<C; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                grid[i][j] = ICE;
            } else if (c == '.') {
                grid[i][j] = WATER;
            } else { 
                grid[i][j] = WATER;
                swans[swan_idx][0] = i;
                swans[swan_idx++][1] = j;
            }
        }
    }
    
    
    queue<pair<short, short>> melting_ices;

    // Construct initial melting ices queue
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (grid[i][j] == ICE) {
                for (int k=0; k<4; k++) {
                    u = i+directions[k][0];
                    v = j+directions[k][1];
                    if (u >= 0 && u < R && v >=0 && v < C) {
                        if (grid[u][v] == WATER) {
                            melting_ices.push(make_pair(i, j));
                            grid[i][j] = WILL_BE_MELT;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    grid[swans[0][0]][swans[0][1]] = VISITED;
    short days = 0;
    int i, j;
    queue<pair<int, int>> swan_queue;
    swan_queue.push(make_pair(swans[0][0], swans[0][1]));
    for (int n=0; n<1500; n++) { // Days will be at most 1499
        bool other_swan_found = false;
        bool is_swan_reinit = false;
        
        while (!swan_queue.empty() && !other_swan_found) {
            pair<int, int> swan_pos = swan_queue.front();
            swan_queue.pop();
            for (int k=0; k<4; k++) {
                u = swan_pos.first+directions[k][0];
                v = swan_pos.second+directions[k][1];
                if (u >= 0 && u < R && v >=0 && v < C) {
                    if (u == swans[1][0] && v == swans[1][1]) {
                        other_swan_found = true;
                        break;
                    } else if (grid[u][v] == WATER) {
                        grid[u][v] = VISITED;
                        swan_queue.push(make_pair(u, v));
                    } 
                }
            }
        }
        
        if (other_swan_found) break;
        
        int n_melting_ices = melting_ices.size();
        if (n_melting_ices == 0) break;

        for (int k=0; k<n_melting_ices; k++) {
            pair<short, short> ice_position = melting_ices.front();
            melting_ices.pop(); 
            
            i = ice_position.first;
            j = ice_position.second;

            grid[i][j] = WATER;
            for (int k=0; k<4; k++) {
                u = i+directions[k][0];
                v = j+directions[k][1];
                if (u >= 0 && u < R && v >=0 && v < C) {
                    if (grid[u][v] == ICE) {
                        grid[u][v] = WILL_BE_MELT;
                        melting_ices.push(make_pair(u, v));
                    } else if (grid[u][v] == VISITED) {
                        grid[i][j] = VISITED;
                        swan_queue.push(make_pair(i, j));
                    }
                } 
            }
        }
        days++;
    }

    cout << days << "\n";

    // Destroy
    for (int i=0; i<R; i++) {
        delete grid[i];
    }
    delete[] grid;

    return 0;
}