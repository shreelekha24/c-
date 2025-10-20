class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> vis;
    queue<string> q;
    q.push(s);
    string smallest = s;
    vis.insert(s);
    
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        if (cur < smallest) smallest = cur;

        // Add operation on odd indices
        string add = cur;
        for (int i = 1; i < cur.size(); i += 2) {
            add[i] = ((add[i] - '0' + a) % 10) + '0';
        }
        if (!vis.count(add)) {
            vis.insert(add);
            q.push(add);
        }

        // Rotate operation
        string p = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
        if (!vis.count(p)) {
            vis.insert(p);
            q.push(p);
        }
    }
    return smallest;
}

};