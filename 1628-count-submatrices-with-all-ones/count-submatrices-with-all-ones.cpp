class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>>row(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++)
        {
            row[i][0]=mat[i][0];
            for(int j=1;j<mat[0].size();j++)
            {
                if(mat[i][j]!=0)
                {
                    row[i][j]=row[i][j-1]+1;
                }
            }
        }
        long long count=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0) continue;
                int mini=row[i][j];
                for(int k=i;k>=0 && row[k][j]>0;k--)
                {
                    mini=min(mini,row[k][j]);
                    count+=mini;
                }
            }
        }
        return count;
    }
};