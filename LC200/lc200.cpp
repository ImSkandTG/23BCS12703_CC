#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vc vector<char>
#define vvc vector<vc>
class Solution {
public:
    bool isValid(int x, int y, vvc& grid) {
        return x<grid.size() && y<grid[0].size();
    }
    void bfs(int i, int j, vvc &grid, vvi &vst, vii& dir) {
        vst[i][j] = 1;
        queue<ii>q;
        q.push({i, j});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto it : dir) {
                int nrow = row+it.first;
                int ncol = col+it.second;
                if (isValid(nrow, ncol, grid) && grid[nrow][ncol]=='1' && !vst[nrow][ncol]) {
                    vst[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
            if (q.empty()) break;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vii dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vvi vst(n, vi(m, 0));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (!vst[i][j] && grid[i][j]=='1') {
                    cnt++;
                    bfs(i, j, grid, vst, dir);
                }
            }
        }
        return cnt;
    }
};
