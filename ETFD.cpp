#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define M 1000002
int marked[M/64 + 2];
ll euler[M+2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n) {
  for (ll i = 3; i<=n; i += 2) {
    if (!on(i)) {
      for (ll j = i ; j <= n; j += i ) {
        if(j%2==1)
            mark(j);
        euler[j]=(euler[j]/i)*(i-1);
      }
    }
  }
}

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}
vector<int>vec_euler[M];
int depth[M];
int main()
{
    for(int i=1;i<M;i++)
    {
        euler[i]=i;
        if(i%2==0)
            euler[i]/=2;
    }
    sieve(M);
    depth[1]=0;
    vec_euler[0].push_back(1);
    for(int i=2;i<M;i++)
    {
        int val=euler[i];
        depth[i]=depth[val]+1;
        vec_euler[depth[i]].push_back(i);
    }
    int test,cs;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int pos_l=lower_bound(vec_euler[k].begin(),vec_euler[k].end(),l)-vec_euler[k].begin();
        int pos_r=lower_bound(vec_euler[k].begin(),vec_euler[k].end(),r)-vec_euler[k].begin();
        int ans=pos_r-pos_l;
        if(vec_euler[k][pos_r]==r)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
