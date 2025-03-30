class Solution {
public:
void display(int col,vector<vector<string>>&v,vector<string>&temp,vector<int>&leftrow,vector<int>&uld,vector<int>&lld,int n)
{
    if(col==n)
    {
        v.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(leftrow[row]==0 && uld[n-1+col-row]==0 && lld[col+row]==0)
        {
            temp[row][col]='Q';
            leftrow[row]=1;
            uld[n-1+col-row]=1;
            lld[col+row]=1;
            display(col+1,v,temp,leftrow,uld,lld,n);
            temp[row][col]='.';
            leftrow[row]=0;
            uld[n-1+col-row]=0;
            lld[col+row]=0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> v;
    vector<string> temp(n, string(n, '.'));
    vector<int>leftrow(n,0);
    vector<int>uld(2*n-1,0);
    vector<int>lld(2*n-1,0);
    display(0, v, temp,leftrow,uld,lld,n);
    return v;
}
};