// Drill 9 Q3
// Seif Ahmed Mohamed Ahmed - GC39OP
#include "std_lib_facilities.h"
  class Date
  {
  private:
  
  	int y, m, d; 		// Implementation or Class members 
  
  public:
  	
  	Date( int y, int m, int d);
  	void add_day(int n);
  	int month() const { return m; }
  	int day() const { return d; }
  	int year() const { return y; }
  	
  };
  	
  Date::Date(int yy, int mm, int dd): y{yy}, m{mm}, d{dd}
  
  {
  	if (yy < 0 || mm < 1 || mm > 12 || dd < 1  || dd > 31) error ("Invalid Input");	
  }
  
  	void Date::add_day (int n)
   {
  		d+=n;
  		if (d > 31) d %= 31;
   }
   	ostream& operator <<(ostream& os, const Date& d)
     {
		return os << d.year() << '-' << d.month() << '-' << d.day() ;
     }
     
     	int main()
try
 { 
 	// initiallizing today
    Date today(1978, 6, 25);
    cout << "Today is: " << today << '\n';
    
    Date tomorrow = today;
    tomorrow.add_day(1); // add 1 to tomorrow 
    cout << "Tomorrow is: " << tomorrow << '\n'; // print tomorrow ( today+1)
   
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
  
  
