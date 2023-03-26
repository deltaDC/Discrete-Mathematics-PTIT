#include <bits/stdc++.h>
using namespace std;

#define lim 10000005
#define MOD 1000000007
#define ll long long

#define faster() ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#define testcase() int t; cin >> t; while(t--)

vector<int> ke[1005];
bool visited[1005];

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
	vector<int> v;
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
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			cnt++;
			dfs(i);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		visited[i] = true;
		int dem = 0; 
		for(int j = 1; j <= n; j++)
		{
			if(!visited[j])
			{
				dfs(j);
				dem++;
			}
		}
		if(dem > cnt)
		{
			ans++;
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	for(auto x : v) cout << x << " ";
	cout << endl;
}

 







