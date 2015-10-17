#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

vector<int> sequence;
vector<int> seg;

void init(int n)
{
    int len = 2 * (int)pow(2.0, floor(log(double(n)) / log(2.0)) + 1.0);
    seg.resize(len);
}


void build(int node, int b, int e)
{
    if(b == e)
        seg[node] = sequence[b];
    else
    {
        int left = node * 2;
        int right = left + 1;
        int mid = (b + e) / 2;
        
        build(left, b, mid);
        build(right, mid+1, e);
        
        if(left == right)
            seg[node] = seg[left];
        else
            seg[node] = seg[left] * seg[right];
    }
}


int prod(int node, int b, int e, int qb, int qe)
{
    if(e < qb || b > qe)
        return 1;
    if(b >= qb && e <= qe)
        return seg[node];
        
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    
    if(left == right)
        return prod(left, b, mid, qb, qe);
        
    return prod(left, b, mid, qb, qe) * prod(right, mid+1, e, qb, qe);
}


void update(int node, int b, int e, int up)
{
    if(up < b || up > e)
        return;
    if(b == e && b == up)
    {
        seg[node] = sequence[up];
        return;
    }
    
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    
    update(left, b, mid, up);
    update(right, mid+1, e, up);
    
    if(left == right)
        seg[node] = seg[left];
    else
        seg[node] = seg[left] * seg[right];
}


int main()
{
    int elements, rounds;
    
    while(cin >> elements)
    { 
        cin >> rounds;
    
        sequence.resize(elements);
        for(int i = 0; i < elements; ++i)
        {
            int temp;
            cin >> temp;
            sequence[i] = (temp > 0 ? 1 : (temp == 0 ? 0 : -1));
        }
        
        init(elements);
        build(1, 0, elements-1);
        
        for(int i = 0; i < rounds; ++i)
        {
            char com;
            int a, b;
            cin >> com >> a >> b;
            
            if(com == 'C')
            {
                sequence[a-1] = (b > 0 ? 1 : (b == 0 ? 0 : -1));
                update(1, 0, elements-1, a-1);
            }
            else
            {
                int product = 0;
                
                if(a == b)
                    product = sequence[a-1];
                else
                    product = prod(1, 0, elements-1, a-1, b-1);
                    
                if(product)
                    cout << ((product > 0) ? '+' : '-');
                else
                    cout << 0;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
