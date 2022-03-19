/**
 * Title:  Maximum Frequency Stack (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, Mar, 2022
 * Method: Priority queue -> max heap -> frequency, add time, value
 */

class FreqStack {
private:
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> hash;
    int time;
public:
    FreqStack() {
        time = 0;
    }
    
    void push(int val) {
        hash[val] += 1;
        time += 1;
        pq.push(make_pair(hash[val], make_pair(time, val)));
    }
    
    int pop() {
        auto temp = pq.top();
        pq.pop();
        hash[temp.second.second]--;
        return temp.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
