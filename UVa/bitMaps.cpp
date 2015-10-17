#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

char sbitmap[40001];
char ss[51];
bitset<40001> bbitmap;
char type;
int rows, cols;
string outstr;
char c;


int lsplit(int b, int e)
{return((b + e) / 2);}

int rsplit(int b, int e)
{return(1 + lsplit(b,e));}



void b2d(int rb, int re, int cb, int ce)
{
    if(rb == re && cb == ce)
    {
        outstr += (bbitmap[cb + cols * rb] ? '1' : '0');
        return;
    }
    
    bool first = bbitmap[cb + cols * rb];
    
    int j = cb+1;
    
    for(int i = rb; i <= re; ++i)
    {
        for(; j <= ce; ++j)
            if(bbitmap[j + cols * i] != first)
            {
                outstr += 'D';
                b2d(rb, lsplit(rb,re), cb, lsplit(cb,ce));
                if(cb != ce)
                    b2d(rb, lsplit(rb,re), rsplit(cb,ce), ce);
                if(rb != re)
                {
                    b2d(rsplit(rb,re), re, cb, lsplit(cb,ce));
                    if(cb != ce)
                        b2d(rsplit(rb,re), re, rsplit(cb,ce), ce);
                }
                return;
            }
        j = cb;
    }
            
    outstr += (first ? '1' : '0');
}



void d2b(int rb, int re, int cb, int ce)
{
    scanf("%c", &c);
    while(c != 'D' && c != '0' && c != '1')
        scanf("%c", &c);
    
    if(c != 'D')
    {
        for(int i = rb; i <= re; ++i)
            for(int j = cb; j <= ce; ++j)
                outstr[j + cols * i] = c;
                
        return;
    }
    
    d2b(rb, lsplit(rb,re), cb, lsplit(cb,ce));
    if(cb != ce)
        d2b(rb, lsplit(rb,re), rsplit(cb,ce), ce);
    if(rb != re)
    {
        d2b(rsplit(rb,re), re, cb, lsplit(cb,ce));
        if(cb != ce)
            d2b(rsplit(rb,re), re, rsplit(cb,ce), ce);
    }
}



int main()
{
    while(cin >> type >> rows >> cols)
    {
        sbitmap[0] = '\0';
        outstr = "";
        
        printf("%c%4i%4i\n", (type == 'B' ? 'D' : 'B'), rows, cols);
        
        if(rows <= 0 || cols <= 0)
            continue;
        
        if(type == 'B')
        {
            int len = 0;
            while(len != rows*cols)
            {
                scanf("%s", ss);
                strcat(sbitmap, ss);
                len += strlen(ss);
            }
            
            for(int i = 0; i < rows * cols; ++i)
                bbitmap[i] = (sbitmap[i] == '1');
                
            b2d(0, rows-1, 0, cols-1);
        }
        else
        {
            outstr.resize(rows*cols);
            d2b(0, rows-1, 0, cols-1);
        }
        
        for(int i = 0; i < outstr.length();)
        {
            for(int j = 0; j < 50 && i < outstr.length(); ++j, ++i)
                printf("%c", outstr[i]);
            cout << endl;
        }
    }
    
    return 0;
}
