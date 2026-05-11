Q link:https://leetcode.com/problems/rotting-oranges/description/

using pp = pair<int, pair<int, int>>;
class Solution {
private:
int noOfRows;
int noOfColumns;
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

bool isInsideBoundary(int nRow, int nCol, vector<vector<int>> &trackVisitedCells, vector<vector<int>> &grid)
{
    if(nRow < 0 || nRow >= noOfRows || nCol < 0 || nCol >= noOfColumns) return false;

    return trackVisitedCells[nRow][nCol] == 0 && grid[nRow][nCol] == 1;
}

public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        noOfRows = grid.size();
        noOfColumns = grid[0].size();

        queue<pp> Q;
        vector<vector<int>> trackVisitedCells(noOfRows, vector<int> (noOfColumns, 0));

        int countOfFreshOranges = 0;

        for(int row = 0; row < noOfRows; row++)
        {
            for(int col = 0; col < noOfColumns; col++)
            {
                if(grid[row][col] == 2)
                {
                    Q.push({0, {row, col}});
                    trackVisitedCells[row][col] = 1;
                }

                else if(grid[row][col] == 1) countOfFreshOranges += 1;
            }
        }

        int minTimeTaken = 0;

        while(!Q.empty())
        {
            int currTime = Q.front().first;
            int currRow = Q.front().second.first;
            int currCol = Q.front().second.second;
            Q.pop();

            minTimeTaken = max(minTimeTaken, currTime);
            
            for(int ind = 0; ind < 4; ind++)
            {
                int nRow = currRow + dx[ind];
                int nCol = currCol + dy[ind];

                if(isInsideBoundary(nRow, nCol, trackVisitedCells, grid))
                {
                    countOfFreshOranges -= 1;
                    Q.push({currTime + 1, {nRow, nCol}});
                    trackVisitedCells[nRow][nCol] = 1;
                }
            }
        }

        return countOfFreshOranges == 0 ? minTimeTaken : -1;
    }
};
