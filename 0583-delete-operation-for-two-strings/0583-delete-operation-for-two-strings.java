class Solution {
    public int minDistance(String word1, String word2) {
        int n=word1.length(), m=word2.length();
        int[][] lcs=new int[n+1][m+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)) lcs[i][j]=1+lcs[i-1][j-1];
                else lcs[i][j]=Math.max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        return n+m-2*lcs[n][m];
    }
}