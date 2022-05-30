#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define forn for (int i = 0; i < n; i++)
#define srt(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define kk '\n'
using namespace std;

int longpath(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp)
{
    int n = mat.size();
    int m = mat[0].size();

    if (i < 0 or j < 0 or i >= n or j >= m)
    {
        return 0;
    }

    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }

    int curmax = 1;

    if (i + 1 < n and i + 1 >= 0 and mat[i + 1][j] > mat[i][j])
    {
        curmax = max(curmax, 1 + longpath(mat, i + 1, j, dp));
    }

    if (j + 1 < m and j + 1 >= 0 and mat[i][j + 1] > mat[i][j])
    {
        curmax = max(curmax, 1 + longpath(mat, i, j + 1, dp));
    }

    if (j - 1 < m and j - 1 >= 0 and mat[i][j - 1] > mat[i][j])
    {
        curmax = max(curmax, 1 + longpath(mat, i, j - 1, dp));
    }

    if (i - 1 < n and i - 1 >= 0 and mat[i - 1][j] > mat[i][j])
    {
        curmax = max(curmax, 1 + longpath(mat, i - 1, j, dp));
    }

    dp[i][j] = curmax;

    return curmax;
}
int longestIncreasingPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxi = max(maxi, longpath(mat,i,j,dp));
        }
    }

    return maxi;
}

int longestPath(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0 || i >= mat.size() || j > mat[0].size())

        return 0;

    if (dp[i][j] > 0)

        return dp[i][j];

    int currMax = 1;

    if (i + 1 < mat.size() && i + 1 >= 0 && mat[i + 1][j] > mat[i][j])
    {

        currMax = max(currMax, 1 + longestPath(mat, i + 1, j, dp));
    }

    if (j + 1 < mat[0].size() && j + 1 >= 0 && mat[i][j + 1] > mat[i][j])
    {

        currMax = max(currMax, 1 + longestPath(mat, i, j + 1, dp));
    }

    if (j - 1 < mat[0].size() && j - 1 >= 0 && mat[i][j - 1] > mat[i][j])
    {

        currMax = max(currMax, 1 + longestPath(mat, i, j - 1, dp));
    }

    if (i - 1 < mat.size() && i - 1 >= 0 && mat[i - 1][j] > mat[i][j])
    {

        currMax = max(currMax, 1 + longestPath(mat, i - 1, j, dp));
    }

    dp[i][j] = currMax;

    return currMax;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{ 

    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    int maks = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {

            maks = max(maks, longestPath(matrix, i, j, dp));
        }
    }

    return maks;
}
