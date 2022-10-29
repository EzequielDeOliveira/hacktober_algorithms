#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll OO = 0x3f3f3f3f3f3f3f3fLL;

struct Segtree {

    int n;
    vector<ll> seg;

    Segtree(vector<ll>& s){
        n = (int)s.size();
        seg.resize(n+n+n+n, 0);
        seg_build(1,0,n-1,s);
    }

    ll merge(ll a, ll b){
        //return a+b;
        if(!a) a = OO;
        if(!b) b = OO;
        return min(a,b);
    }

    void seg_build(int x, int l, int r, vector<ll>& s){
        if(r < l) return;
        if(l == r){
            seg[x] = s[l];
        } else {
            int mid = l + (r-l)/2;
            seg_build(x+x, l, mid, s);
            seg_build(x+x+1, mid+1, r, s);
            seg[x] = merge(seg[x+x], seg[x+x+1]);
        }
    }

    ll q(int x, int l, int r, int i, int j){
        if(r < i || l > j ) return 0;
        if(l >= i && r <= j ) return seg[x];
        int mid = l + (r-l)/2;        
        return merge(q(x+x,l,mid,i,j), q(x+x+1,mid+1,r,i,j));
    }

    void att(int x, int l, int r, int posi, ll val){
        if(l == r){
            seg[x] = val;
        } else {
            int mid = l + (r-l)/2;
            if(posi <= mid)att(x+x,l,mid,posi,val);    
            else att(x+x+1,mid+1,r,posi,val);
            seg[x] = merge(seg[x+x], seg[x+x+1]);
        }
    }
 
    int findkth(int x, int l, int r, int k){
        if(l == r){
            return l;
        } else {
            int mid = l + (r-l)/2;
            if(seg[x+x] >= k){
                return findkth(x+x,l,mid,k);
            } else {
                return findkth(x+x+1,mid+1, r, k - seg[x+x]);    
            }
        }
    }

    ll query(int l, int r){
        return q(1, 0, n-1, l, r);
    }

    void update(int posi, ll val){
        att(1, 0, n-1, posi, val);
    }

    int findkth(int k){
        return findkth(1,0,n-1,k);
    }

};