class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size()));
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(i==0){ 
            int k=0,j=0;
            vector<int>temp;
            while(k<m && j<n)
            {
                temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            k=i,j=0;
            int p=0;
            while(k<m&& j<n)
            {
                v[k][j]=temp[p];
                p++;
                k++;
                j++;
            }
            }
            else{
               int k=i,j=0;
            vector<int>temp;
            while(k<m && j<n)
            {
                temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            k=i,j=0;
            int p=0;
            while(k<m&& j<n)
            {
                v[k][j]=temp[p];
                p++;
                k++;
                j++;
            }
            }
        }
        for(int i=1;i<n;i++)
        {
            int k=0,j=i;
            vector<int>temp1;
            while(k<m && j<n)
            {
                temp1.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(temp1.begin(),temp1.end());
            k=0,j=i;
            int p=0;
            while(k<m && j<n)
            {
                v[k][j]=temp1[p];
                p++;
                k++;
                j++;
            } 
        }
        return v;
    }
};