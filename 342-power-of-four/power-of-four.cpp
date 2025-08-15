class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int i=0;
        while(true)
        {
            if(pow(4,i)==n) return true;
            if(pow(4,i)>n) return false;
            i++;
        }
        return false;
    }
};