/**
 * Title:  My Calendar I (Leetcode Medium 729)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, September, 2024
 */

class MyCalendar {
private:
    vector<pair<int, int>> v; // start, end
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto& p: v) {
            if (p.second <= start || p.first >= end) continue;
            return false;
        }
        v.emplace_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */