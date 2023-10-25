#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }
        std::cout << numMap[5] << std::endl;
        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return { i, numMap[complement] };
            }
        }
        return {}; // No solution found
    }
};
void arryAsString(std::vector<int> array) {
    std::cout << "[ ";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i];
        if (i == (array.size() - 1)) {
            break;
        }
        std::cout << " ,";
    }
    std::cout << " ]" << std::endl;
}
int main(){
    Solution s{};
    std::vector array{ 1,2,3,5,6,5 };
    arryAsString(s.twoSum(array, 10));
}
