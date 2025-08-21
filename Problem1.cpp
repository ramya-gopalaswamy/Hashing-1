//Given an array of strings, group anagrams together.

// Using a hashmap, to store key (words sorted) and the anagrams as values,
// if key isnt present, an empty vector is created and we pushback the word


#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagram(vector<string>& strs) {
        unordered_map<string, vector<string>> map; 

        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];              
            sort(key.begin(), key.end());      
            map[key].push_back(strs[i]);   
        }

        vector<vector<string>> ans;           
        for (auto it = map.begin(); it != map.end(); ++it)
            ans.push_back(it->second);
        return ans;
    }
};
