//Given a pattern and a string str, find if str follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// str is split into words by spaces, uses two hashmaps to enforce a bijection


#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

static vector<string> splitBySpace(const string& s) {
    vector<string> out;
    size_t i = 0, n = s.size();
    while (i < n) {
        while (i < n && s[i] == ' ') ++i;       
        if (i == n) break;
        size_t j = i;
        while (j < n && s[j] != ' ') ++j;      
        out.emplace_back(s.substr(i, j - i));
        i = j;
    }
    return out;
}

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = splitBySpace(str);
        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> p2w;  
        unordered_map<string, char> w2p;  

        for (size_t i = 0; i < pattern.size(); ++i) {
            char p = pattern[i];
            const string& w = words[i];

            auto it1 = p2w.find(p);
            if (it1 != p2w.end()) {
                if (it1->second != w) return false;
            } else {
                p2w[p] = w;
            }

            auto it2 = w2p.find(w);
            if (it2 != w2p.end()) {
                if (it2->second != p) return false;
            } else {
                w2p[w] = p;
            }
        }
        return true;
    }
};

