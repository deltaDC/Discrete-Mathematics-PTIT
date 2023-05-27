#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define lim 10000005
#define MOD 1000000007
#define ll long long

#define faster() ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#define testcase() int t; cin >> t; while(t--)

ll n, m, s;
ll parent[105];

struct edge
{
    ll x, y, w;
};

vector<edge> dscanh;

void bellmanFord(ll s, ll t)
{
    vector<ll> d(n + 1, 1e9); //khoi tao kc giua cac dinh la +oo
    d[s] = 0; //kc tu dinh s -> s = 0
    parent[s] = s;
    //Bellman Ford
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto it : dscanh)
        {
            int u = it.x, v = it.y, w = it.w;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }
    //in theo yeu cau de bai
    cout << "K/c " << s << " -> " << t << " = ";
    if(d[t] == 1e9)
    {
        cout << "INF\n";
        return;  
    } 
    else cout << d[t]; 
    cout << ";        ";
    if(s == t)
    {
        cout << s << " <- " << t;
    }
    else
    {
        vector<ll> path;
        while(1)
        {
            path.push_back(t);
            if(t == s) break;
            t = parent[t];
            if(parent[t] == 0) break;
        }
        for(ll i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if(i != path.size() - 1) cout << " <- ";
        } 
    }
    cout << endl;
}

int main()
{   
    cin >> n >> s;
    ll a[105][105];
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            if(a[i][j] != 0)
            {
                edge temp{i, j, a[i][j]};
                dscanh.push_back(temp);
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        bellmanFord(s, i);
    }
}
