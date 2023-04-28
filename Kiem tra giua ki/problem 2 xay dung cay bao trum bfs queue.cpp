#include<iostream> 
#include<vector> 
#include<stack> 
#include<queue>

using namespace std;

int check1[1000], check2[1000], n, u, a[1000][1000];
vector<pair<int, int>> vp1, vp2;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    check2[u] = 1;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int i = 1; i <= n; ++i)
        {
            if(a[s][i] && !check2[i])
            {
                int x1 = s, x2 = i;
                if(x1 > x2) swap(x1, x2);
                vp2.push_back({x1, x2});
                q.push(i);
                check2[i] = 1;
            }
        }
    }
}

void BFS()
{
    bfs(u);
    if(vp2.size() < n - 1) cout << "No spanning tree";
    else 
    {
        cout << "Queue BFS tree" << endl;
        for(auto x : vp2) cout << x.first << " " << x.second << endl;
    }
}
int main()
{
    cin >> n >> u;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    BFS();
}
