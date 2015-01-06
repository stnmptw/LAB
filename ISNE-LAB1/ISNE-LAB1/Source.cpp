#include <iostream>

using namespace std;
double calculate(double,double,double,double);
double dateDis(double);
double discout(double,double);
int main()
{
	int x = 0, count = 0,mem;
	double  minimum = 0, load = 0;
	while (x != -1)
	{
		cout << "Welcome 1 to continue -1 to end" << endl;
		cin >> x;
		if (x != -1)
		{
			double width, high, deep, weigh, date, hold, price;
			cout << "Enter Width :";
			cin >> width;
			cout << "Enter High :";
			cin >> high;
			cout << "Enter Deep :";
			cin >> deep;
			cout << "Enter Weigh";
			cin >> weigh;
			cout << "Date arrival :";
			cin >> date;
			price = calculate(width, high, deep, weigh) - dateDis(date);
			load = load + price;
			if (count == 0)
			{
				minimum = price;
			}
			
				hold = price;
			
			if (minimum > hold )
			{
				minimum = hold;
			}
			count++;
		}
	}
	cout << "Real Total : " << load << endl;
	cout << "Do you have a member card (1=have ,0= don't) : ";
	cin >> mem;
	if (count >=3 && mem == 1)
	{
		cout << "Total For Member :" << discout(minimum, load) << endl;
	}
	else
	{
		cout << "Total : " << load << endl;
	}
	
}
double calculate(double a, double b, double c,double d)
{
	a = a*2.54;
	b = b*2.54;
	c = c*2.54;
	d = d*0.00220462262;

	double price = ((a*c * 2) + (b * 4)) * 10 * d;
	return price;
}
double dateDis(double a)
{
	if (a > 10 && a<30)
	{
		a = a - 10;
	}
	else if (a > 30)
	{
		a = (a - 20) * 2;
	}
	return a;
}
double discout(double a, double b)
{
	a = (a * 20 / 100);
	b = b - a;
	if (b < 0)
	{
		return 0;
	}
	else
	{
		cout << "Discout : " << a << endl;
		return b;
	}
	
}