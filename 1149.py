import sys
sys.setrecursionlimit(100000)
R, G, B = (0, 1, 2)
N = int(input())
color_cost = [[-1, -1, -1]] + [list(map(int, input().split(' '))) for i in range(N)]
min_cost = [[-1 for j in range(3)] for i in range(N+1)]

min_cost[1][R] = min(color_cost[1][G], color_cost[1][B])
min_cost[1][G] = min(color_cost[1][B], color_cost[1][R])
min_cost[1][B] = min(color_cost[1][R], color_cost[1][G])

def get_pair_colors(color):
    if color == R:
        return (G, B)
    elif color == G:
        return (R, B)
    elif color == B:
        return (R, G)

def get_min_cost(N, parent_color = None, parent_cost = -1):
    if parent_color == None:
        return min(get_min_cost(N-1, R, color_cost[N][R]), get_min_cost(N-1, G, color_cost[N][G]), get_min_cost(N-1, B, color_cost[N][B])) 
    else:
        if N == 1:
            return parent_cost + min_cost[1][parent_color]
        else:
            pair = get_pair_colors(parent_color)
            if min_cost[N][parent_color] == -1:
                min_cost[N][parent_color] = parent_cost + min(get_min_cost(N-1, pair[0], color_cost[N][pair[0]]), get_min_cost(N-1, pair[1], color_cost[N][pair[1]]))
            return min_cost[N][parent_color]
   
print(get_min_cost(N, None, -1))   