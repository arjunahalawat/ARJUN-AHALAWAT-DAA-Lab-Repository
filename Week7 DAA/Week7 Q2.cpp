#include <bits/stdc++.h>
using namespace std;

//only for the directed graph....if not then convert it into a directed graph
void adjList(list<pair<int, int>> adj[], int s, int d, int w)
{
    adj[s].push_back({d, w});
}

void createEdge(list<pair<int, int>> adj[], vector<vector<int>> &edge, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto a : adj[i])
        {
            int node = i;
            int adjNode = a.first;
            int weight = a.second;
            edge.push_back({node, adjNode, weight});
        }
    }
}


//only for the directed graph
vector<int>bellmanfordAlgo(vector<vector<int>>edge, int src,int v,vector<int>&dummyParent)
{
    vector<int>dis(v,INT_MAX);
    dis[src] = 0;
    for(int i=0;i<v-1;i++)
    {
        for(auto it:edge)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dis[u]!=INT_MAX&&dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                dummyParent[v]=u;
            }
        }
    }

    //Nth relaxation to check for the negative cycles
    for(auto it:edge)
    {
        int u=it[0];
        int v=it[1];
        int w=it[2];
        if (dis[u] != INT_MAX && dis[u] + w < dis[v])
        {
            cout<<"Negative edge cycles found"<<endl;
            return {-1};
        }
    }

    return dis;
}

void ultimateParent(vector<int>dummyParent,int node)
{
    if(dummyParent[node]==node)
    {
        cout<<node;
        return;
    }
    cout<<node<<" ";
    ultimateParent(dummyParent,dummyParent[node]);
}



int main()
{
    int v = 6;
    list<pair<int, int>> adj[v];
    vector<int> dis;
    vector<vector<int>>edge;

    // adding parent vector to calculate the path
    vector<int> dummyParent(v);
    for (int i = 0; i < v; i++)
        dummyParent[i] = i;

    adjList(adj,1,2,4);
    adjList(adj,1,3,1);
    adjList(adj,2,5,4);
    adjList(adj,3,2,2);
    adjList(adj,3,4,4);
    adjList(adj,4,5,4);

    createEdge(adj,edge,v);

    dis=bellmanfordAlgo(edge, 1,v,dummyParent);

    for(int i=1;i<v;i++)
    {
        ultimateParent(dummyParent,i);
        cout<<" : "<<dis[i]<<endl;
    }


    return 0;
}
