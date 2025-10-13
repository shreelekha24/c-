class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int j=0;
        vector<string>v;
        v.push_back(words[0]);
       for(int i=1;i<words.size();i++)
       {
        string p=words[i];
        sort(p.begin(),p.end());
        string t=words[j];
        sort(t.begin(),t.end());
        if(p==t)
        {
            continue;
        }
        else {
            v.push_back(words[i]);
            j=i;
        }
       }
       return v;
    }
};