#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>

/*
13
1
0 0 6 0 6 0 6 4 4 4 0 0 1
0 0 8 0 0 8 8 0 0 0 1 0 0
6 8 0 8 6 8 6 0 0 0 0 0 0
0 0 8 0 8 8 0 0 0 0 0 0 0
6 0 6 8 0 0 0 0 0 6 0 0 0
0 8 8 8 0 0 0 0 0 0 0 0 0
6 8 6 0 0 0 0 6 0 1 0 0 0
4 0 0 0 0 0 6 0 4 0 0 4 0
4 0 0 0 0 0 0 4 0 4 2 2 1
4 0 0 0 6 0 1 0 4 0 4 0 0
0 1 0 0 0 0 0 0 2 4 0 0 2
0 0 0 0 0 0 0 4 2 0 0 0 9
1 0 0 0 0 0 0 0 1 0 2 9 0
*/

using namespace std;

int n;

struct canh {
    int dau, cuoi, trongso;  
};

bool used[105];
vector<pair<int, int>> ke[105];

void prim(int u)
{
    vector<canh> mst; //luu cay khung
    int d = 0; //chieu dai cay khung
    used[u] = true; //loai u ra khoi V hay used
    //xay dung cay khung
    while(mst.size() < n - 1)
    {
        int min_w = INT_MAX;
        int X, Y; //luu 2 dinh co trong so be nhat
        //tim canh co trong so be nhat
        for(int i = 1; i <= n; i++)
        {
            //neu dinh i da thuoc cay khung
            if(used[i])
            {
                //duyet ds ke cua dinh i
                for(pair<int, int> it : ke[i])
                {
                    int j = it.first;
                    int trongso = it.second;
                    if(!used[j] && trongso < min_w)
                    {
                        min_w = trongso;
                        X = j; Y = i; //luu lai canh co trong so be nhat
                    }
                }
            }
        }
        mst.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true; //danh dau X da thuoc cay khung
    }
    
    cout << "dH = " << d << endl;
    for(canh x : mst)
    {
        if(x.dau < x.cuoi) cout << x.dau << " " << x.cuoi << endl;
        else cout << x.cuoi << " " << x.dau << endl;
    }
}

int main()
{
    int start; cin >> n >> start;
    int a[n + 1][n + 1];
    //chuyen sang ds ke
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] >= 1)
            {
                ke[i].push_back({j, a[i][j]});
            }
        }
    }
    prim(start);
}
