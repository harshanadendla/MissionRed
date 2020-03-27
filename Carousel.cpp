#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

void solve()
{
    bool flag1=true,flag2=false;
    int n;
    cin>>n;

    int a[n];
    cin>>a[0];
    for(int i=1;i<n;i++) 
    {
        cin>>a[i];
        if(a[i]!=a[0]) 
        {
            flag1=false;
        }
        if(a[i]==a[i-1]) flag2=true;
    }

    if(a[0]==a[n-1]) flag2=true;

    if(flag1)
    {
        cout<<"1\n";
        for(int i=0;i<n;i++) cout<<"1 ";
        cout<<"\n";
        return ;
    }

    if(n%2==0)
    {
        cout<<"2\n";
        for(int i=0;i<n;i++)
        {
            if(i%2) cout<<"2 ";
            else cout<<"1 ";
        }
        cout<<"\n";
    }
    else
    {
        if(flag2)
        {
            cout<<"2\n1 ";
            int c=1;
            for(int i=1;i<n;i++)
            {
                if(a[i]==a[i-1] && flag2) 
                {
                    cout<<c<<" ";
                    flag2=false;
                }
                else
                {
                    c=3-c;
                    cout<<c<<" ";
                }
            }
            cout<<"\n";
        }
        else
        {
            cout<<"3\n";
            for(int i=0;i<n-1;i++)
            {
                if(i%2) cout<<"2 ";
                else cout<<"1 ";
            }
            cout<<"3\n";
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}