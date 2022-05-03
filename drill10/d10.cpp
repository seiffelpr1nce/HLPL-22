//Drill 10
// Seif Ahmed Mohamed Ahmed - GC39OP

#include "std_lib_facilities.h"


struct Point 
{
	int x;
	double y;
};

istream& operator>> (istream& is, Point& p)
    {
	
	int x1,y1;
	char ch1, ch2, ch3;
	is >> ch1 >> x1 >> ch2 >> y1 >> ch3 ;

	if(!is) return is;
	
	if(ch1 != '(' || ch2 != ',' || ch3 != ')') 	// Error handling
	{
		is.clear(ios_base::failbit);
		return is;
	}
	
	p.x = x1;
	p.y = y1;
	
	return is;
    }

ostream& operator<<(ostream& os, Point& p)
  {
    return os << '(' << p.x << ',' << p.y << ')';
  }

void fill_from_file(vector<Point>& points, string& name)
{
    ifstream ist {name};
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    if (!ist) error("can't open input file ", name);
    for (Point p; ist >> p; )
        points.push_back(p);
}

int main()
try {

	string ifname;
	
	cout << " enter seven pairs of coordinates in the form of (x,y)\n";
 	
 	vector<Point> points;

	while (points.size() < 7) {
        	Point p;
        	cin >> p;
        	points.push_back(p);
    		    } 
        
	 for (Point p : points)
        	cout << p << endl;
    		
	
	string fname = "mydata.txt";
		
	

	ofstream ofs { fname };

	if ( !ofs ) error ("Unable to open file: ", fname);
	
	for (const auto& p : points)
	ofs <<'(' << p.x << ',' << p.y << ')' << endl;
	
		
	vector<Point> processed_points;
	fill_from_file(processed_points, fname);

	for (Point p : processed_points)
        cout << p << endl;

	if (points.size() != processed_points.size())
       cout << "Something's wrong!\n";
	
	return 0;

	}
	 catch (exception& e)
{
		cerr << e.what() << endl;
	return 1;
	}
