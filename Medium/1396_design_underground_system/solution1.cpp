/**
 * Title:  Design Underground System (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, April, 2022
 */

class UndergroundSystem {
private:
    unordered_map<string, vector<int>> time;
    unordered_map<int, pair<string, int>> customer;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        customer[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        time[customer[id].first + "-" + stationName].emplace_back(t - customer[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = 0.0;
        string s = startStation + "-" + endStation;
        for (auto& x : time[s])
            sum += x;
        return sum / (double)time[s].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
