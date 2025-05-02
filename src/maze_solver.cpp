#include "maze_solver.h"
#include <stack>
using namespace std;

bool MazeSolver::dfs(Maze& maze, int r, int c, vector<vector<bool>>& visited) {

    if (r < 0 || r >= maze.grid.size() || c < 0 || c >= maze.grid[0].size()) {
        return false;
    }

    char cell = maze.grid[r][c];
    if (cell == '#' || visited[r][c]) {
        return false;
    }

    visited[r][c] = true;

    if (cell == 'F') {
        maze.path.push_back({r, c});
        return true;
    }

    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; dir++) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (dfs(maze, nr, nc, visited)) {
            maze.path.push_back({r, c});
            return true;
        }
    }

    return false;
}


bool MazeSolver::solveDFS(Maze& maze) {
    // Clear any existing path
    maze.path.clear();

    // Create visited matrix
    vector<vector<bool>> visited(maze.grid.size(),
                                 vector<bool>(maze.grid[0].size(), false));

    // Start DFS from the start position
    bool found = dfs(maze, maze.start.row, maze.start.col, visited);

    // If path found, add the start position to the path
    if (found) {
        maze.path.push_back(maze.start);
    }

    return found;
}
