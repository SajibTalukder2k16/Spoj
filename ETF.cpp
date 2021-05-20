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
int main()
{
    for(int i=1;i<M;i++)
    {
        euler[i]=i;
        if(i%2==0)
            euler[i]/=2;
    }
    sieve(M);
    int test,cs;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        int n;
        cin>>n;
        cout<<euler[n]<<endl;
    }
    return 0;
} 
