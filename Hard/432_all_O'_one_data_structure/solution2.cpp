/**
 * Title:  All O' one Data Structure (Leetcode Hard 432)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, September, 2024
 * Method: Use two pairs to store the string with min and max count. Use updateMin and updateMax to iterate through all the keys in map to find the min and max count.
 * Result: 68ms, beats 97.46% of C++ submissions
 */

class AllOne {
private:
    unordered_map<string, int> m;
    pair<string, int> _min{{}, 0}; // record string with min cnt
    pair<string, int> _max{{}, 0}; // record string with max cnt
public:
    AllOne() {}

    void updateMin() {
       _min.second = INT_MAX;
        for(auto & nd : m) {
            if(_min.second > nd.second) {
                _min.second = nd.second;
                _min.first = nd.first;
            }
        } 
    }

    void updateMax() {        
        _max.second = INT_MIN;
        for(auto & nd : m) {
            if(_max.second < nd.second) {
                _max.second = nd.second;
                _max.first = nd.first;
            }
        }
    }
    
    void inc(string key) {
        auto & v = m[key];
        ++v;
        if(v > _max.second) { // update max
            _max.second = v;
            _max.first = key;
        }
        if(key == _min.first) { // key may not be min cnt, fidn new min
            updateMin();
        }
        if(_min.second > v || _min.first.empty()) {
            _min.first = key;
            _min.second = v;
        }
    }
    
    void dec(string key) {
        m[key]--;
        if(m[key] == 0) m.erase(key);
        _min.first = _max.first = ""; // recalculate min and max
    }
    
    string getMaxKey() {
        if(!_max.first.empty()) return _max.first;
        updateMax();
        return _max.first;
    }
    
    string getMinKey() {
        if(!_min.first.empty()) return _min.first;
        updateMin();
        return _min.first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
