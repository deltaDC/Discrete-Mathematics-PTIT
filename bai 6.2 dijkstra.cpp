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
vector<pair<ll, ll>> ke[105];
ll parent[105];

void dijkstra(ll s, ll t)
{
    vector<ll> d(n + 1, 1e9);
    d[s] = 0;
    parent[s] = s;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while(!q.empty())
    {
        pair<ll, ll> top = q.top();
        q.pop();
        ll kc = top.first, u = top.second;
        if(kc > d[u])
        {
            continue;
        } 
        //relax
        for(auto it : ke[u])
        {
            ll v = it.first, w = it.second;
            if(d[v] > d[u] + w) 
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
                parent[v] = u;
            }
        }
    }
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
            if(a[i][j] >= 1)
            {
                ke[i].push_back({j, a[i][j]});
                //ke[j].push_back({i, a[i][j]});
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        dijkstra(s, i);
    }
}
