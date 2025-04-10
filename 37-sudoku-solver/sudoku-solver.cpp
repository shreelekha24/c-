class Solution {
public:
bool solve(vector<vector<char>>&board)
{
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            if(board[i][j]=='.')
            {
                for(char k='1';k<='9';k++)
                {
                    if(safe(board,i,j,k)){
                    board[i][j]=k;
                    if(solve(board))
                     return true;
                     else
                     board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool safe(vector<vector<char>>&board,int row,int col,char c)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)
        return false;
        if(board[row][i]==c)
        return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
        return false;
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
    }
};