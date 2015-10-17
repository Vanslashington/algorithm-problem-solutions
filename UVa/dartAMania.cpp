#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;
typedef set<int> iset;
typedef iset::iterator it;

int qScore;

iset scores;
int darts[3];

it i, j, k;

int combos, perms;

int main()
{
    scores.insert(0);
    scores.insert(50);
    for(int s = 1; s <= 20; ++s)
        for(int n = 1; n <= 3; ++n)
            scores.insert(s * n);
    
    scanf("%i ", &qScore);
    while(qScore > 0)
    {
        combos = perms = 0;
        
        for(i = scores.begin(); *i <= qScore && i != scores.end(); ++i)
            for(j = i; *i + *j <= qScore && j != scores.end(); ++j)
                for(k = j; *i + *j + *k <= qScore && k != scores.end(); ++k)
                    if(*i + *j + *k == qScore)
                    {
                        ++combos;
                        
                        darts[0] = *i;
                        darts[1] = *j;
                        darts[2] = *k;
                        
                        ++perms;
                        while(next_permutation(darts, darts+3))
                            ++perms;
                    }
        
        if(combos > 0)
        {
            printf("NUMBER OF COMBINATIONS THAT SCORES %i IS %i.\n",
                                                    qScore,  combos);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %i IS %i.\n",
                                                    qScore,  perms);
        }
        else
            printf("THE SCORE OF %i CANNOT BE MADE WITH THREE DARTS.\n",
                                qScore);
                                
        printf(
    "**********************************************************************\n");
        
        scanf("%i ", &qScore);
    }
    
    printf("END OF OUTPUT\n");
    
    return 0;
}
