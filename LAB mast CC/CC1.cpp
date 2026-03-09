class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {    
        long sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        int remainder = sum % p;
        if(remainder == 0)
            return 0;
        unordered_map<int,int> mp;
        mp[0] = -1;

        int prefix = 0;
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - remainder + p) % p;
            if(mp.find(need) != mp.end())
            {
                ans = min(ans, i - mp[need]);
            }
            mp[prefix] = i;
        }
        if(ans == nums.size())
            return -1;
        return ans;
    }
};