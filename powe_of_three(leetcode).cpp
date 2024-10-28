#include<bits/stdc++.h>
using namespace std;
bool isPowerOfThree(int n)
{
        if(n == 1) return true;
        if(n < 1 || n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    }
int main()
{
	double n;
	cin>>n;
	if(isPowerOfThree(n))
	{
		cout<<"YES"<<endl;

	}
	else cout<<"NO"<<endl;
}
