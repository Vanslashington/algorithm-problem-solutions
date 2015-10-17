#include <stdio.h>


#define MAX_BOLTS 500
#define MAX_NUTS  500

/* global copy of the input data */
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];

/* data used to match nuts with bolts */
int nut_used[MAX_NUTS];
int bestmatched;


void match_bolt(int boltno, int matched)
{
    if(boltno == bolts)
    {
        if(matched > bestmatched) 
            bestmatched = matched;
            
        return;
    }

    /* don't match this bolt */
    match_bolt(boltno+1,matched);

    /* match with all unused nuts that fit this bolt */
    for(int n=0; n < nuts; n++) 
        if(!nut_used[n] && fits[boltno][n])
        {
            nut_used[n]=1;
            match_bolt(boltno+1,matched+1);
            nut_used[n]=0;
        }
}



int main()
{
    int cases,caseno;

    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++)
    {
        scanf("%d%d",&bolts,&nuts);
    
        for(int b=0;b<bolts;b++)
            for(int n=0;n<nuts;n++)
                scanf("%d",&fits[b][n]);
                
        bestmatched=0;
    
        for(int n=0;n<nuts;n++) 
            nut_used[n]=0;
            
        match_bolt(0,0);
        
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }

    return 0;
}
