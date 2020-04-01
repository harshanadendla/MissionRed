/*
	YES PAIN YES GAIN
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define un_map unordered_map
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

void solve()
{
	un_map<char,vi> indexes;

	int n,k;
	cin>>n>>k;

	string str,ans;
	cin>>str;

	for(int i=0;i<str.size();i++)
	{
		indexes[str[i]].pb(i);
	}

	for(char c='a';c<='z' && k!=0;c++)
	{
		for(int i=0;i<indexes[c].size() && k!=0;i++) 
		{
			str[indexes[c][i]]='#';
			k--;
		}
	}

	for(int i=0;i<str.size();i++) if(str[i]!='#') ans.pb(str[i]);

	cout<<ans;
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