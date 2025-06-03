class Solution {
public:
void solve(string& word, int k)
{
    if(word.size()>=k)
    return;
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(word[i]=='z')
        word+='a';
        else
        word+=char(word[i]+1);
    }
   solve(word,k);
}
char kthCharacter(int k) {
    string word="a";
    solve(word,k);
    return word[k-1];
    }
};