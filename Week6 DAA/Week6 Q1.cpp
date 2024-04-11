#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
void adj_list(list<int> adj[], int s, int d)
{
    adj[s].push_back(d);
}
bool dfs(list<int> adj[], int src, int dest, vector<int> &visited, vector<int> &path)
{
    stack<int> s;
    s.push(src);
    visited[src] = 1;

    while (!s.empty())
    {
        src = s.top();
        path.push_back(src);
        s.pop();

        if (src == dest)
            return true;

        for (auto a : adj[src])
        {
            if (visited[a] != 1)
            {
                visited[a] = 1;
                if (dfs(adj, a, dest, visited, path))
                    return true;
                else
                    path.pop_back();
            }
        }
    }
    return false;
}
int main()
{
    int v = 5;
    list<int> adj[v];
    vector<int>visited(v,0);
    adj_list(adj, 0, 1);
    adj_list(adj, 0, 3);
    adj_list(adj, 1, 4);
    adj_list(adj, 2, 1);
    adj_list(adj, 2, 3);
    adj_list(adj, 2, 4);
    adj_list(adj, 3, 1);
    adj_list(adj, 4, 3);
    int src,dest;
    cout<<"Enter the source node : ";
    cin>>src;
    cout<<"Enter the destination node : ";
    cin>>dest;
    vector<int>path;
    dfs(adj,src,dest,visited,path);
    if(visited[dest]!=1)
    {
        cout<<"No Such Path Exists"<<endl;
    }
    else
    {
        cout<<"Yes Path Exists : ";
        for(int i:path)
            cout<<i<<" ";
    }
    return 0;
}
