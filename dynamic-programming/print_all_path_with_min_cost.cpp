#include <bits/stdc++.h>
using namespace std;

char path(pair<int, int> ini, pair<int, int> fin)
{
    if (ini.first == fin.first)
        return 'H';
    else
        return 'V';
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = arr[i][j] + dp[i][j + 1];
            }
            else if (j == m - 1)
            {
                dp[i][j] = arr[i][j] + dp[i + 1][j];
            }
            else
            {
                dp[i][j] = arr[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    queue<pair<string, pair<int, int>>> q;
    q.push({"", {0, 0}});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr.second.first==n-1 && curr.second.second == m-1)
        {
            cout << curr.first << endl;
            continue;
        }
        int newx = curr.second.first, newy = curr.second.second;
        if (newx == n - 1)
        {
            q.push({curr.first + 'H', make_pair(newx, newy+1)});
        }
        else if (newy == m - 1)
        {
            q.push({curr.first + 'V', make_pair(newx+1, newy)});
        }
        else
        {
            int mini = min(dp[newx + 1][newy], dp[newx][newy + 1]);
            if (dp[newx + 1][newy] == mini)
            {
                q.push({curr.first + 'V', make_pair(newx + 1, newy)});
            }
            if (dp[newx][newy + 1] == mini)
            {
                q.push({curr.first + 'H', make_pair(newx, newy + 1)});
            }
        }
        // cout << "working" << endl;
    }

    return 0;
}