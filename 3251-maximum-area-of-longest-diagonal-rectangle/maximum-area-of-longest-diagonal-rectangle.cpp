class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<int>ans;
        double p=0.0;
        int l,b;
        for(int i=0;i<dimensions.size();i++)
        {
            double d=sqrt(pow(dimensions[i][0],2)+pow(dimensions[i][1],2));
            if(p<=d){
            if(p==d)
            { 
                if(l*b<dimensions[i][0]*dimensions[i][1]){ 
            l=dimensions[i][0];
            b=dimensions[i][1];}
            }
            else{ 
            p=d;
            l=dimensions[i][0];
            b=dimensions[i][1];}
        }
        }
        int area=l*b;
        return area;
    }
};