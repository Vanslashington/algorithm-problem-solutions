#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;


map<char,char> rev;
char s[21];
bool pal, mir;


bool check()
{
    int len = strlen(s);
        
    pal = true;
    mir = true;
    
    for(int b = 0, e = len-1; b <= e; ++b, --e)
    {
        if(s[b] != s[e])
            pal = false;
        if(rev[s[b]] != s[e])
            mir = false;
        
        if(!pal && !mir)
            return false;
    }
    
    return true;
}


int main()
{
    string f = "AEHIJLMOSTUVWXYZ12358";
    string t = "A3HILJMO2TUVWXY51SEZ8";
    
    for(int i = 0; i < f.size(); ++i)
        rev[f[i]] = t[i];
        
    
    while(scanf("%s", s) != EOF)
    {
        printf("%s -- is ", s);
        
        if(!check())
            printf("not a palindrome");
        else
        {
            printf("a %s %s", 
                   (mir ? "mirrored" : "regular") ,
                   (pal ? "palindrome" : "string")   );
        }
        
        printf(".\n\n");
    }
    
    
    return 0;
}
