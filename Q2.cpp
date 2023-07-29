#include<iostream>
#include<vector>
using namespace std;


void print(vector<int> &ans)
{
   int n = ans.size();

   for(int i = n-1; i >= 0; i--)
   cout<<ans[i];
}

vector<int> multiply(vector<int> &ans, int x)
{
   int n = ans.size();
   int carry = 0;

   for(int i = 0; i < ans.size(); i++)
   {
      int prod = ans[i]*x + carry;
      ans[i] = prod%10;
      carry = prod/10;
   }

   while(carry)
   {
      ans.push_back(carry%10);
      carry/=10;
   }
   
   return ans;
}

int main(){

   int n;
   cout<<"Enter the number";
   cin>>n;
   
   vector<int> ans;
   ans.push_back(1);
   
   for(int i = 2; i <= n; i++)
   {
      ans = multiply(ans,i);
   }

   print(ans);

   return 0;
}

