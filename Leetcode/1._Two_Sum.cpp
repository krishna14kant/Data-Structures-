// Two Sum LeetCode Solution

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash_map;
        std::vector<int> result;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement is in the hash map
            auto it = hash_map.find(complement);
            if (it != hash_map.end()) {
                // Found a pair that sums to the target
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }

            // Store the current number and its index in the hash map
            hash_map[nums[i]] = i;
        }

        return result; // Return an empty vector if no solution is found
    }
};
