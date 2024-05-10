/**
 * Title:  K-th Smallest Prime Fraction (Leetcode Medium 786)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, May, 2024
 * Method: Use priority queue to first store every element devide by the last element in array, then pop the top element and push the next bigger element with same numerator k times.
 *         Since it is max heap by default so we need to store the negative value of fraction.
 * Result: Time complexity O((n+k)logn), space complexity O(n), m = maximum value in array
 */

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        int n = arr.size();
        // All index with last index
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(-1.0 * arr[i] / arr.back(), make_pair(i, n - 1)));
        }
        while (--k > 0) {
            auto cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push(make_pair(-1.0 * arr[cur.first] / arr[cur.second], make_pair(cur.first, cur.second)));
        }
        // Retrieve the kth smallest fraction from top of priority queue
        return vector<int>{arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};

// Time complexity O((n + k)logn)
    // initialize O(nlogn)
    // remove and replace O(klogn)
    // retrieve kth smallest fraction O(logn)
// Space complexity O(n)
