class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    string s = "";
    int i = 1;

    // Keep appending 'a' until it's at least as long as 'b'
    while (s.size() < b.size()) {
        s += a;
        i++;
    }

    // Check the current and one extra repetition (covers edge cases)
    if (s.find(b) != string::npos) return i - 1;
    s += a;
    if (s.find(b) != string::npos) return i;

    return -1; // not found
}

};