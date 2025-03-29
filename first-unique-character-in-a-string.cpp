class Solution {
    public:
        int firstUniqChar(string s) {
            int n = s.size();
            map<char, pair<int, int>> mp;
            for(int i = 0; i < n; i++) {
                if(mp.find(s[i]) != mp.end()) {
                    pair<int, int>& t = mp[s[i]];
                    t.second += 1;
                } else {
                    mp[s[i]] = {i, 1};
                }
            }
            int ans = INT_MAX;
            for(map<char, pair<int, int>>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
                pair<int, int>& t = itr->second;
                if(t.second == 1) {
                    ans = min(ans, t.first);
                }
            }
            if(ans == INT_MAX) {
                ans = -1;
            }
            return ans;
        }
    };