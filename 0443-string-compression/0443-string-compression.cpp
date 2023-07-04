class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ans=0, n=chars.size();
        if(n==1) return 1;
        while(i<n)
        {
            int j = i + 1;
            while(j<n && chars[i] == chars[j]) j++;
            chars[ans] = chars[i];
            ans++;
            if(j-i > 1){
                string s = to_string(j-i);
                for(char c : s)
                {
                    chars[ans] = c;
                    ans++;
                }
            }
            i = j ;
        }
        return ans;
    }
};