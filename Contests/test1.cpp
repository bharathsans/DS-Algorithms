#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "Debugger_CP.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

typedef long long ll;
typedef vector<ll> vl;
#define invec(a, n) for(ll i = 0; i < n; i++) {cin >> a[i];}
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define ff first
#define ss second
#define ini(a, i) memset(a, i, sizeof(a))
#define ub(a,x) upper_bound(all(a),x) - a.begin()
#define lb(a,x) lower_bound(all(a),x) - a.begin()
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

void solve()
{
     int n;
     cin >> n;

     vector<int> v(n);
     
     unordered_map<int, bool> unique;

     int lowestMiss = n;
     int cuts = 0;

     for(int i = 0; i < n; i++){
          cin >> v[i];
          unique[v[i]] = 1;
     }

     for(int i = 0; i <= n; i++){
          if(!unique[i]){
               lowestMiss = i;
               break;
          }
     }
          
     unique.clear();

     int count = 0;
     vector<int> cutInd;

     int left = n - 1;
     int right = 0;

     for(int i = 0; i < n; i++){
          if(v[i] < lowestMiss){
               if(!unique[v[i]]){
                    ++count;
                    unique[v[i]] = 1;
               }
          }
          if(count == lowestMiss){
               left = i;
               break;
          }
     }

     unique.clear();

     for(int i = n - 1; i >= 0; i--){
          if(v[i] < lowestMiss){
               if(!unique[v[i]]){
                    ++count;
                    unique[v[i]] = 1;
               }
          }
          if(count == lowestMiss){
               right = i;
               break;
          }
     }

     if(left < right){
          cout << 2 << endl;
          cout << "1 " << left + 1 << endl;
          cout << left + 2 << " " << n << endl;
     }
     else
          cout << -1 << endl;
}

int main()
{
     fast();
     int T;
     cin >> T;
     while(T--)
         solve();
}