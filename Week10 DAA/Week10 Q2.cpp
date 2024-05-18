#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of intervals"<<endl;
    cin>>n;
    vector<int>start(n),deadline(n);
    cout<<"Enter start times of intervals"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }
    int maxDeadline=0;
    cout<<"Enter deadline of intervals"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>deadline[i];
        maxDeadline=max(maxDeadline,deadline[i]);
    }
    vector<pair<int,pair<int,int>>>intervals(n);
    for(int i=0;i<n;i++)
    {
        intervals[i]={deadline[i],{start[i],i+1}};
    }
    sort(intervals.begin(),intervals.end());
    vector<pair<int,pair<int,int>>>ans;
    //ans.push_back(intervals[0]);
    int currTime=0;
    for(int i=0;i<n;i++)
    {    if(currTime+intervals[i].second.first<=intervals[i].first)
        {
            ans.push_back(intervals[i]);
            currTime+=intervals[i].second.first;
        }
    }
    cout<<"Number of tasks possible is : "<<ans.size()<<endl;
    cout<<"Selected Tasks numbers is : ";
    for(auto x:ans)
    {
        cout<<x.second.second<<", ";
    }
    return 0;
}
