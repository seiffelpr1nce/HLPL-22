// Drill 9 Q2
// Seif Ahmed Mohamed Ahmed - GC39OP
  
#include "std_lib_facilities.h"


struct Date
  {
	int y, m, d;
	

Date(int yy, int mm, int dd)
 {
	if (yy < 0 || mm < 1 || mm > 12 || dd < 1  || dd > 31)
		error ("Invalid date input");  
	
		y = yy;
		m = mm;
		d = dd;
		
 }




void add_day( int n)
	{
	d=d+n;	// to increase date by ndays
	}
  }; // ';'is obligatory after structs


	ostream& operator<<(ostream& os, const Date& d)

     {
		return os << d.y << '-' << d.m << '-' << d.d ;
     }



int main()
try 
 {
	// initiallizing today
	Date today = {1978, 6, 25};
	cout << " Today is: " << today << endl;
	
	//checking tomorrow
	Date tomorrow = today; //to give tomorrow's same value as today then add n over it
	tomorrow.add_day(1);  // in that case n is 1 
	cout << " Tomorrow is: " << tomorrow << endl;   // print tomorrow ( today+1)
 		
	
	//checking invalid date
		
	Date invalid = {2004, 13, -5};
	cout << invalid << endl;
	
	
	
		return 0;
 }
 catch (exception& e)
{
	cerr << e.what() <<endl;
		return 1;
}
