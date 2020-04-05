//baboi....pindesindi...easy sum..implementation konchem ....konchem tough

/*
    YES PAIN YES GAIN
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T> using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define unmap unordered_map
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

const int N=1e5;
const int M=3e5;
const int mod=1e9+7;

struct team
{
    int rating;
    string name;
};

void solve()
{
    vector<vector<team>> ans;
    vi indices(4);

    string t;
    int n,m,s,x,a,b,c,rating;
    cin>>n;

    vector<team> teams(n);
    s=m=n/4;
    cin>>x>>a>>b>>c;

    for(int i=0;i<n;i++)
    {
        cin>>teams[i].name>>teams[i].rating;
    }

    sort(all(teams),[](team a,team b){return a.rating>b.rating;});


    while(s>1)
    {
        vector<team> tms;
        for(int i=0;i<4;i++)
        {
            int y=(x*a+b)%c;
            x=y;
            int idx=s*i+y%s;
            indices[i]=idx;
            tms.pb(teams[idx]);
        }

        ans.pb(tms);
        for(int i=0;i<4;i++) teams.erase(teams.begin()+indices[i]-i);
        s--;
    }
    ans.pb(teams);

    for(int i=0;i<ans.size();i++)
    {
        sort(all(ans[i]),[](team a,team b){return a.rating>b.rating;});
    }

    char grp='A';
    for(auto u : ans)
    {
        cout<<"Group "<<grp<<":\n";
        grp++;
        for(auto v : u)
        {
            cout<<v.name<<"\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}