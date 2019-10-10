#include <bits/stdc++.h>
using namespace std;

//===============typedef
typedef long long ll;
typedef vector<pair<int,char > > vi;

#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
#define pb push_back



int main()
{
	int n,e;
	cin>>n>>e;
	vi g[n+1];

	for(int i=0;i<e;i++)
	{
		char w;
		int x,y;
		cin>>x>>y>>w;
		g[x].push_back({y,w});
	}

	string chk;
	cin>>chk;
	int now=0;

	for (int i=0;i<sz(chk);i++)
	{
		for(int j=0;j<g[now].size();j++)
		{
			if(g[now][j].second==chk[i])
				now=g[now][j].first;
		}
	}
	cout<<(now==2?"ACCEPTED":"REJECTED");
}