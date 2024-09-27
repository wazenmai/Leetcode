/**
 * Title:  My Calendar II (Leetcode Medium 731)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, September, 2024
 */

class MyCalendarTwo {
private:
    vector<pair<int, int>> v1; // first book
    vector<pair<int, int>> v2; // double book
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        // first check v2
        for (auto& p: v2) {
            if (p.second <= start || p.first >= end) continue;
            return false;
        }
        // pass check, add in v1
        for (auto& p: v1) {
            if (p.second <= start || p.first >= end) continue;
            int s = max(start, p.first);
            int e = min(end, p.second);
            v2.emplace_back(make_pair(s, e));
        }
        v1.emplace_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
