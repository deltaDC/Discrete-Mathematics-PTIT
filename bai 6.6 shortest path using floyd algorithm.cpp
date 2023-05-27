#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m; 
int d[200][200];
int a[200][100];

void ktao()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			d[i][j] = a[i][j];
		}
	}
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
    	for(int j = 1; j <= n; j++)
    	{
    		cin >> a[i][j];
	}
    }
    ktao();
    for(int k = 1; k <= n; k++)
    {
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
    }
    for(int i = 1; i <= n; i++)
    {
	for(int j = 1; j <= n; j++)
	{
		cout << d[i][j] << " ";
	}
	cout << endl;
    }
}

