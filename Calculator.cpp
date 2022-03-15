#include "std_lib_facilities.h"

constexpr char number = '8'; // 8 means it is a number and the value dose not metter
constexpr char quit = 'x'; // x is no longer a variable, but for quitting the program
constexpr char print = ';';   // about  Q3-Drill 6,  we can not change ';' to '=' because we have already declared it with char
constexpr char result = '=';
//constexpr char let = 'L';
constexpr char name = 'a';
const string declkey = "#"; // declaration keyword from let to '#'
constexpr char sq = 's';
const string square_root = "sqrt"; // square-root function
constexpr char power = 'p';
const string power_s = "pow"; // power function
const string quitkey = "exit"; 


double expression();
double term();
double primary();

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var)
{
	for (auto v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name(string var, double val)
{
	if (is_declared(var)) error("declared twice");
	var_table.push_back(Variable{ var,val });
	return val;
}

double get_value(string var)
{
	for (auto v : var_table)
		if (v.name == var) return v.value;
	error("Variable not found");
	return 0;
}

void set_value(string var, double val)
{
	for (auto& v : var_table)
		if (v.name == var)
		{
			v.value = val;
			return;
		}
	error("Variable not defined");
}

class Token {
public:
	char kind;
	double value;
	string name;
	Token() : kind(0) {}
	Token(char ch) : kind(ch), value(0) {}
	Token(char ch, double val) : kind(ch), value(val) {}
	Token(char ch, string n) : kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() : full(false), buffer(0) {}

void Token_stream::putback(Token t) {
	if (full) error("Token_stream buffer is full");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case quit:
	case print:

	case '(':
	case ')':

	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ',':
		//case 'p':

	case '#':
	case '=':
		return Token(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5':
	case '6': case '7': case '8': case '9': case '.':
	{
		cin.putback(ch);
		double val = 0;
		cin >> val;
		return Token(number, val);
	}
	default:
	{
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token('#');
			if (s == square_root) return Token(sq);
			if (s == power_s) return Token(power);
			if (s == quitkey) return Token(quit);

			else if (is_declared(s))
				return Token(number, get_value(s));
			return Token(name, s);
		}
		error("Bad token");
		return 0;
	}
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("variable name expected");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= expected in declaration");

	double d = expression();
	define_name(var_name, d);
	return d;
}
// function to calculate the square root
double square()
{
	double d = expression();
	if (d < 0) error("number is negative!"); // the number can not br negative and if the number is negative it shows error
	return sqrt(d);

}
// function to calculate the power >>>> pow(x,i) is Multiply x with itself i-times
double POWER()
{
	Token t1 = ts.get();
	if (t1.kind != '(') error(" ( expected !"); // we get '(' first because we have pow 

	double x = expression();
	Token t = ts.get();
	if (t.kind != ',') error(" , expected !"); // we put comma between the numbers to separate them
	double i = narrow_cast<int>(expression()); // casting to int because the power should be an integer


	Token t2 = ts.get();
	if (t2.kind != ')') error(" ) expected !"); //get ')' as a token to make sure it is the end of the function and we have no more inputs

	return pow(x, i);

}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '#':
		return declaration();
	case sq:
		return square();
	case power:
		return POWER();

	default:
		ts.putback(t);
		return expression();
	}
}


void calculate()
{
	while (cin)
		try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try {

	cout << "Welcome to our simple calculator\n - Please enter expressions useing floating-point numbers" << endl;
	cout << "- You can use the following operators (+, -, *, /, % , sqrt(num), pow(num,num)) followed by ; then press enter to print\n - you can exit the program by writeing x or exit and you can not use x as variable  \n";

	define_name("pi", 3.1415926535);
	define_name("k", 1000);  //predifind number k = 1000 

	calculate();

	return 0;

}
catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "Some error\n";
	return 2;
}

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		Token t = ts.get();

		if (t.kind != ')') error(") expected!");

		return d;
	}
	case number:
		return t.value;
	case '-':
		return -primary();
	case '+':
		return primary();
		/*case 'p':
		{
			double x = expression();
			int i = expression();

			return pow(x,i);
		}*/

	default:
		error("primary expected");
		return 0;
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
			left /= primary(); // primary == 0?
			t = ts.get();
			break;
		case '%':
		{
			
			/*
			double d = primary();
			if (d==0) error("Zero divider in %");
			left = fmod(left, d);
			t = ts.get();
			break;
			*/
			
			
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary());
			if (i2 == 0) error("Zero divider in %");
			left = i1 % i2;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}
