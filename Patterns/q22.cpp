#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n; // Number of cities

void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("Nodes reachable from city %d: ", start);

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int isConnected() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = -1; // Reset queue
    enqueue(0);
    visited[0] = 1;

    while (front <= rear) {
        int v = dequeue();
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0; // Not connected
    }
    return 1; // Connected
}

int main() {
    int start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting city (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(start);

    if (isConnected())
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    printf("UID : 24BAI70438");

    return 0;
}