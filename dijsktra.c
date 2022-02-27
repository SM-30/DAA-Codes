#include<stdio.h>
#include<conio.h>
#define INTMAX 99999
int i,j,n;
void Dijkstra(int gp [][n], int);
int main()
{
    int x,y,z,s;
    char ch;
    printf("Enter the number of edges: ");
    scanf("%d", &n);
    int adjmat[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        adjmat[i][j] = 0;
    }
    printf("Enter the graph\n");
    ch = 'y';
    while(ch != 'n')
    {
        printf("Enter the parent node, child node and the distance between them\n");
        scanf("%d %d %d", &x, &y, &z);
        fflush(stdin);
        adjmat[x][y] = z;
        printf("Want to enter another node ?(y/n): ");
        scanf("%c", &ch);
    }
    printf("\nEnter the source:\n");
    scanf("%d", &s);
    Dijkstra(adjmat, s);
    return 0;
}
void Dijkstra(int gp[n][n], int start)
{
    int cs[n][n], dist[n], pred[n], visit[n], x = 1, mindist, next;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(gp[i][j] == 0)
            cs[i][j] = INTMAX;
            else
            cs[i][j] = gp[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        dist[i] = cs[start][i];
        pred[i] = start;
        visit[i] = 0;
    }
    dist[start] = 0;
    visit[start] = 1;
    while(x < n - 1)
    {
        mindist = INTMAX;
        for(i=0; i<n; i++)
        {
            if(dist[i] < mindist && visit[i] == 0)
            {
                mindist = dist[i];
                next = i;
            }
        }
        visit[next] = 1;
        for(i=0; i<n; i++)
        {
            if(visit[i] == 0)
            {
                if(mindist + cs[next][i] < dist[i])
                {
                    dist[i] = mindist + cs[next][i];
                    pred[i] = next;
                }
            }
        }
        x++;
    }
    printf("Vertex \t\t Distance from source %d\n", start);
    for(i=0; i<n; i++)
    {
        if(i != start)
        printf("%d \t\t %d\n", i, dist[i]);
    }
}