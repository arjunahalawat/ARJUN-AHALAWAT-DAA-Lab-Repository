#include <bits/stdc++.h>
using namespace std;
#define V 4
int shortestPath(int graph[V][V], int u, int v, int k)
{
   if (k == 0 && u == v)
    return 0;
   if (k == 1 && graph[u][v] != 0)
    return graph[u][v];
   if (k <= 0)
    return 0;
   int res = INT_MAX;
   for (int i = 0; i < V; i++)
   {
       if (graph[u][i] != 0 && u != i && v != i)
       {
           int rec_res = shortestPath(graph, i, v, k-1);
           if (rec_res != 0)
              res = min(res, graph[u][i] + rec_res);
       }
   }
   return res;
}
int main()
{
     int graph[V][V] = { {0, 10, 3, 2},
                        {0, 0, 0, 7},
                        {0, 0, 0, 6},
                        {0, 0, 0, 0}};
    int u = 0, v = 3, k = 2;
    cout << "Weight of the shortest path is " <<shortestPath(graph, u, v, k);
    return 0;
}
