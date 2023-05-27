#include<iostream>

using namespace std;

int n, start;
int a[105][105], res[105];
bool visited[105];

void hamiltonianPath(int u)
{
    for(int i = 1; i <= n; i++)
    {
        //kiem tra xem dinh u co ke khong
        if(a[res[u - 1]][i])
        {
            //den dich
            if(u == n + 1 && i == start)
            {
                for(int j = 1; j <= n; j++) cout << res[j] << " ";
                cout << start << endl;
            }
            else if(!visited[i])
            {
                res[u] = i;
                visited[i] = true;
                hamiltonianPath(u + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n >> start;
    for(int i = 1; i <= n ;i++)
    {
        for(int j = 1; j <= n;j++)
        {
            cin >> a[i][j];
        }
    }
    res[1] = start;
    visited[start] = true;
    hamiltonianPath(2);
}
