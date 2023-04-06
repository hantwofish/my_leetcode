    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[i]));
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }

作者：Ikaruga
链接：https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solutions/230223/longest-continuous-subarray-by-ikaruga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solutions/612773/he-gua-de-shu-ju-jie-gou-hua-dong-chuang-v46j/