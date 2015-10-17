#include <iostream>
#include <cstdio>

using namespace std;


const bool PAREN = 0,
           BRACKET = 1;

char b[2] = {'(', '['},
     e[2] = {')', ']'};

char p;


bool correct(bool type)
{
    scanf("%c", &p);

    while(p == b[type] || p == b[!type])
    {
        if(!correct(p == '['))
            return false;
            
        scanf("%c", &p);
    }
            
    if(p == e[type])
        return true;
    
    return false;
}


int main()
{
    int cases;
    scanf("%i%*c", &cases);
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        bool answer = true;
        
        scanf("%c", &p);
        
        while(p != '\n')
        {
            if(p == ']' || p == ')')
                answer = false;
            else if(!answer || !correct(p == '['))
                    answer = false;
            
            if(p == '\n')
                break;
            
            scanf("%c", &p);
        }
        
        cout << (answer ? "Yes" : "No") << endl;
    }
    
    return 0;
}
