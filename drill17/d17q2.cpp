// Drill 17 Q2
// Seif Ahmed Mohamed Ahmed - GC39OP

#include "std_lib_facilities.h"
void print_array(ostream& os, int* a, int n)
{
	for(int i=0; i<n; i++)
		os << a[i] << endl;
	delete[] a;  
}

  int main(){
  	
  	//Q1:
  		int n = 7;		//allocating an int, initiallizing it to 7.
  		int * p1 = &n;		// assigning it's address to p1.
  	
  	//Q2:
  		cout << "p1: " << ' ' << p1 << " of n = " << n << endl;
  		
  	//Q3:
  		int seven_i[7] { 1, 2, 4, 8, 16, 32, 64}; 	// Allocating the array seven_i of 7 elements. 
  		int* p2 = seven_i;		// assigning its address to a variable p2.
  	
  	//Q4:
  		cout << "p2: " << p2 << " of n = " << n << endl; 		// Print out the value of p2
  		print_array (cout, p2, 7) ; 	// and the array it points to using print_array.
  		
  	
  	//Q5:
  		int* p3 = p2;
  		
  	//Q6:
  		p1 = p2;
  		
  	//Q7:
  		p3 = p2;
  		
  	//Q8:
  		cout << "p1: " << ' ' << p1 << " it points to " << *p1 << endl; 	// p1 points to the first element in the array.
  		
  	//Q9: We have never used any free_space to dellocate something.
  	
  	//Q10: 
  		int ten_i[10] { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512}; 	// Allocating the array ten_i of 10 elements.
  		p1 = ten_i;
  		
  	//Q11:
  		int ten_ii[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 513};
  		p2 = ten_ii;
  	
  	//Q12:
  		for ( int i =0; i<10; i++)
  		p2[i] = p1[i];
  		
  	//Q13:
  		vector<int> v_ten_i{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	p1 = &v_ten_i[0];
		
	vector<int> v_ten_ii {1, 2, 4, 8, 16, 32, 64, 128, 256, 513};
	p2 = &v_ten_ii[0];
		

	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];

	return 0;
}
