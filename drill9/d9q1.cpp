// Drill 9 Q1
// Seif Ahmed Mohamed Ahmed - GC39OP

#include "std_lib_facilities.h"



struct Date{
	int y;
	int m;
	int d;
	    };



void init_date(Date& date, int yy, int mm, int dd)
{
	if (yy < 0 || mm < 0 || mm > 12 || dd < 1  || dd > 31)
		error ("Invalid date"); 
	
		date.y = yy;
		date.m = mm;
		date.d = dd;
		
	
}



void add_day(Date& date, int n)
{
	
	date.d += n;		// add n-days to date
}



ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.y << '-' << d.m << '-' << d.d ;
	
}



int main()
try {
	Date today;		// for checking valid values
	Date invalid;		// for checking invalid values
	
	init_date(today, 1978, 6, 25);	
	
	Date tomorrow(today);

	add_day(tomorrow, 1);  // add 1 to today to become tomorrow 

	cout << today << endl;
			
	cout << tomorrow << endl;

	// for invalid date
		
	init_date(invalid, 2004, 13, -5);
	
	cout << invalid << endl;

	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}
