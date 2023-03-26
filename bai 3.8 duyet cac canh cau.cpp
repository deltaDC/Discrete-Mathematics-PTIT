#include <bits/stdc++.h>
using namespace std;

#define lim 10000005
#define MOD 1000000007
#define ll long long

#define faster() ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#define testcase() int t; cin >> t; while(t--)

vector<int> ke[1005];
bool visited[1005];

void dfs(int u, int s, int t)
{
	visited[u] = true;
	for(auto x : ke[u])
	{
		if(x == s && u == t || x == t && u == s) continue;
		if(!visited[x])
		{
			dfs(x, s, t);
		}
	}
}

int main()
{  
	vector<int> v;
	vector<pair<int, int>> edge;
	vector<pair<int, int>> res;
	map<pair<int, int>, int> mp;
	memset(ke, 0, sizeof(ke));
	memset(visited, 0, sizeof(visited));
	int n; cin >> n;
	int a[n + 1][n + 1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 1)
			{
				ke[i].push_back(j);
				if(mp[{i, j}] == 0 && mp[{j, i}] == 0)
				{
					edge.push_back({i, j});
					mp[{i, j}]++;
					mp[{j, i}]++;
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			cnt++;
			dfs(i, 0, 0);
		}
	}
	int ans = 0;
	for(auto x : edge)
	{
		int u = x.first, v = x.second;
		int dem = 0;
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= n; i++)
		{
			if(!visited[i])
			{
				dem++;
				dfs(i, u, v);
			}
		}
		if(dem > cnt)
		{
			res.push_back({u, v});
		}
	}
	for(auto x : res)
	{
		cout << x.first << " " << x.second << endl;
	} 
}

 







