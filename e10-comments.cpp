//rey howle.....10^6/2 is 5 * 10^5.....not 10^3

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
#define s second
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

const int N=1e6;
const int M=3e5;
const int mod=1e9+7;

int n;
unmap<int,vector<string>> ans;
vector<pair<string,int>> msgs;
bool vis[N];

bool isNum(char c) { return c>='0' && c<='9';}

void dfs(pair<string,int> msg,int idx,int level)
{
    n=max(n,level);

    vis[idx]=true;
    ans[level].pb(msg.f);

    int k=0;
    for(int i=1;k<msg.s;i++)
    {
        if(!vis[idx+i])
        {
            dfs(msgs[idx+i],idx+i,level+1);
            k++;
        }
    }
}

void solve()
{
    int cnt=0;
    string str,temp;
    cin>>str;

    pair<string,int> dummy=mp("a",1);
    msgs.pb(dummy);

    for(int i=0;i<str.size();i++)
    {
        if(str[i]==',')
        {
            if(!isNum(str[i-1]))
            {
                msgs[cnt].f=temp;
                temp="";
            }
            else
            {
                msgs[cnt].s=n;
                n=0;
                msgs.pb(dummy);
                cnt++;
            }
        }
        else if(isNum(str[i]))
        {
            n=n*10+(str[i]-'0');
        }
        else
        {
            temp+=str[i];
        }
    }
    msgs[cnt].s=n;

    n=0;
    for(int i=0;i<msgs.size();i++)
    {
        if(!vis[i])
        {
            dfs(msgs[i],i,1);
        }
    }

    cout<<n<<"\n";
    for(int i=1;i<=n;i++,cout<<"\n")
    {
        for(string str : ans[i])
        {
            cout<<str<<" ";
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
    //cin>>t;

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