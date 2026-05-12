Q link: https://leetcode.com/problems/surrounded-regions/

class Solution {
using pp = pair<int, int>;
private:
const vector<int> dx = {-1, +1, 0, 0};
const vector<int> dy = {0, 0, -1, +1};

bool isInsideBoundary(int nRow, int nCol, int noOfRows, int noOfColumns, vector<vector<char>> &board)
{
    if(nRow < 0 || nRow >= noOfRows || nCol < 0 || nCol >= noOfColumns) return false;

    return board[nRow][nCol] == 'O';
}

public:
    void solve(vector<vector<char>>& board) 
    {   
        int noOfRows = board.size(), noOfColumns = board[0].size();
        queue<pp> Q;

        for(int row = 0; row < noOfRows; row++)
        {   
            if(board[row][0] == 'O') 
            {
                Q.push({row, 0});
                board[row][0] = '-';
            }

            if(board[row][noOfColumns - 1] == 'O') 
            {
                Q.push({row, noOfColumns - 1});
                board[row][noOfColumns - 1] = '-';
            }
        }

        for(int col = 0; col < noOfColumns; col++)
        {   
            if(board[0][col] == 'O') 
            {
                Q.push({0, col});
                board[0][col] = '-';
            }

            if(board[noOfRows - 1][col] == 'O') 
            {
                Q.push({noOfRows - 1, col});
                board[noOfRows - 1][col] = '-';
            }
        }

        while(!Q.empty())
        {
            int currRow = Q.front().first;
            int currCol = Q.front().second;
            Q.pop();

            for(int ind = 0; ind < dx.size(); ind++)
            {
                int nRow = currRow + dx[ind];
                int nCol = currCol + dy[ind];

                if(isInsideBoundary(nRow, nCol, noOfRows, noOfColumns, board))
                {
                    Q.push({nRow, nCol});
                    board[nRow][nCol] = '-';
                }
            }
        }

        for(int row = 0; row < noOfRows; row++)
        {
            for(int col = 0; col < noOfColumns; col++)
            {
                if(board[row][col] == '-') board[row][col] = 'O';

                else if(board[row][col] == 'O') board[row][col] = 'X';
            }
        }
    }
};
