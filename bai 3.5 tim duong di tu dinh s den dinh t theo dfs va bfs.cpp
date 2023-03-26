#include <bits/stdc++.h>
using namespace std;

vector<int> ke[105];
bool visited[105];
int parent[105] = {};

void dfs(int u)
{
    visited[u] = true;
    for(auto x : ke[u])
    {
        if(!visited[x]) 
		{
			dfs(x);
			parent[x] = u;
		}
    }
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		for(auto x : ke[top])
		{
			if(!visited[x])
			{
				q.push(x);
				visited[x] = true;
				parent[x] = top;
			}
			
		}
	}
}

void path(int s, int t)
{
	int first = s, second = t;
	dfs(s);
	if(!visited[t])
	{
		cout << "no path";
		return;
	} 
	else
	{
		vector<int> road;
		while(s != t)
		{
			road.push_back(t);
			t = parent[t];
		}
		road.push_back(s);
		cout << "DFS path: ";
		for(auto x : road) cout << x << " ";
		cout << endl;
	}
	
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	s = first; t = second;
	
	bfs(s);
	if(!visited[t])
	{
		cout << "no path";
		return;
	} 
	else
	{
		vector<int> road;
		while(s != t)
		{
			road.push_back(t);
			t = parent[t];
		}
		road.push_back(s);
		cout << "BFS path: ";
		for(auto x : road) cout << x << " ";
	}
}


int main()
{
    int n; cin >> n;
    int s, t; cin >> s >> t;
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
    path(s, t);
}

