#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


vector<int> segtree;
bitset<1024000> pirates;
vector<queue<int> > queries;

void init(int n)
{
    int length = 2 * (int)pow(2.0, floor(log((double)n) / log(2.0)) + 1.0);
    segtree.resize(length);
}


void build(int node, int b, int e)
{
    if(b == e)
        segtree[node] = (int)pirates[b];
    else
    {
        int left = node * 2;
        int right = 1 + node * 2;
        
        build(left, b, (b + e) / 2);
        build(right, 1 + (b + e) / 2, e);
        
        segtree[node] = segtree[left] + segtree[right];
    }
}


int query(int node, int b, int e, int qb, int qe)
{
    if(b > qe || e < qb)
        return 0;
    if(b >= qb && e <= qe)
        return segtree[node];
    
    int left = node * 2;
    int right = 1 + node * 2;
    
    int lcount = query(left, b, (b + e) / 2, qb, qe);
    int rcount = query(right, 1 + (b + e) / 2, e, qb, qe);
    
    segtree[node] = lcount + rcount;
    return segtree[node];
}


int query2(int node, int b, int e, int qb, int qe)
{
    if(b > qe || e < qb)
        return 0;
    if(b == e)
    {
        segtree[node] = pirates[b];
        return segtree[node];
    }
    
    int left = node * 2;
    int right = 1 + node * 2;
    
    int lcount = query2(left, b, (b + e) / 2, qb, qe);
    int rcount = query2(right, 1 + (b + e) / 2, e, qb, qe);
    
    segtree[node] = lcount + rcount;
    return segtree[node];
}

void update(int node, int b, int e, int rb, int re)
{
    if(b > re || e < rb)
        return;
    if(b == e)
    {
        segtree[node] = pirates[b];
        return;
    }
    else
    {
        int left = node * 2;
        int right = 1 + node * 2;
        
        update(left, b, (b + e) / 2, rb, re);
        update(right, 1 + (b + e) / 2, e, rb, re);
        
        segtree[node] = segtree[left] + segtree[right];
    }
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        string piratess = "";
        
        int m;
        cin >> m;
        
        int len;
        
        for(int i = 0; i < m; ++i)
        {
            int its;
            cin >> its;
            string temp;
            cin >> temp;
            
            for(int j = 0; j < its; ++j)
                piratess += temp;
        }
        
        len = piratess.size();
        reverse(piratess.begin(), piratess.end());
        pirates = bitset<1024000>(piratess);
        init(len);
        build(1, 0, len-1);
        
        int q;
        cin >> q;
        
        cout << "Case " << tcase << ":" << endl;
        int qnum = 1;
        
        queries = vector<queue<int> >(len, queue<int>());
        
        bool up = false;
        
        for(int i = 0; i < q; ++i)
        {
            char code;
            int b, e;
            cin >> code >> b >> e;
            
            switch(code)
            {
                case('F'):
                    for(int j = b; j <= e; ++j)
                        pirates[j] = 1;
                    up = true;
                    break;
                case('E'):
                    for(int j = b; j <= e; ++j)
                        pirates[j] = 0;
                    up = true;
                    break;
                case('I'):
                    for(int j = b; j <= e; ++j)
                        pirates[j] = !pirates[j];
                    up = true;
                    break;
                    
                case('S'):
                    if(up)
                    {
                        cout << "Q" << qnum++ << ": "
                             << query2(1, 0, len-1, b, e) << endl;
                        up = false;
                    }
                    else
                    {
                        cout << "Q" << qnum++ << ": "
                             << query(1, 0, len-1, b, e) << endl;
                    }
                    break;
            }
        }
    }
    
    return 0;
}
