/**
 * Title:  Kth Largest Element in a Stream (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, April, 2022
 */

class KthLargest {
private:
    int len;
    int largest;
    vector<int> stream;
public:
    KthLargest(int k, vector<int>& nums) {
        largest = k;
        sort(nums.begin(), nums.end());
        stream = nums;
        len = (int)stream.size();
    }
    
    int add(int val) {
        int index = bs(val, 0, len);
        stream.emplace_back(0);
        len = (int)stream.size();
        for (int i = len - 1; i > index; i--) {
            stream[i] = stream[i - 1];
        }
        stream[index] = val;
        return stream[len - largest];
    }
    
    int bs(int val, int l, int r) {
        if (l >= r)
            return l;
        int mid = (l + r) / 2;
        if (val == stream[mid])
            return mid;
        if (val < stream[mid])
            return bs(val, l, mid);
        return bs(val, mid + 1, r);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
