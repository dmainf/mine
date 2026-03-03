#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
struct Point {
    double x, y;
    Point(double x=0,double y=0):x(x),y(y){}
    Point operator+(const Point& o) const { return {x+o.x, y+o.y}; }
    Point operator-(const Point& o) const { return {x-o.x, y-o.y}; }
    Point operator*(double k) const { return {x*k, y*k}; }
};
double dot(Point a, Point b){ return a.x*b.x + a.y*b.y; }
double norm2(Point a){ return dot(a,a); }
double dist(Point a, Point b){ return sqrt(norm2(a-b)); }
double min_distance(Point pT0, Point vT, double tT, Point pA0, Point vA, double tA) {
    double ans = 1e100;
    vector<double> ts;
    ts.push_back(0);
    ts.push_back(min(tT, tA));
    ts.push_back(max(tT, tA));
    ts.push_back(tT);
    ts.push_back(tA);
    for (double t : ts) {
        Point PT = (t < tT ? pT0 + vT*t : pT0 + vT*tT);
        Point PA = (t < tA ? pA0 + vA*t : pA0 + vA*tA);
        ans = min(ans, dist(PT, PA));
    }
    double t = min(tT, tA);
    Point D = pT0 - pA0;
    Point V = vT - vA;
    double t_star = -dot(D, V) / norm2(V);
    if(t_star > 0 && t_star < t) {
        Point PT = pT0 + vT*t_star;
        Point PA = pA0 + vA*t_star;
        ans = min(ans, dist(PT, PA));
    }
    if(tT > tA) {
        double t_star2 = -dot(pT0 + vT*0 - (pA0 + vA*tA), vT) / norm2(vT);
        if(t_star2 > tA && t_star2 < tT) {
            Point PT = pT0 + vT*t_star2;
            Point PA = pA0 + vA*tA;
            ans = min(ans, dist(PT, PA));
        }
    }
    if(tA > tT) {
        double t_star3 = -dot(pA0 + vA*0 - (pT0 + vT*tT), vA) / norm2(vA);
        if(t_star3 > tT && t_star3 < tA) {
            Point PT = pT0 + vT*tT;
            Point PA = pA0 + vA*t_star3;
            ans = min(ans, dist(PT, PA));
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    while(t--){
        Point as, ag, bs, bg;
        cin >> as.x >> as.y >> ag.x >> ag.y;
        cin >> bs.x >> bs.y >> bg.x >> bg.y;

        Point vT = ag - as;
        double lenT = sqrt(norm2(vT));
        Point dirT = (lenT > 0 ? vT*(1.0/lenT) : Point(0,0));

        Point vA = bg - bs;
        double lenA = sqrt(norm2(vA));
        Point dirA = (lenA > 0 ? vA*(1.0/lenA) : Point(0,0));

        double ans = min_distance(as, dirT, lenT, bs, dirA, lenA);
        cout << ans << endl;;
    }
}
