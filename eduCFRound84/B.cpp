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
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5+1;
const int mod=1e9+7;

struct dt
{
    int m;
    set<int> kings;
}dtr[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t,a;
    cin>>t;
    
    while(t--)
    {
        int n,idx=LLONG_MAX,id=LLONG_MAX;
        cin>>n;

        bool d_vis[n+1],k_vis[n+1];

        for(int i=0;i<n+1;i++)
        {
            dtr[i].kings.clear();
            d_vis[i]=false;
            k_vis[i]=false;
        }

        for(int i=0;i<n;i++)
        {
            cin>>dtr[i].m;
            for(int j=0;j<dtr[i].m;j++)
            {
                cin>>a;
                dtr[i].kings.insert(a);
            }
            
            for(int it : dtr[i].kings)
            {
                if(!k_vis[it]) 
                {
                    d_vis[i]=true;
                    k_vis[it]=true;
                    break;
                }
            }

            if(d_vis[i]==false) idx=min(i,idx);
        }

        for(int i=1;i<=n;i++) 
        {
            if(k_vis[i]==false) 
            {
                id=i;
                break;
            }
        }

        if(idx==LLONG_MAX || id==LLONG_MAX) cout<<"OPTIMAL\n";
        else
        {
            cout<<"IMPROVE\n"<<idx+1<<" "<<id<<"\n";
        }
    }

    return 0;
}