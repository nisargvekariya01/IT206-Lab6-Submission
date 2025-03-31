class Solution {
    public:
        vector<int> topKFrequent(vector<int>& v, int k) {
            int n = v.size();
            map<int, int> mp;
            for(int i = 0; i < n; i++) {
                if(mp.find(v[i]) != mp.end()) {
                    mp[v[i]]++;
                } else {
                    mp[v[i]] = 1;
                }
            }
    
            map<int, queue<int>> mpans;
            for(map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) {
                mpans[itr->second].push(itr->first);
            }
    
            vector<int> ans(k);
            int idx = 0;
            map<int, queue<int>>::iterator itr = mpans.end();
            itr--;
            for(; idx <= k-1; itr--, idx++) {
                if(itr->second.size() == 1) {
                    ans[idx] = itr->second.front();
                    itr->second.pop();
                } else {
                    while(idx <= k-1 && itr->second.size() != 0) {
                        ans[idx] = itr->second.front();
                        itr->second.pop();
                        idx++;
                    }
                    idx--;
                }
            }
            return ans;
        }
    };