#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

int maxSubsequenceSum(const std::vector<int>& nums, int m) {
    int n = nums.size();
    std::vector<int> prefixSum(n + 1, 0);

    
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

   
    std::deque<int> dq;
    int maxSum = INT_MIN;

    for (int i = 0; i <= n; ++i) {
       
        if (!dq.empty() && dq.front() < i - m) {
            dq.pop_front();
        }

        
        if (!dq.empty()) {
            maxSum = std::max(maxSum, prefixSum[i] - prefixSum[dq.front()]);
        }

      
        while (!dq.empty() && prefixSum[dq.back()] >= prefixSum[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return maxSum;
}

int main() {
    std::vector<int> nums;
    int m,n,ipt;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&ipt),nums.push_back(ipt);
    std::cout << maxSubsequenceSum(nums, m) << std::endl;
    return 0;
}
