#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const int Months = 12;
	string name[Months] = { "January","Feburary","March","April","May","June","July","August","September","October","November","December" };
	int count = 0;
	double rain[Months];
	double avg;
	double year = 0;
	double highest;
	string highMonth;
	double lowest;
	string lowMonth;

	for (count = 0; count < Months; count++)
	{
		cout << "How many inches of rain does " << name[count] << " have? \n";
		cin >> rain[count];
		while (rain[count]<0)
		{
			cout << "Please enter a number greater than 0." << endl;
			cin >> rain[count];
		}
	}

	highest = rain[0];
	highMonth = name[0];
	lowest = rain[0];
	lowMonth = name[0];

	for (count = 1; count < Months; count++)
	{
		if (rain[count] > highest)
		{
			highMonth = name[count];
			highest = rain[count];
		}
		 if (rain[count] < lowest)
		{
			lowMonth = name[count];
			lowest = rain[count];
		}
	}
	

	

	for (count = 0; count < Months; count++)
	{
		year += rain[count];
		cout << name[count] << " has " << rain[count] << " inches of rainfall.\n";
	}
	avg = year / Months;
	cout << endl << setprecision(2) << fixed;
	cout << "Total Rainfall throughout the year is " << year << " inches" << endl;
	
	cout << "The average monthly rainfall is " << avg << " inches" << endl;
	cout << "The month with the highest amount of rainfall is " << highMonth << " with " << highest << " inches." << endl;
	cout << "The month with the lowest amount of rainfall is " << lowMonth << " with " << lowest << " inches." << endl;

	
	
	cout << endl;
	system("pause");
	return 0;
}
