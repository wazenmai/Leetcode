/**
 * Title:  Kth Largest Element in a Stream (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, April, 2022
 * Method: Use min heap to maintain k largest element.
 */

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int largest;
public:
    KthLargest(int k, vector<int>& nums) {
        largest = k;
        for (auto& x : nums)
            pq.push(x);
        while (pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > largest)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
