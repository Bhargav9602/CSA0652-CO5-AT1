#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int n;
int set[MAX];
int maxCut = 0;

// Count current cut edges
int calculateCut()
{
    int cut = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(graph[i][j] == 1 && set[i] != set[j])
                cut++;
        }
    }

    return cut;
}

// Backtracking function
void maxCutBacktracking(int vertex)
{
    if(vertex == n)
    {
        int cut = calculateCut();

        if(cut > maxCut)
            maxCut = cut;

        return;
    }

    // Put vertex in Set A
    set[vertex] = 0;
    maxCutBacktracking(vertex + 1);

    // Put vertex in Set B
    set[vertex] = 1;
    maxCutBacktracking(vertex + 1);
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    maxCutBacktracking(0);

    printf("\nMaximum Cut = %d\n", maxCut);

    return 0;
}
