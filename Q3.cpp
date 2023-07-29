#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the decimal number";
    cin>>n;

    int dig = floor(log2(n)) + 1;
    int * bin = new int[dig];

    for(int i = dig - 1; i >= 0; i--)
    {
        bin[i] = n%2;
        n /= 2;
    }

    for(int i = 0; i < dig; i++)
    cout<<bin[i];

    return 0;
}
