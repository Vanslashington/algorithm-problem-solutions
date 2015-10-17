#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    
    while(A != "0" || B != "0")
    {
        int l = (A.length() > B.length() ? B.length() : A.length());
        int t = 0;
        
        int c = 0;
        
        for(int i = 0; i < l; ++i)
        {
            c = ((A[A.length() - (i+1)] - '0') + 
                 (B[B.length() - (i+1)] - '0') + c > 9);
            t += c;
        }
        
        if(A.length() != B.length())
        {
            if(A.length() < B.length())
            {
                string temp = A;
                A = B;
                B = temp;
            }
            
            for(int i = l; i < A.length(); ++i)
            {
                c = ((A[A.length() - (i+1)] - '0') + c > 9);
                t += c;
            }
        }
        
        string st;
        st += ('0' + t);
        
        cout << (t == 0 ? "No" : st) << " carry operation" 
             << (t > 1 ? "s." : ".") << endl;
        
        cin >> A >> B;
    }
    
    return 0;
}
