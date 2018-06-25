class Solution {
public:
    void dfs(vector<vector<int>>& grid, int& ans, int x, int y) {
        ans++;
        for (int i = 0; i < 4; i++) {
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            dfs(grid, ans+1, nx, ny);
        }

    }
    int largestIsland(vector<vector<int>>& grid) {
        int maxa = 0, cnt;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                memset(vis, 0, sizeof vis);
                cnt = 0;
                if (!grid[i][j]) {
                    grid[i][j] = 1;
                    dfs(grid, cnt, i, j);
                    grid[i][j] = 0;
                } else {
                    dfs(grid, cnt, i, j);
                }
                maxa = max(maxa, cnt);
            }
        return maxa;
    }
public:
    int vis[55][55];
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};