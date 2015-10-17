#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;


typedef vector<int> vi;
typedef vi::iterator vi_it;

vi sequence;
vi endIndexOfLIS;
vi parent;


void printLis(int i)
{
    if(parent[i] != -1)
        printLis(parent[i]);

    printf("%i\n", sequence[i]);
}


int main()
{
    sequence.reserve(50000);
    endIndexOfLIS.reserve(50000);
    parent.reserve(50000);


    int e;
    while(scanf("%i", &e) != EOF)
        sequence.push_back(e);

    int longest = 0;

    int seqLen = sequence.size();
    parent.resize(seqLen, -1);
    for(int i = 0; i < seqLen; ++i)
    {
        if(endIndexOfLIS.empty())
        {
            endIndexOfLIS.push_back(i);
            ++longest;
        }
        else if(sequence[i] > sequence[endIndexOfLIS.back()])
        {
            parent[i] = endIndexOfLIS.back();
            endIndexOfLIS.push_back(i);
            ++longest;
        }
        else
        {
            int mLen = endIndexOfLIS.size();

            int lo = 0;
            int hi = mLen-1;
            while(lo != hi)
            {
               int mid = (lo + hi) / 2;
               if(sequence[endIndexOfLIS[mid]] >= sequence[i])
                   hi = mid;
               else
                   lo = mid+1;     
            }
            
            endIndexOfLIS[lo] = i;
            if(lo == 0)
                parent[i] = -1;
            else
                parent[i] = endIndexOfLIS[lo-1];
        }
    }

    cout << longest << "\n-\n";
    printLis(endIndexOfLIS.back());

    return 0;
}
