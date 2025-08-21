//Given two strings s and t, determine if they are isomorphic.
//Using 2 hashmaps s->t and t->s, scan both strings for each pair (a,b) ensure existing mappings match or create new ones in both directions.


#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> s2t;  
        unordered_map<char, char> t2s;  
        

        for (size_t i = 0; i < s.size(); ++i) {
            char a = s[i], b = t[i];

            
            auto itST = s2t.find(a);
            if (itST != s2t.end()) {
                if (itST->second != b) return false;  
            } else {
                s2t[a] = b;
            }

          
            auto itTS = t2s.find(b);
            if (itTS != t2s.end()) {
                if (itTS->second != a) return false; 
            } else {
                t2s[b] = a;
            }
        }
        return true;
    }
};
