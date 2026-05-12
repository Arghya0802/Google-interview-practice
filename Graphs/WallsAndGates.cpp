Q link: https://leetcode.com/problems/walls-and-gates/

class Solution {
using pp = pair<int, pair<int, int>>;
private:
const vector<int> dx = {-1, +1, 0, 0};
const vector<int> dy = {0, 0, -1, +1};
const int INF = INT_MAX;

bool isInsideBoundary(int nRow, int nCol, int noOfRows, int noOfColumns, vector<vector<int>> &rooms)
{
    if(nRow < 0 || nRow >= noOfRows || nCol < 0 || nCol >= noOfColumns) return false;

    return rooms[nRow][nCol] == INF ? true : false;
}

public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        int noOfRows = rooms.size(), noOfColumns = rooms[0].size();

        queue<pp> Q;

        for(int row = 0; row < noOfRows; row++)
        {
            for(int col = 0; col < noOfColumns; col++)
            {
                if(rooms[row][col] == 0)
                {
                    Q.push({0, {row, col}});
                }
            }
        }

        while(!Q.empty())
        {
            int currDist = Q.front().first;
            int currRow = Q.front().second.first;
            int currCol = Q.front().second.second;
            Q.pop();

            for(int ind = 0; ind < dx.size(); ind++)
            {
                int nRow = currRow + dx[ind];
                int nCol = currCol + dy[ind];

                if(isInsideBoundary(nRow, nCol, noOfRows, noOfColumns, rooms))
                {
                    rooms[nRow][nCol] = 1 + currDist;
                    Q.push({1 + currDist, {nRow, nCol}});
                }
            }
        }

        return;
    }
};
