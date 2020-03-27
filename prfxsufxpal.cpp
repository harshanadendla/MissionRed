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
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

string longestPrfxPal(string str)
{
    string s1=str+"*";
    reverse(str.begin(),str.end());
    s1+=str;

    vi prfx(s1.size(),0);

    int idx=0,i=1;

    while(i<s1.size())
    {
        if(s1[idx]==s1[i])
        {
            prfx[i++]=++idx;
        }
        else
        {
            if(idx!=0)
            {
                idx=prfx[idx-1];
            }
            else
            {
                prfx[i++]=idx;
            }
        }
    }

    return s1.substr(0,idx);
}

void solve()
{
    string str;
    cin>>str;

    int l=0,r=str.size()-1;

    while(l<r && str[l]==str[r]) l++,r--;

    string lhs=str.substr(0,l),rhs=str.substr(r+1);

    string mid=str.substr(l,r-l+1);

    string mid1=longestPrfxPal(mid);

    reverse(mid.begin(),mid.end());

    string mid2=longestPrfxPal(mid);

    (mid1.size() > mid2.size()) ? mid=mid1 : mid=mid2 ;

    cout<<lhs<<mid<<rhs<<"\n";
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