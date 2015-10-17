#include <iostream>
#include <cstdio>

using namespace std;


int fSum(int num)
{
    if(num == 1)
        return 0;
        
    int sum = 1;
        
    for(int i = 2; i * i <= num; ++i)
    {
        if(num % i == 0)
            sum += (i + (num / i));
        
        if(sum > num)
            return sum;
    }
    
    return sum;
}


int main()
{
    int num;
    cin >> num;
    
    printf("PERFECTION OUTPUT\n");
    
    while(num != 0)
    {
        int result = fSum(num);
        
        printf("%5i  %s\n", num,
                            (result < num ? "DEFICIENT" :
                                    (result == num ? "PERFECT" : "ABUNDANT")));
        
        cin >> num;
    }
    
    printf("END OF OUTPUT\n");
    
    return 0;
}
