#include <bits/stdc++.h>
using namespace std;

#define lim 10000005
#define MOD 1000000007
#define ll long long

#define faster() ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#define testcase() int t; cin >> t; while(t--)

set<int> ke[1005];
bool visited[1005];

void euler(int v)
{
	stack<int> st;
	vector<int> EC;
	st.push(v);
	while(!st.empty())
	{
		int x = st.top();
		if(ke[x].size() != 0)
		{
			int y = *ke[x].begin();
			st.push(y);
			ke[x].erase(y);
			ke[y].erase(x);
		}
		else
		{
			st.pop();
			EC.push_back(x);
		}
	}
	reverse(EC.begin(), EC.end());
	for(auto x : EC) cout << x << " ";
}

int main()
{  
	int n; cin >> n;
	int u; cin >> u;
	int a[n + 1][n + 1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 1)
			{
				ke[i].insert(j);
				ke[j].insert(i);
			}
		}
	}
	euler(u);
}

 







