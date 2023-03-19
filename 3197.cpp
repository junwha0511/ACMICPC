/*
Reachability problem
빙판 state를 변화시키며 reachability를 test

연결된 모든 물을 set으로 만들고, set을 merge 해야함
동일한 set에서 동일한 set id pointer를 같도록 구현

백조 두 마리가 동일한 set에 존재하는지 확인
*/


#include<iostream>
#include<cstdio>

using namespace std;

static int available_cluster_id = 0;

enum Type {
    SWAN,
    WATER,
    ICE,
    MELTING
};

struct Unit {
    Type type;
    unsigned int *cluster_id;
};

inline void merge(Unit *dst, Unit *src) {
    *(dst->cluster_id) = *(src->cluster_id); 
}

inline bool is_reachable_type(Type type) {
    return type == WATER || type == SWAN;
}

void mark_reachable(Unit **grid, int R, int C, int i, int j) {
    unsigned int *cluster_id = grid[i][j].cluster_id;
    
    if (i != 0 && grid[i-1][j].cluster_id == nullptr && is_reachable_type(grid[i-1][j].type)) { 
        grid[i-1][j].cluster_id = cluster_id;
        mark_reachable(grid, R, C, i-1, j);
    } 
    if (i != R-1 && grid[i+1][j].cluster_id == nullptr && is_reachable_type(grid[i+1][j].type)) { 
        grid[i+1][j].cluster_id = cluster_id;
        mark_reachable(grid, R, C, i+1, j);
    }
    if (j != 0 && grid[i][j-1].cluster_id == nullptr && is_reachable_type(grid[i][j-1].type)) { 
        grid[i][j-1].cluster_id = cluster_id;
        mark_reachable(grid, R, C, i, j-1);
    }
    if (j != C-1 && grid[i][j+1].cluster_id == nullptr && is_reachable_type(grid[i][j+1].type)) { 
        grid[i][j+1].cluster_id = cluster_id;
        mark_reachable(grid, R, C, i, j+1);
    }
}

void cluster(Unit **grid, int R, int C) { // O(R*C)
    unsigned int *ice_cluster_id = new unsigned int;
    *ice_cluster_id = available_cluster_id++; 
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {  
            if (grid[i][j].type == ICE) {
                grid[i][j].cluster_id = ice_cluster_id;
            } else if (grid[i][j].cluster_id == nullptr) {
                grid[i][j].cluster_id = new unsigned int;
                *(grid[i][j].cluster_id) = available_cluster_id++;
                mark_reachable(grid, R, C, i, j);
            } 
        }
    }
}

inline bool is_reachable(Unit **grid, pair<int, int> *swans) {
    return *grid[swans[0].first][swans[0].second].cluster_id == *grid[swans[1].first][swans[1].second].cluster_id;
}

inline void merge_with_melted_ice(Unit **grid, int R, int C, int i, int j) {
    if (i != 0 && grid[i-1][j].type != ICE) { 
        merge(&grid[i-1][j], &grid[i][j]);
    } 
    if (i != R-1 && grid[i+1][j].type != ICE) { 
        merge(&grid[i+1][j], &grid[i][j]);
    } 
    if (j != 0 && grid[i][j-1].type != ICE) { 
        merge(&grid[i][j-1], &grid[i][j]);
    } 
    if (j != C-1 && grid[i][j+1].type != ICE) { 
        merge(&grid[i][j+1], &grid[i][j]);
    } 
}

inline bool has_water(Type type){
    return type == SWAN || type == WATER;
}

inline Unit* find_water_from_surround(Unit **grid, int R, int C, int i, int j) {
    if (i != 0 && has_water(grid[i-1][j].type)) return &grid[i-1][j];
    if (i != R-1 && has_water(grid[i+1][j].type)) return &grid[i+1][j];
    if (j != 0 && has_water(grid[i][j-1].type)) return &grid[i][j-1];
    if (j != C-1 && has_water(grid[i][j+1].type)) return &grid[i][j+1];
    return nullptr;
}

void melt(Unit **grid, int R, int C) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {  
            if (grid[i][j].type == ICE) {
                Unit *water = find_water_from_surround(grid, R, C, i, j);
                if (water != nullptr){
                    grid[i][j].type = MELTING;
                    grid[i][j].cluster_id = water->cluster_id; // get new cluster id
                    merge_with_melted_ice(grid, R, C, i, j);
                }
            } 
        }
    }
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {  
            if (grid[i][j].type == MELTING) grid[i][j].type = WATER;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    pair<int, int> swans[2];
    int swan_init_idx = 0;

    cin >> R >> C;
    Unit **grid = new Unit*[R];
    

    for (int i=0; i<R; i++) {
        grid[i] = new Unit[C];
        for (int j=0; j<C; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                grid[i][j].type = ICE;
            } else if (c == '.') {
                grid[i][j].type = WATER;
            } else {
                grid[i][j].type = SWAN;
                swans[swan_init_idx++] = make_pair(i, j);
            }
        }
    }
    cluster(grid, R, C);

    int days = 0;
    while (1) {
        if (is_reachable(grid, swans)) 
            break;
        melt(grid, R, C);
        // for (int i=0; i<R; i++) {
        //     for (int j=0; j<C; j++) {  
        //         cout << *grid[i][j].cluster_id;
        //     }
        //     cout << "\n";
        // }
        cout << "\n";
        days++;
    }

    cout << days << "\n";

    // Destroy
    // TODO: many leaks for cluster id...
    for (int i=0; i<R; i++) {
        delete grid[i];
    }
    delete[] grid;

    return 0;
}