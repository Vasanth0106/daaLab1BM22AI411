//cpp program to calculate sum of subsets using backtracking
#include <iostream>
#include <vector>

bool foundSolution = false;

void findSubsets(const std::vector<int>& nums, int targetSum, int currentSum, int startIndex, std::vector<int>& currentSubset) {
    if (currentSum == targetSum) {
        std::cout << "Solution: ";
        for (int num : currentSubset) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        foundSolution = true;
        return;
    }

    if (startIndex >= nums.size() || currentSum > targetSum) {
        return;
    }

    // Include the current element
    currentSubset.push_back(nums[startIndex]);
    findSubsets(nums, targetSum, currentSum + nums[startIndex], startIndex + 1, currentSubset);
    currentSubset.pop_back();  // Backtrack

    // Exclude the current element
    findSubsets(nums, targetSum, currentSum, startIndex + 1, currentSubset);
}

void sumOfSubsets(const std::vector<int>& nums, int targetSum) {
    std::vector<int> currentSubset;
    findSubsets(nums, targetSum, 0, 0, currentSubset);

    if (!foundSolution) {
        std::cout << "No solution found." << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int targetSum;
    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;
    
    sumOfSubsets(nums, targetSum);
    
    return 0;
}
