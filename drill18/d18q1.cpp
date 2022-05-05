// Drill 18 Q1
// Seif Ahmed Mohamed Ahmed - GC39OP

#include "std_lib_facilities.h"

// Q1
int ga [10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};


// Q2
void f(int a[], int n)
{
	// q3 (a)
		int la[10];
	// q3 (b)
	for (int i = 0; i<10; i++)
		la[i] = ga[i];
	
	// q3 (c)
		cout << "elements of the array are: " << endl;
	for (int i = 0; i<10; i++)
		cout << la[i] << ' ' << endl;
	
	// q3 (d)
	int *p = new int [n];
	
	// q3 (e)
	//copy(p, a, n*sizeof(int));
	memcpy(p, a, n*sizeof(int));
		
	
	// q3 (f)
	cout << "elements of the array are: " << endl;
	for (int i = 0; i < n; ++i)
	cout << p[i] << " " << endl;
	// q3  (g)
	delete[] p;
	

}
int fac (int n)
{
	int x = 1;
	for( int i=1; i<n; i++)
		x*= i;
		
	return x;

}

int main ()
{
	// q4 (a)
	f (ga,10);

	// q4 (b)
	int aa [10] = {fac(1), fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10)};
	
	cout << " the factorial araay : " << endl;
	for (int i = 0; i < 10; ++i)
		cout << aa[i] << " " << endl;
		
	// q4 (c)
	f (aa, 10);
	

return 0;
}
