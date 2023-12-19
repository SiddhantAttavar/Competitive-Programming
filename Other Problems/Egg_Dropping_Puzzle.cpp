//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) {
        swap(n, k);
        vector<vector<int>> dp(n + 1, vector<int>(k, 1e9));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < k; j++) {
            dp[0][j] = 0;
        }
        
        for (int j = 1; j < k; j++) {
            for (int i = 1; i <= n; i++) {
                int l = 1, r = i, x = 1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (dp[i - m][j] <= dp[m - 1][j - 1]) {
                        x = m;
                        r = m - 1;
                    }
                    else {
                        l = m + 1;
                    }
                }
                dp[i][j] = min(dp[i][j - 1], max(dp[i - x][j], dp[x - 1][j - 1]) + 1);
                if (x > 1) {
                    dp[i][j] = min(dp[i][j], max(dp[i - x + 1][j], dp[x - 2][j - 1]) + 1);
                }
            }
        }
        
        return dp[n][k - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
