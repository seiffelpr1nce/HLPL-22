// Drill 17 Q1
// Seif Ahmed Mohamed Ahmed - GC39OP

#include "std_lib_facilities.h"


  	// step4: Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os.


void print_array10(ostream& os, int* a)	// for both Q4&Q5
{
	for(int i=0; i<10; i++)
		os << a[i] << endl;
	delete[] a;  // as in step 9..
			// Do i need to use delete[] to free_store each time ?
}

	// step6: Allocate an array of 11 ints on the free store; initialize it with the values 100,101, 102, etc.; and print out its values.
	

void print_array11(ostream& os, int* a)
{
	for(int i=0; i<11; i++)
		os << a[i] << endl;

	delete[] a; // as in step 9..
}

/*void print_array20(ostream& os, int* a)
{
	for(int i=0; i<20; i++)
		os << a[i] << endl;
	delete[] a; // as in step 9..
}*/

	// step7:  Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os.
	
void print_array(ostream& os, int* a, int n)
{
	for(int i=0; i<n; i++)
		os << a[i] << endl;
	delete[] a;  // as in step 9..
}

void printVector(vector<int> v)
{

	for (int i=0; i<v.size(); ++i)
		cout << v[i] << endl;  //printing vector[i]
	//delete v[i];  


}

vector<int> allocateVector(int n)
{
	vector<int> temp;
	int counter = 100;
	for (int i = 0; i < n; ++i)
		temp.push_back(counter++);  
	
	return temp;
}


int main()
{
	/*Q1*/
	int* ten_i = new int[10];
	
	
	/*Q2*/
	for(int i=0; i<10; i++)
	cout << ten_i[i] << endl;
	
	
	/*Q3*/ 
	delete[] ten_i;
	
	
	/*Q4*/
	//print_array10(cout, ten_i);
	//delete[] ten_i;	// task4 done
	
	
	
	/*Q5*: Allocate an array of ten ints on the free store; initialize it with the values 100,101, 102, etc.; and print out its values*/
	
	int* ten_ii = new int[10] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	print_array10(cout, ten_ii);
	//delete[] ten_ii
	
	
	
	/*Q6*/
	int* eleven_i = new int[11] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};  // of 11 elements
	print_array11(cout, eleven_i);
	//delete[] eleven_i;
	
	
	/*Q7: Check Ln 34*/
	
	
	/*Q8*/
	int* twenty_i = new int[20] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
	print_array(cout, twenty_i, 20);
	//delete[] twenty_i;
	
	
	/*Q9: =) */
	
	/*Q10*/
	cout << "using Vector of ten" << endl;
	vector<int> v_ten_i = allocateVector(10);
	printVector(v_ten_i);
	
	cout << "using Vector of eleven" << endl;
	vector<int> v_eleven_i = allocateVector(11);
	printVector(v_eleven_i);
	
	cout << "using Vector of twenty" << endl;
	vector<int> v_twenty_i = allocateVector(20);
	printVector(v_twenty_i);
	
	

return 0;
}

