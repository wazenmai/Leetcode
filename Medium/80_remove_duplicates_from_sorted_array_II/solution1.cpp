/**
 * Title:  Remove Duplicates from Sorted Array II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   8, Feb, 2022
 */

class Solution {
public:
    void print_vec(vector<int>& num) {
        cout << " [";
        for (auto& e : num)
            cout << e << " ";
        cout << "]\n";
    }
    
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        int k = 0;
        int change = 1;
        unordered_map<int, int> hash_table;
        for (int i = 0; i < n; i++) {
            change = i + 1;
            // cout << i << "(" << nums[i] << "): (" << k << ", " << change << ") hash[" << nums[i] << "] = " << hash_table[nums[i]] << "\n";
            if (hash_table[nums[i]] < 2) {
                hash_table[nums[i]] += 1;
                k += 1;
            }
            else {
                while (change < n && hash_table[nums[change]] >= 2)
                    change++;
                if (change >= n)
                    break;
                int temp = nums[i];
                nums[i] = nums[change];
                nums[change] = temp;
                i = i - 1;
                // print_vec(nums);
            }
        }
        return k;
    }
};
