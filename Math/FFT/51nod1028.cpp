#include <iostream>
#include <cstdio>
#include <cstring>
#include <complex>
using namespace std ;

const double PI = 3.1415926535897932384626 ;
const int MAXN = 262145 ;
const complex<double> I(0,1) ;

complex<double> a[MAXN] , a_tmp[MAXN] ;
complex<double> save_w0[2][MAXN] ;

complex<double> MUL( complex<double> z1 , complex<double> z2 ) {
	double __rr = z1.real() * z2.real() ;
	double __ii = z1.imag() * z2.imag() ;
	double tmp = (z1.real() + z1.imag()) * (z2.real() + z2.imag()) ;
	complex<double> ret(__rr - __ii, tmp - __rr - __ii) ;
	return ret;
}

// Consider the seq. a[x], a[x+s], ..., a[x+s*(n-1)]
void FFT( int sign , int n , int x , int s ) {
	if ( n == 1 ) return ;
	if ( n == 2 ) {
		a_tmp[1] = a[x] ;
		a_tmp[2] = a[x+s] ;
		a[x] = a_tmp[1] + a_tmp[2] ;
		a[x+s] = a_tmp[1] - a_tmp[2] ;
		return ;
	}
	FFT(sign , n/2 , x , s*2) ;
	FFT(sign , n/2 , x+s , s*2) ;

	int i0 , y0 ;
	complex<double> w ;
	for ( i0 = 0 , y0 = x , w = 1.0 ; i0 < n / 2 ; i0 ++ , y0 += s*2 , w = MUL(w,save_w0[sign][n]) ) {
		a_tmp[i0] = a[y0] ;
		a_tmp[i0+n/2] = MUL(a[y0+s] , w) ;
	}
	for ( i0 = 0 , y0 = x ; i0 < n/2 ; i0 ++ , y0 += s) {
		a[y0] = a_tmp[i0] + a_tmp[i0+n/2] ;
		a[y0+s*n/2] = a_tmp[i0] - a_tmp[i0+n/2] ;
	}
}

void Init() {//´ò±í
	for ( int i = 1 ; i <= 262144 ; i ++ ) {
		save_w0[1][i] = exp(2.0 * PI * I / (double)i) ;
		save_w0[0][i] = exp(-2.0 * PI * I / (double)i) ;
	}
}

char s1[MAXN] , s2[MAXN] ;
int num1[MAXN] , num2[MAXN] ;
complex<double> b[MAXN] ;
int ans[MAXN] ;

int main() {
    Init() ;
    while(gets(s1)){
        gets(s2) ;
        int len1 = strlen(s1) ;
        int len2 = strlen(s2) ;
        int n = 1 ;
        while ( len1 * 2 > n || len2 * 2 > n ) n *= 2 ;
        for ( int i = 1 ; i <= n ; i ++ ) num1[i] = 0 , num2[i] = 0 ;
        for ( int i = len1 - 1 ; i >= 0 ; i -- ) num1[len1 - i] = (int)(s1[i] - '0') ;
        for ( int i = len2 - 1 ; i >= 0 ; i -- ) num2[len2 - i] = (int)(s2[i] - '0') ;
        for ( int i = 1 ; i <= n ; i ++ ) a[i] = (double)num1[i] ;
        FFT(1 , n , 1 , 1) ;
        for ( int i = 1 ; i <= n ; i ++ ) b[i] = a[i] ;
        for ( int i = 1 ; i <= n ; i ++ ) a[i] = (double)num2[i] ;
        FFT(1 , n , 1 , 1) ;
        for ( int i = 1 ; i <= n ; i ++ ) a[i] *= b[i] ;
        FFT(0 , n , 1 , 1) ;
        for ( int i = 1 ; i <= n ; i ++ ) ans[i] = (int)(a[i]/(double)n+0.5).real() ;

        for ( int i = 1 ; i < n ; i ++ ) {
            ans[i+1] += ans[i] / 10 ;
            ans[i] %= 10 ;
        }
        for ( int i = n ; i >= 1 ; i -- ) if ( i == 1 || ans[i] != 0 ) {
            for ( int j = i ; j >= 1 ; j -- ) printf("%d" , ans[j]) ;
            puts("") ;
            break ;
        }
    }
}
