#include <iostream>
#include <stdlib.h>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front = 0, rear = 0, v;
int visit[10] = {0}, visited[10] = {0};
int stk[10], top = 0, visit1[10] = {0}, visited1[10] = {0};

int main() {
    int m;
    cout << "Enter no. of vertices : ";
    cin >> n;

    cout << "Enter no. of edges : ";
    cin >> m;

    cout << "EDGES" << endl;
    for (k = 1; k <= m; k++) {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    cout << "The adjacency matrix of the graph is" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    cout << "Enter initial vertex for BFS : ";
    cin >> v;

    cout << "The BFS of the Graph is : " << endl;
    cout << v << " ";
    visited[v] = 1;
    k = 1;

    while (k < n) {
        for (j = 1; j <= n; j++) {
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1) {
                visit[j] = 1;
                qu[rear++] = j;
            }
        }
        v = qu[front++];
        cout << v << " ";
        k++;

        visit[v] = 0;
        visited[v] = 1;
    }

    cout << endl << "Enter initial vertex for DFS : ";
    cin >> v;

    cout << "The DFS of the Graph is" << endl;
    cout << v << " ";
    visited[v] = 1;
    k = 1;

    while (k < n) {
        for (j = n; j >= 1; j--) {
            if (cost[v][j] != 0 && visited1[j] != 1 && visit1[j] != 1) {
                visit1[j] = 1;
                stk[top] = j;
                top++;
            }
        }
        v = stk[--top];
        cout << v << " ";
        k++;
        visit1[v] = 0;
        visited1[v] = 1;
    }

    cout << endl;
    return 0;
}
