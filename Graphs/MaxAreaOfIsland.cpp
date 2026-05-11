Q link: https://leetcode.com/problems/max-area-of-island/
using pp = pair<int, int>;

class Solution {
private:
int noOfRows;
int noOfColumns;

int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

bool canbeVisited(int nRow, int nCol, vector<vector<int>> &trackVisitedCells, vector<vector<int>> &grid)
{
    if(nRow < 0 || nRow >= noOfRows || nCol < 0 || nCol >= noOfColumns) return false;

    return trackVisitedCells[nRow][nCol] == 1 || grid[nRow][nCol] == 0 ? false : true;
}

int bfs(int currRow, int currCol, vector<vector<int>> &trackVisitedCells, vector<vector<int>> &grid)
{
    queue<pp> Q;
    Q.push({currRow, currCol});
    trackVisitedCells[currRow][currCol] = 1;
    int area = 1;

    while(!Q.empty())
    {
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();

        for(int ind = 0; ind < 4; ind++)
        {
            int nRow = row + dx[ind];
            int nCol = col + dy[ind];

            if(canbeVisited(nRow, nCol, trackVisitedCells, grid))
            {
                Q.push({nRow, nCol});
                trackVisitedCells[nRow][nCol] = 1;
                area++;
            }
        }
    }

    return area;
}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        noOfRows = grid.size(), noOfColumns = grid[0].size();
        int maxIslandArea = 0;

        vector<vector<int>> trackVisitedCells(noOfRows, vector<int> (noOfColumns, 0));

        for(int row = 0; row < noOfRows; row++)
        {
            for(int col = 0; col < noOfColumns; col++)
            {
                if(grid[row][col] == 0) continue;

                if(!trackVisitedCells[row][col])
                {
                    int currArea = bfs(row, col, trackVisitedCells, grid);
                    maxIslandArea = max(maxIslandArea, currArea);
                }
            }
        }

        return maxIslandArea;
    }
};
