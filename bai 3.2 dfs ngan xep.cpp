#include <bits/stdc++.h>
using namespace std;

vector<int> ke[15];
bool visited[15];

void stackDfs(int u)
{
    stack<int> st;
    st.push(u);
    while(!st.empty())
    {
        int topNode = st.top();
        st.pop();
        if(!visited[topNode])
        {
            visited[topNode] = true;
            cout << topNode << " ";
            sort(ke[topNode].begin(), ke[topNode].end());
            for(auto it = ke[topNode].rbegin(); it != ke[topNode].rend(); it++)
            {
                int x = *it;
                if(!visited[x]) st.push(x);
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
    stackDfs(1);
}
