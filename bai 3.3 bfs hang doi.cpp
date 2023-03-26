#include <bits/stdc++.h>
using namespace std;

vector<int> ke[15];
bool visited[15];

void queueBFS(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		cout << front << " ";
		for(auto x : ke[front])
		{
			if(!visited[x])
			{
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main()
{
    int n; cin >> n; 
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 1) ke[i].push_back(j);
        }
    }
    queueBFS(1);
}
