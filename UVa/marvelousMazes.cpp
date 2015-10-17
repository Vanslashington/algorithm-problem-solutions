#include <cstdio>

using namespace std;


int main()
{
    int rep = 0;
    char c;
    
    while(scanf("%c", &c) != EOF)
    {
        if(c >= '0' && c <= '9')
            rep += (c - '0');
            
        else if(c == '!' || c == '\n')
            printf("\n");
        
        else
        {
            if(c == 'b')
                c = ' ';
            
            for(int i = 0; i < rep; ++i)
                printf("%c", c);
            
            rep = 0;
        }
    }
    
    return 0;
}
