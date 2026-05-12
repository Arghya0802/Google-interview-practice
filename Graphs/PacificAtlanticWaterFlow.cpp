Q link: https://leetcode.com/problems/pacific-atlantic-water-flow/
// Can be done better by doing multisource bfs and bitMasking instead of individual calling

class Solution {
using pp = pair<int, int>;
using ppx = pair<char, pair<int, int>>;
using ppy = pair<string, char>;

private:
const vector<int> dx = {-1, +1, 0, 0};
const vector<int> dy = {0, 0, -1, +1};

private:

bool canWaterFlow(int currRow, int currCol, int nRow, int nCol, int noOfRows, int noOfColumns, vector<vector<int>> &heights, vector<vector<int>> &ocean)
{
    if(nRow < 0 || nRow >= noOfRows || nCol < 0 || nCol >= noOfColumns) return false;

    return ocean[nRow][nCol] == 0 && heights[nRow][nCol] >= heights[currRow][currCol];
}

void bfs(int currRow, int currCol, int noOfRows, int noOfColumns, vector<vector<int>> &heights, vector<vector<int>> &ocean)
{
    queue<pp> Q;
    Q.push({currRow, currCol});
    ocean[currRow][currCol] = 1;

    while(!Q.empty())
    {
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();

        for(int ind = 0; ind < dx.size(); ind++)
        {
            int nRow = row + dx[ind];
            int nCol = col + dy[ind];

            if(canWaterFlow(row, col, nRow, nCol, noOfRows, noOfColumns, heights, ocean))
            {
                Q.push({nRow, nCol});
                ocean[nRow][nCol] = 1;
            }
        }
    }

    return;
}

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int noOfRows = heights.size(), noOfColumns = heights[0].size();

        queue<ppx> Q;
        vector<vector<int>> pacific(noOfRows, vector<int> (noOfColumns, 0));
        vector<vector<int>> atlantic(noOfRows, vector<int> (noOfColumns, 0));

        // Adding cells that are at the boundary with Pacific Ocean
        for(int col = 0; col < noOfColumns; col++) 
        {
            bfs(0, col, noOfRows, noOfColumns, heights, pacific);
            bfs(noOfRows - 1, col, noOfRows, noOfColumns, heights, atlantic); 
        }

        for(int row = 0; row < noOfRows; row++) 
        {
            bfs(row, 0, noOfRows, noOfColumns, heights, pacific);
            bfs(row, noOfColumns - 1, noOfRows, noOfColumns, heights, atlantic);
        }
        
        vector<vector<int>> ans;

        for(int row = 0; row < noOfRows; row++)
        {
            for(int col = 0; col < noOfColumns; col++)
            {
                if(pacific[row][col] > 0 && atlantic[row][col] > 0) 
                    ans.push_back({row, col});
            }
        }

        return ans;
    }
};
