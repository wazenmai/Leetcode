/**
 * Title:  Smallest String with Swaps (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, April, 2022
 * Finding: pairs (a, b) (a, c) means that we also have (a, c). -> find connected pairs (indices).
 * Method: Construct a graph of indices from pairs, dfs all indices and memrize characters and indices, sort them and assign the value. O(V + ElogE)
 */

class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visited;
public:
    void dfs(string& s, int id, vector<char>& characters, vector<int>& indices) {
        characters.emplace_back(s[id]);
        indices.emplace_back(id);
        visited[id] = true;
        
        for (int nb: graph[id]) {
            if (!visited[nb])
                dfs(s, nb, characters, indices);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = (int)pairs.size();
        int l = s.length();
        
        graph.clear();
        graph.resize(l);
        
        visited.resize(l);
        
        for (int i = 0; i < l; i++)
            visited[i] = false;
        
        for (auto& pair: pairs) {
            graph[pair[0]].emplace_back(pair[1]);
            graph[pair[1]].emplace_back(pair[0]);
        }
        
        vector<char> characters;
        vector<int> indices;
        
        for (int i = 0; i < s.length(); i++) {
            if (!visited[i]) {
                
                dfs(s, i, characters, indices);
                
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());
                
                // print
                // for (int j = 0; j < (int)characters.size(); j++) {
                //     cout << indices[j] << ": " << characters[j] << endl; 
                // }
                
                // now we have characters and indices on connected graph
                for (int j = 0; j < (int)characters.size(); j++) {
                    s[indices[j]] = characters[j];
                }
                characters.clear();
                indices.clear();
            }
        }
       return s;
    }
};
