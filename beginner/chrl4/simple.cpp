#include <iostream>
#include <math.h>
using namespace std;

const int modulo = 1000000007;

int main(int argc, char *argv[])
{
    int n, k; 
    cin >> n >> k;
    int *A = new int[n];
    long *prod = new long[n];
    for (int i=0; i<n; ++i) cin >> A[i];
    prod[0] = A[0];

    for (int i=1; i<=k && i<n; ++i) prod[i] = prod[0] * A[i] % modulo;
    
    
    
    
    return 0;
}
