#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of intervals"<<endl;
    cin>>n;
    vector<int>start(n),end(n);
    cout<<"Enter start times of intervals"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }
    cout<<"Enter end times of intervals"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>end[i];
    }
    vector<pair<int,pair<int,int>>>intervals(n);
    for(int i=0;i<n;i++)
    {
        intervals[i]={end[i],{start[i],i+1}};
    }
    sort(intervals.begin(),intervals.end());
    vector<pair<int,pair<int,int>>>ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++)
    {
        auto back=ans.back();
        if(intervals[i].second.first>=back.first)
        {
            ans.push_back(intervals[i]);
        }
    }
    cout<<"Number of non-conflicting activities is : "<<ans.size()<<endl;
    cout<<"List of selected activities is : ";
    for(auto x:ans)
    {
        cout<<x.second.second<<", ";
    }
    return 0;
}
