/**
 * Title:  Seat Reservation Manager(Leetcode Medium 1845)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, November, 2023
 * Result: Time complexity O(nlogn), Space complexity O(n)
 */

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // empty seats
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            pq.push(i);
    }
    
    int reserve() {
        int temp = pq.top();
        pq.pop();
        return temp;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
