class Solution {
    public:
        int longestConsecutive(vector<int>& a) {
            int n = a.size();
            map<int, int> mp;
            for(int i = 0; i < n; i++) {
                mp[a[i]] = 1;
            }
            int ans = 0;
            for(map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
                if(mp.find(itr->first - 1) != mp.end()) {
                    itr->second = mp.find(itr->first - 1)->second + 1;
                }
                ans = max(ans, itr->second);
            }
            return ans;
        }
    };