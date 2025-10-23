class Solution {
public:
    int minAddToMakeValid(string s) {
        int total=0;
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push('(');
            else if(s[i]==')') 
            {
                if(st.empty()||st.top()!='(')
                total++;
                if(!st.empty())
                st.pop();
            }
        }
        return total+st.size();
    }
};