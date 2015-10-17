#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;


double GOLDEN_RATIO;


long long tableSize, goldenRatioVal;
int fibLevel = 46;
vector<int> table;
int numElements;


int main()
{
    srand(time(NULL));
    int a = 0, b = 1;
    for(int i = 2; i <= fibLevel; ++i)
    {
        int sum = a + b;
        a = b;
        b = sum;
    }

    GOLDEN_RATIO = 2.0 - double(b) / double(a);

    cout << endl << "Table Size: ";
    cin >> tableSize;
    cout << "Number of elements: ";
    cin >> numElements;


    table.clear();
    table.resize(tableSize);

    goldenRatioVal = (long long)floor(.5 + (double(tableSize) * GOLDEN_RATIO));

    cout << endl
         << "Ratio Value: " << goldenRatioVal << endl;

    for(long long i = 1; i <= numElements; ++i)
    {
        int val = rand() % 100000;
        int index = (val * goldenRatioVal) % tableSize;
        if(table[index])
            cout << "{" << val << ": " << index << "}" << ", ";
        table[index] = val;
    }
    cout << endl << endl;

    for(int i = 0; i < tableSize; ++i)
        cout << table[i] << ", ";
    cout << endl;


    return 0;
}
