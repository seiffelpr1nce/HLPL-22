// Drill 9 Q4
// Seif Ahmed Mohamed Ahmed - GC39OP


#include "std_lib_facilities.h"


 enum class Month {
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
  	 	   };

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}
vector<string> months {
	"January" , "February" , "March" , "April",	"May" , "June" , "July" , "August" , "September" , "October" , "November" , "December"
};

ostream& operator<<(ostream& os, Month m)  	//define output operator
{
	return os << months[int(m)];  // int is essential 

}

class Date {
private:
	int y,d;
	Month m;
			// Implementation or Class members 
	
	bool is_valid()
	{
		if (y < 0 ||  d < 1 || d > 31) return false;
			
			return true;				
	}

public:
	Date(): y(2001), m(Month::jan), d(1) {}	// Default value

	Date(int yy, Month mm, int dd): y(yy), m(mm), d(dd)
	{
		if (!is_valid()) error("Invalid date");
			
		
	}
			// Constructor , Instanciation
	int get_year()  { return y; }
	Month get_month()  { return m; }
	int get_day()  { return d; }
	void set_year (int yy) 
	{ 
		if (yy < 0) error ("Invalid year");
		y = yy; 	
	}
	void set_month (Month mm) 
	{
		m = mm;
	}
	void set_day (int dd) 
	{ 
		if (dd < 1  || dd > 31) error ("Invalid day");
		d = dd; 
	}
	void add_day(int n)
	{
		d+=n;
		if (d > 31)
		{
			d=1;
			++m;
			if (m == Month::jan)
			{
				++y;
			}
		}
	}
			// Interface of the class 		
			
}; // ";" must follow clases and structs





	ostream& operator<<(ostream& os, Date& date)
	
{
	return os << date.get_year() << "-" << date.get_month() << "-" << date.get_day() << " ";
}



 
	int main()
	
try {
	Date today (1978, Month::jun, 25);
	cout << Today is: << today << endl;		// check today 
	
	Date tomorrow = today; 
	tomorrow.add_day(1);  	// add 1 to today to become tomorrow 
	cout << Tomorrow is:  << tomorrow << endl;	// print tomorrow 
	
	Date invalid(2004, Month::apr, -5);		// for Invalid dates
	cout << invalid << endl;
		
	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}
