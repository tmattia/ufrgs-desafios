#include <iostream>
#include <math.h>

using namespace std;

long long int totient (long long int i)
{
	long long int res;
	long long int j;
	if (i==1) return 1;
	res=i;
	if (i%2==0)
	{
		res-=res/2;
		do i/=2; while (i%2==0) ;
	}
	for (j=3; j*j<=i; j+=2)
	{
		if (i%j==0)
		{
			res-=res/j;
			do i/=j; while (i%j==0) ;
		}
	}
	if (i>1) res-=res/i;
	return res; 
}


int main()
{
	long long int n;

	while (cin >> n) {
		if (n == 0) break;

		if (n == 1)
			cout << "0" << endl;
		else
			cout << totient(n) << endl;
	}

	return 0;
}
