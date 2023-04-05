#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge
{
    int dau, cuoi, trongso;
};

int n, m = 0;
vector<edge> canh;
int parent[105], sz[105];

//khoi tao 1 dinh là cha cua chinh no voi size = 1
void init()
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

//tim root cua 1 dinh
int find(int v)
{
    if(v = parent[v]) return v;
    return parent[v] = find(parent[v]);
}

//kiem tra chu trình
bool Union(int a, int b)
{
    //tim root
    a = find(a);
    b = find(b);
    //tao thanh chu trinh
    if(a == b) return 0;
    //noi 2 dinh
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return 1;
}

bool comp(edge a, edge b)
{
    if(a.trongso == b.trongso) return a.dau < b.dau;
    return a.trongso < b.trongso;
}

bool comp2(edge a, edge b)
{
    return a.dau < b.dau;
}

void kruskal()
{
    vector<edge> res;
    int d = 0;
    //sx trong so tang dan
    sort(canh.begin(), canh.end(), comp);
    for(int i = 0; i < m; i++)
    {
        if(res.size() == n - 1) break; //cay khung co n - 1 canh
        edge temp = canh[i];
        if(Union(temp.dau, temp.cuoi))
        {
            res.push_back(temp);
            d += temp.trongso;
        }
    }
    //sx ve dung form cua ds canh
    sort(res.begin(), res.end(), comp2);
    cout << "dH = " << d << endl;
    for(auto x : res)
    {
        cout << x.dau << "   " << x.cuoi << endl;
    }
}

int main()
{
    cin >> n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    //chuyen sang ds ke
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(a[i][j] >= 1)
            {
                m++;
                edge temp;
                temp.dau = i;
                temp.cuoi = j;
                temp.trongso = a[i][j];
                canh.push_back(temp);
            }
        }
    }
    init();
    kruskal();
}

