#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
// adjacency list for undirected graph
void adj_list(list<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}
bool isBipartite(list<int>adj[],int src,int v)
{
    vector<int>color(v,-1);
    queue<int>q;
    q.push(src);
    color[src]=0;
    while(!q.empty())
    {
        src=q.front();
        q.pop();
        for(auto a:adj[src])
        {
            if(color[a]==-1)
            {
                color[a]=1-color[src];
                q.push(a);
            }
            else if(color[a]==color[src])
                return false;
        }
    }
    return true;
}
int main()
{
    int v = 9;
    list<int> adj[v];

    adj_list(adj, 1, 2);
    adj_list(adj, 2, 3);
    adj_list(adj, 2, 6);
    adj_list(adj, 3, 4);
    adj_list(adj, 4, 5);
    adj_list(adj, 4, 7);
    adj_list(adj, 5, 6);
    adj_list(adj, 7, 8);

    if(isBipartite(adj, 1, v))
        cout<<"Yes Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;
    return 0;
}
