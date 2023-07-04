class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), l=p.length();
        vector<int> ans;
        if(n<l) return ans;
        vector<int> window(26,0), freq_p(26, 0);
        for(int i=0;i<l;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if(freq_p == window) ans.push_back(0);
        for(int i=l; i<n; i++){
            window[s[i-l] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-l+1);
        }
        return ans;
    }
};