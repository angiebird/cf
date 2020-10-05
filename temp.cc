#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;

// #define int ll

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
  string sep = " ";
  for (const auto& x : v) {
    os << x << sep;
  }
  return os << '\n';
}

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H; dbg_out(T...);
}

#ifdef QLEG_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

vi get_primes(int n, vi& prime_ls) {
  vi min_div_ls(n + 1);
  min_div_ls[0] = 1;
  min_div_ls[1] = 1;
  for(int v = 2; v <=n; v++) {
    if(min_div_ls[v] == 0) {
      min_div_ls[v] = v;
      prime_ls.pb(v);
      int idx = 2*v;
      while(idx <= n) {
        if(min_div_ls[idx] == 0) {
          min_div_ls[idx] = v;
        }
        idx += v;
      }
    }
  }
  return min_div_ls;
}

void factorize_div(const vi& min_div_ls, int v, vi& factors, vi& powers) {
  while(v != 1) {
    int div = min_div_ls[v];
    factors.pb(div);
    int pows = 0;
    while(v % div == 0) {
      pows++;
      v /= div;
    }
    powers.pb(pows);
  }
}

void factorize(vi& prime_ls, int v, vi& factors, vi& powers) {
  int cnt = 0;
  for(auto p : prime_ls) {
    if(v % p == 0) {
      factors.pb(p);
      powers.pb(0);
      while(v % p == 0) {
        v /= p;
        powers[cnt] += 1;
      }
      cnt++;
    }
  }
  if(v != 1) {
    factors.pb(v);
    powers.pb(1);
  }
}

void get_divisors(const vi& factors, const vi& powers, vi& divs, int idx = 0) {
  if(idx == factors.size()) {
    return;
  }
  if(idx == 0) {
    divs.pb(1);
  }
  int p = powers[idx];
  int f = factors[idx];
  int s = 1;
  for(int i = 1; i <= p;++i){
    s *= f;
    int len = divs.size();
    for(int j = 0; j < len; ++j) {
      int d = divs[j];
      divs.pb(d*s);
    }
  }
  get_divisors(factors, powers, divs, idx+1);
}

signed main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1; cin>>T;
  for(int t = 0; t < T; t++) {
    int n;
    cin>>n;
  }
  return 0;
}
