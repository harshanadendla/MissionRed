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
const int N=1e5;
const int mod=1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        if(n%2)
        {
            if(k%2==0) cout<<"NO\n";
            else
            {
                if(k*k>n) cout<<"NO\n";
                else cout<<"YES\n";
            }
        }
        else
        {
            if(k%2) cout<<"NO\n";
            else
            {
                if(k*k>n) cout<<"NO\n";
                else cout<<"YES\n";
            }
        }
    }

    return 0;
}
