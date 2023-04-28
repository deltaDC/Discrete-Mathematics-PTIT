#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int u,check[1000],a[1000][1000],n;
vector<pair<int,int>> ve;

void dfs(int u)
{
	stack<int> s;
	check[u]=1;
	s.push(u);
	while(!s.empty())
	{
        int v = s.top();
        s.pop();
        for(int i = 1; i <= n; ++i)
        {
            if(!check[i] && a[v][i])
            {
            	int x1 = i, x2 = v;
            	if(x1 > x2) swap(x1, x2);
           		ve.push_back({x1, x2});
                s.push(v);
                s.push(i);
                check[i] = 1;
                break;
            }
        }
    }
}


void dfs()
{
    dfs(u);
    if(ve.size() < n - 1) cout << "No spanning tree";
    else 
    {
        cout << "Stack DFS tree" << endl;
        for(auto x : ve) cout << x.first << " " << x.second << endl;
    }
}
int main()
{
    cin >> n >> u;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1;j <= n; ++j) cin >> a[i][j];
    }
    dfs();
}
