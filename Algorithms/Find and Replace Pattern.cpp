class Solution(
public:
    /**
     * @param words: word list
     * @param pattern: pattern string
     * @return: list of matching words
     */
    vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
        // Write your code here.
        vector<string> res;
        for (string w : words) if (F(w) == F(pattern)) res.push_back(w);
        return res;
    }

    string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
};
