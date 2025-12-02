class Solution {
public:
    int steps = 0;

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> qu;

        pair<int,int> ent {entrance[0], entrance[1]};
        qu.push(ent);
        maze[entrance[0]][entrance[1]] = 'v';

        while (qu.size()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = qu.front();
                qu.pop();

                if (checkNodeOnEdge(maze, {x,y}) && steps != 0)
                    return steps;

                if (x > 0 && maze[x-1][y] == '.') {
                    qu.push({ x-1, y });
                    maze[x-1][y] = 'v';
                }
                if (y > 0 && maze[x][y-1] == '.') {
                    qu.push({ x, y-1 });
                    maze[x][y-1] = 'v';
                }
                if (x < maze.size() - 1 && maze[x+1][y] == '.') {
                    qu.push({ x+1, y });
                    maze[x+1][y] = 'v';
                }
                if (y < maze[0].size() - 1 && maze[x][y+1] == '.') {
                    qu.push({ x, y+1 });
                    maze[x][y+1] = 'v';
                }
            }
            steps++;
        }

        return -1;
    }

    bool checkNodeOnEdge(vector<vector<char>>& maze, pair<int,int> coord) {
        auto [x, y] = coord;

        if (x == 0) return true;
        if (y == 0) return true;
        if (x == maze.size() - 1) return true;
        if (y == maze[0].size() - 1) return true;

        return false;
    }
};
