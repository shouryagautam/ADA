#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

string multiply(string num1,string num2)
{
    int dig = floor(log10(stod(num1)) + log10(stod(num2))) + 1;
    string ans(dig,'0');

    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    int n = num1.length();
    int m = num2.length();

    for(int i = 0; i < n; i++)
    {
        int j = 0;
        int carry = 0;
        for(; j < m; j++)
        {

            int val = carry + ( (num1[i] - '0') * (num2[j] - '0') );
            carry = val/10;
            ans[i+j] = ( (ans[i+j] - '0') + val%10) + '0';
            carry += (ans[i+j] - '0') / 10;
            ans[i+j] = (ans[i + j] - '0')%10 + '0';

        }

        if(carry) ans[i+j] = ((ans[i+j] - '0') + carry) + '0';
    }

    reverse(ans.begin(),ans.end());

    return ans;

}

int main(){
    
    string num1,num2;

    cout<<"Enter the first number";
    cin>>num1;

    cout<<"Enter the second number";
    cin>>num2;

    string ans = multiply(num1,num2);

    cout<<ans;

    return 0;
}













