class Solution {
    public:
        vector<int> twoSum(vector<int>& a, int k) {
            int n = a.size();
            vector<int> vans;
            map<int, int> mp;
            for(int i = 0; i < n; i++) {
                if(mp.find(k - a[i]) != mp.end()) {
                    vans.push_back(mp[k - a[i]]);
                    vans.push_back(i);
                    break;
                } else {
                    mp[a[i]] = i;
                }
            }
            return vans;
        }
    };