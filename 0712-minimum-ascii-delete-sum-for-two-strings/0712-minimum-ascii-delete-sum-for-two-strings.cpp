class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(), m=s2.length(), sum=0;
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	            if(s1[i-1]==s2[j-1]) dp[i][j]=(int)s1[i-1]+dp[i-1][j-1];
	            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
        for(int i=0; i<n; i++) sum+=(int)s1[i];
        for(int i=0; i<m; i++) sum+=(int)s2[i];
        return sum-2*dp[n][m];
    }
};