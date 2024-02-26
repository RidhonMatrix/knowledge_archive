/*
    Ridhon
    Problelm link:
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define endl   '\n'
#define deb(x)       cout << #x << " = " << x << endl
#define deb2(x, y)   cout << #x << " = " << x << "," << #y << "=" << y << endl
int gcd(int a,int b){ return b == 0 ? a : gcd(b, a % b); }

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v;
    int cnt = 0;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        if(s[s.size() - 1] == '0'){
            int c = 0;
            for(int j = s.size() - 1; j >= 0; --j){
                if(s[j] == '0') ++c;
                else break;
            }
            v.push_back({c, (int) s.size()});
        }else {
            cnt += s.size();
        }
    }
    sort(v.begin(), v.end(), greater<>());

    for(int i = 0; i < v.size(); ++i){
        if((i + 1) % 2 == 1){
            cnt += v[i].second - v[i].first;
        }else cnt += v[i].second;
    }
    // deb(cnt);
    if(cnt >= m + 1){
        cout << "Sasha" << endl;
    }else cout << "Anna" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    int c = 1;
    while(t--){
        //cout<<"Case "<<c++<<": ";
        solve();
    }
    return 0;
}