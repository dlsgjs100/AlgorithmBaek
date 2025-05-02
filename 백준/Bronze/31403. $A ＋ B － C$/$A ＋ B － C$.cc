#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A,B,C;
    cin>>A>>B>>C;
    
    int intSum = A + B - C;
    int stringSum = stoi(to_string(A) + to_string(B)) - C;
    
    cout<<intSum<<'\n'<<stringSum;
    return 0;
}