#include <iostream>
#include <string>
using namespace std;
/**
 ** @param A, B: Two strings.
 ** @return: The length of longest common subsequence of A and B.
 **/
int longestCommonSubsequence(string A, string B) {
    if(A.empty()||B.empty()) return 0;
    int dp[A.length()+1][B.length()+1];
    memset(dp,0,sizeof(dp));
    int n = A.length();
    int m = B.length();
    int maxP = INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0; j<=m;j++ ){
            cout<< dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}
int main(){
    string A("ABCD");
    string B("EACB");
    cout<<longestCommonSubsequence(A,B)<<endl;
    return 0;
}
