class Solution {
  public:
  
    int f(int i, int j, string& s1, int count,  string& s2) {
        if(i==s1.length() || j==s2.length()) return count;
        if(s1[i]==s2[j]) return f(i+1,j+1, s1,count+1,s2);
        else return max(count, max(f(i+1,j,s1,0,s2), f(i,j+1,s1,0,s2)));
    }
    
    int longCommSubstr(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1,0));
        int count=0, maxx=0;
        for(int i=1; i<=s1.size(); i++) {
            for(int j=1; j<=s2.size(); j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                    maxx = max(maxx, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxx;
    }
};