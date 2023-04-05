#include <iostream>
#include <vector>
using namespace std;

vector<int> ke[105];
bool visited[105];

vector<pair<int, int>> res;

void dfs(int u)
{
    visited[u] = true;
    for(auto x : ke[u])
    {
        if(!visited[x])
        {
            if(u < x) res.push_back({u, x});
            else res.push_back({x, u});
            dfs(x);
        }
    }
}

int main()
{
    int n; cin >> n;
    int start; cin >> start;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1)
            {
                ke[i].push_back(j);
            }
        }
    }
    dfs(start);
    for(auto x : res) cout << x.first << " " << x.second << endl;
}
