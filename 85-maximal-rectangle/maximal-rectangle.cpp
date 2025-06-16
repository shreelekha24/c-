class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>pse(heights.size());
        stack<int>st;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        vector<int>nse(heights.size());
        stack<int>st1;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st1.empty() && heights[st1.top()]>heights[i])
            st1.pop();
            nse[i]=st1.empty()?heights.size():st1.top();
            st1.push(i);
        }
        int area=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int total=(nse[i]-pse[i]-1)*heights[i];
            area=max(area,total);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=INT_MIN;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            int area=largestRectangleArea(height);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};