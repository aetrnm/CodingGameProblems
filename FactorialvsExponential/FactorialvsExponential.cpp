#include <iostream>
#include <conio.h>

using namespace std;

double powerAtoN(double a, int n)
{
    double ans = 1;
	for(int i = 0; i < n; i++)
	{
        ans *= a;
	}
    return ans;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        double A;
        cin >> A;
        int N = 1;
        while (powerAtoN(A, N) > factorial(N))
        {
            N++;
        }
    	if(i == K-1)
            cout << N << " ";

        else
			cout << N << " ";
    }
}