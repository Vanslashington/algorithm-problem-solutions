#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <iterator>
#include <utility>

using namespace std;

typedef set<pair<int,int> > pset;

pset grades;
int avg;


bool pcomp(pair<int,int> p, int i)
{return p.first <= i;}



int main()
{
    int cases;
    cin >> cases;
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        grades.clear();
        avg = 0;
        
        int n;
        cin >> n;
        for(int stud = 0; stud < n; ++stud)
        {
            int grade;
            scanf("%i", &grade);
            grades.insert(pair<int,int>(grade, stud));
            avg += grade;
        }
        
        avg /= n;
        
        printf("%.3f%%\n", 100.0 * (double(n - distance(grades.begin(), 
                lower_bound(grades.begin(), grades.end(), avg, pcomp))) / 
                            double(n))  );
    }
    
    return 0;
}
