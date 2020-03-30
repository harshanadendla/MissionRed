#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int n,y;
    cin>>n;

    vector<int> a(2*n+1);
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    y=a[2*n];
    int area1=(a[2*n]-a[n+1])*(a[n]-a[1]);

    for(int i=2;i<=n;i++)
    {
        y=min(y,a[i+n-1]-a[i]);
    }

    int area2=(a[2*n]-a[1])*y;

    cout<<min(area1,area2);
    return 0;
}