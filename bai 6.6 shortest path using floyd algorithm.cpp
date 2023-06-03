#include <iostream>
#include <vector>

using namespace std;

#define INF 99999

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V, INF));
    vector<vector<int>> next(V, vector<int>(V, -1));

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j) {
                next[i][j] = j;
            }
        }
    }

    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "K/c " << i + 1 << " -> " << j + 1 << " = " << dist[i][j] << ";  ";
            if (dist[i][j] != INF && i != j) {
                cout << i + 1;
                int current = i;
                while (current != j) {
                    current = next[current][j];
                    cout << " --> " << current + 1;
                }
            }else if(i==j) cout << i + 1;
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph, V);

    return 0;
}
