#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int nums[101][101];
int sum[101];
char line[101];

int main()
{
    int rows = 0;
    int maxlen = 0;
    
    memset(nums, 0, sizeof(nums));
    memset(sum, 0, sizeof(sum));
    
    scanf("%s", line);
    while(strcmp(line, "0"))
    {
        int l = strlen(line);
        maxlen = max(maxlen, l);
        
        for(int i = 0; i < l; ++i)
            nums[rows][i] = line[i] - '0';
        
        ++rows;
        scanf("%s", line);
    }
    
    int j;
    for(j = maxlen-1; j >= 1; --j)
    {
        for(int i = 0; i < rows; ++i)
            sum[j] += nums[i][j];
            
        sum[j-1] = sum[j] / 10;
        sum[j] %= 10;
    }
    for(int i = 0; i < rows; ++i)
        sum[j] += nums[i][j];
    
    for(int i = 0; i < maxlen; ++i)
        cout << sum[i];
    cout << endl;
    
    return 0;
}
