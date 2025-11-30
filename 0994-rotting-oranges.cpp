class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int minutes = -1;
        bool done = true;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) qu.push({ i, j });
                if (grid[i][j] == 1) done = false;
            }
        }

        if (done) return 0;

        while (qu.size()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = qu.front();
                qu.pop();

                if (x > 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    qu.push({ x-1, y });
                }
                if (y > 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    qu.push({ x, y-1 });
                }
                if (x < grid.size() - 1 && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    qu.push({ x+1, y });
                }
                if (y < grid[0].size() - 1 && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    qu.push({ x, y+1 });
                }
            }
            minutes++;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }
};
