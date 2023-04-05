#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> ke[105];
bool visited[105];

vector<pair<int, int>> res1, res2;

void dfs(int u)
{
    visited[u] = true;
    for(auto x : ke[u])
    {
        if(!visited[x])
        {
            if(u < x) res1.push_back({u, x});
            else res1.push_back({x, u});
            dfs(x);
        }
    }
}

void bfs(int u)
{
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		for(auto x : ke[front])
		{
			if(!visited[x])
			{
				if(front < x) res2.push_back({front, x});
				else res2.push_back({x, front});
				q.push(x);
				visited[x] = true;
			}
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
    cout << "DFS tree\n";
    for(auto x : res1) cout << x.first << " " << x.second << endl;
    
    memset(visited, 0, sizeof(visited));
    bfs(start);
    cout << "BFS tree\n";
    for(auto x : res2) cout << x.first << " " << x.second << endl;
}
