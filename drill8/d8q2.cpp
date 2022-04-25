#include "std_lib_facilities.h"

void swap_v( int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "val1 is " << a << ' '<< "val2 is " << b << endl;
}

void swap_r(int& a, int& b)
{
	
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "val1 is " << a << ' '<< "val2 is " << b << endl;
}
/*
void swap_cr(const int& a, const int& b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;	
}
	        // this function will not even compile as it tries to change the value of a constant/fixed value.
	        // none of the swap_cr functions will compile nor swap.
*/

/*void swap_cr(const int& a, const int& b)
{
	int temp1;
	int temp2;
	temp1 = a;
	temp2 = b;
	
	swap_r(temp1, temp2);
}
			// sol ??
*/




int main()
{
	int x = 7;
	int y = 9;
	swap_r(x,y);
			 // swap_v() compiles and swaps
			// swap_r() compiles and swaps
	swap_v(7,9);	
			// swap_v() compiles and swaps
			// swap_r() doesn't compile, as there's no address to pass in.
	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
			//swap_v() compiles and swaps 
			//swap_r() doesn't compile.
	swap_v(7.7,9.9);
			//swap_v() compiles and swaps 
			//swap_r() doesn't compile.
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);
			//swap_v() compiles and swaps 
			//swap_r() doesn't compile.
	
	return 0;
	
	
	
	
	
	}
