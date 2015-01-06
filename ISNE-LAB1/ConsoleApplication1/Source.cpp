#include <iostream>

using namespace std;
double priceOfBook();
int discount();
int main()
{
	double *dnx;
	int x=0, m, swap,term = 0;
	dnx = (double *)malloc(term*sizeof(double));
	
	double thePrice;
	double total = 0, z, hold;
	cout << "Welcome to Ken's book shop" << endl;
	while (x != -1)
	{
		cout << "Now your cart have " << (term ) << " item" << " To continue please 1 or -1 to end" << endl;
		cin >> x;
		if (x == 1)
		{
			thePrice = priceOfBook() - discount();
			if (thePrice <= 0)
			{
				thePrice = 0;
			}
			dnx[term] = thePrice;
			term++;
		}


	}
	cout << "Do you have a member card ? (0 = dont'have ,1 = have a card) :";
	cin >> m;

	if (m == 1)
	{

		for (int i = 1; i < term; i++)
		{

			cout << "Book " << i << " " << dnx[i] << endl;
			total = total + dnx[i];

		}
		do{
			swap = 0;
			for (int i = 1; i < term - 1; i++)
			{
				if (dnx[i] > dnx[i + 1])
				{
					hold = dnx[i];
					dnx[i] = dnx[i + 1];
					dnx[i + 1] = hold;
					swap = 1;

				}
			}
		} while (swap == 1);

		z = dnx[0];



		if (z >0)
		{
			total = total - (z * 20 / 100);
			cout << "Discout " << z * 20 / 100 << endl;
		}

	}
	else{
		for (int i = 1; i < term; i++)
		{

			cout << "Book " << i << " " << dnx[i] << endl;
			total = total + dnx[i];

		}
	}
	if (total < 0){
		cout << "Free" << endl;
	}
	else{
		cout << "Total " << total;
	}
	
}
double priceOfBook(){
	double w, h, d, g, price;
	cout << "Width,High,Deep (Unit = inch Example 1 2 3) :";
	cin >> w >> h >> d;
	cout << "the weigh of this book(Unit gram) :";
	cin >> g;
	w = w*2.54;
	h = h*2.54;
	d = d*2.54;
	g = g*0.00220462;

	price = ((w*d * 2) + (h * 4)) * 10 * g;
	return price;
}
int discount(){
	int day, number, i = 0;
	do{
		cout << "How long this book arrival(Day) :";
		cin >> day;
		if (day<0)
		{
			cout << "Date Error Please try again \n";
			i = 0;
		}
		if (day <= 10 && day >= 0)
		{
			number = 0;
			i = 1;
		}
		if (day>10 && day <= 30)
		{
			number = day - 10;
			i = 1;
		}
		else if (day>30)
		{
			number = 20 + (day - 30) * 2;
			i = 1;
		}
	} while (i == 0);
	return number;

}