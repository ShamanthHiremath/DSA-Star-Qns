#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long int pow=1;
	while(n>0){
		if(n%2!=0){
			pow=((pow%m)*(x%m))%m;
		}
		x=(1LL* (x%m)*(x%m))%m;
		n=n>>1;
	}
	return pow;
}
//a^b == (a^b/2)^2 if even and (a^b/2)^2 * a if odd
//Ex:2^10 and 2^11