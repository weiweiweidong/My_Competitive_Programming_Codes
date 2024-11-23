# 001_Two Sum

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> h;
        for(int i = 0 ; i < nums.size() ; i++ ){
            int t = target - nums[i];
            if( h.count(t) ) return { h[t] , i };
            h[nums[i]] = i;
        }
        return {};
    }
};
```
