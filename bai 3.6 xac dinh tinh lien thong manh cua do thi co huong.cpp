#include <bits/stdc++.h>
using namespace std;

vector<int> ke[105];
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    for(auto x : ke[u])
    {
        if(!visited[x]) 
		{
			dfs(x);
		}
    }
}

int main()
{
    int n; cin >> n;
    int a[n + 1][n + 1];
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    //ma tran ke -> ds ke
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1)
            {
                ke[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
    	sort(ke[i].begin(), ke[i].end());
    	memset(visited, 0, sizeof(visited));
    	dfs(i);
    	for(int j = 1; j <= n; j++)
    	{
    		if(!visited[j])
    		{
    			cout << "not strongly connected";
    			return 0;
			}
		}
	}
	cout << "strongly connected";
	return 0;
}

