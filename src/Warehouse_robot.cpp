#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int N = 5;
int grid[N][N] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y, cost;
};

int main() {
    int sx = 0, sy = 0;
    int gx = 4, gy = 4;

    queue<Node> q;
    bool visited[N][N] = {};

    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    cout << "Warehouse Robot Pathfinding\n";
    cout << "S = Start, G = Goal, # = Obstacle\n\n";

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == gx && cur.y == gy) {
            cout << "Destination reached!\n";
            cout << "Steps: " << cur.cost << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, cur.cost + 1});
            }
        }
    }

    cout << "No path found!\n";
    return 0;
}
