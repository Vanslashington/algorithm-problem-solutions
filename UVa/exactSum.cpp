#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
typedef deque<int> di;
typedef di::iterator dit;

di books;
int nbooks, money;
dit ub, lb;


int main()
{
    bool first = true;
    
    while(cin >> nbooks)
    {
        books.resize(nbooks);
        
        for(int i = 0; i < nbooks; ++i)
            cin >> books[i];
            
        sort(books.begin(), books.end());
        
        cin >> money;
        
        ub = upper_bound(books.begin(), books.end(), money - books[0]);
        lb = lower_bound(books.begin(), books.end(), money / 2 + 1);
        
        while(!binary_search(lb, ub, money - *lb))
            --lb;
        
        cout << "Peter should buy books whose prices are "
             << *lb << " and " << money - *lb << "." << endl << endl;
    }
    
    return 0;
}
