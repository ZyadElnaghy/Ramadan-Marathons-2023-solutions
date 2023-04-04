#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-8
#define sz(s) int(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define TC int t; cin >> t; while(t--)
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define updmin(a, b) a = min((ll)a, (ll)b)
#define updmax(a, b) a = max((ll)a, (ll)b)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define cin_2d(vec, n, m) for(int i=0;i<n;i++) for(int j=0;j<m&&cin>>vec[i][j];j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll mod = 1000000007;
const ll INF = 1LL << 60;
typedef unsigned long long ull;

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v){ 
  for (const T &x : v) out << x << ' '; return out;
}

void Accepted(){

  ll n, k;
  cin >> n >> k;
  vector < ll > vec(n);
  cin >> vec;

  // binary search on the answer

  ll l = 1, r = accumulate(all(vec), 0LL);

  // lambda function to check if the sum of the subarrays is less than or equal to mid or not
  auto is_good = [&](ll mid, ll &sum) -> bool {
    ll cnt = 1, curr = 0;
    for (auto x : vec) {
      // if the current element plus the sum of the previous elements is less than or equal to mid then add it to the sum of the previous elements
      if (curr + x <= mid) curr += x;
      // else add the current element to the sum of the previous elements and increment the number of subarrays by 1 and update the sum of the subarrays
      else sum = max(sum, curr), curr = x, cnt++;
    }
    // update the sum of the subarrays
    sum = max(sum, curr);
    // check if the number of subarrays is less than or equal to k or not
    return cnt <= k;
  };

  // binary search to find the minimum sum of the subarrays 
  ll ans = 0;
  while (l <= r) {
    // find the minimum sum of the subarrays 
    ll mid = l + (r - l) / 2, sum = 0;
    if (is_good(mid, sum)) ans = sum, r = mid - 1;
    else l = mid + 1;
  }

  cout << ans << "\n";

}

int main()
{
 
  Gerges_Hany();
  int testcaces = 1, T = 1;
   cin >> testcaces;
  while (testcaces--){  
    // cout << "Scenario #" << T++ << ": \n";
    Accepted();
  }   
  Time; 
  return 0;
}