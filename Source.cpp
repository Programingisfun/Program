#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

//1. program
// structure to store information of each contact
struct Telephone
{
	string first_name;
	string last_name;
	string phone_number;
	string address;
	string city;
	string state;
	string postal_code;
	/*string Postal_code;*/
	void displayInfo()
	{
		cout << "\nFirst Name:" << first_name
			<< "\nLast Name:" << last_name
			<< "\t\nPhone Number:" << phone_number
			<< "\t\t\nAddress:" << address
			<< "\t\nCity:" << city
			<< "\t\nState:" << state
		    << "\t\nPostal code:" << postal_code << endl;

	}
};
// method to read from file and store in a vector
vector<Telephone> readFile()
{
	ifstream fin;
	vector<Telephone> v;
	fin.open("TelephoneDirectory.txt");
	if (!fin.is_open())
	{
		cout << "Error! File not found!\n";
	}
	else
	{
		string line;
		while (getline(fin, line))
		{
			stringstream iss(line);
			string firstName, lastName, phone_number, address, city, state,postalcode;
			iss >> firstName;
			iss >> lastName;
			iss >> phone_number;
			iss >> address;
			iss >> city;
			iss >> state;
			iss >> postalcode;
			Telephone tele = { firstName,lastName,phone_number,address,city,state,postalcode};
			v.push_back(tele);
		}
		fin.close();
		return v;
	}
}
// search for phone number in the vector
void searchPhoneNumber()
{
	vector<Telephone> v = readFile();
	string phoneNumber;
	cout << "Enter phone number you want to search: \n";
	cin.ignore(1);
	getline(cin, phoneNumber);
	for (int i = 0; i < v.size(); ++i) {
		if (v.at(i).phone_number.compare(phoneNumber) == 0) {
			cout << "Contact found!\n";
			cout << "Contact information is : \n";
			v[i].displayInfo();
			return;
		}
	}
	cout << "Contact not found!\n";
}
// Adds entry
// need more working on
void addEntry()
{
	vector<Telephone> v = readFile();
	string firstName;
	string lastName;
	string phoneNumber;
	cout << "Enter first name:";
	getline(cin, firstName);
	cin.ignore(1);
	for (int i = 0; i < v.size(); ++i) {
		if (v.at(i).first_name.compare(firstName) == 0) {
			cout << "Contact found!\n";
			cout << "Contact information is : \n";
			v[i].displayInfo();
			return;
		}
	}
	cout << "Contact not found!\n";

}



// search for contact that matches with last name
void searchLastName()
{
	vector<Telephone> v = readFile();
	string lastName;
	cout << "Enter last name you want to search: \n";
	cin.ignore(1);
	getline(cin,lastName);
	for (int i = 0; i < v.size(); ++i) {
		if (v.at(i).last_name.compare(lastName) == 0) {
			cout << "Contact found!\n";
			cout << "Contact information is : \n";
			v[i].displayInfo();
			return;
		}
	}
	cout << "Contact not found!\n";
}
// Deletes a contact entry
void deletenumber()
{
	vector<Telephone> v = readFile();
	string phoneNumber;
	cout << "What entry do you want to delete?(enter a phone.no): \n";
	cin.ignore(1);
	getline(cin, phoneNumber);
	for (int i = 0; i < v.size(); ++i) {
		if (v.at(i).phone_number.compare(phoneNumber) == 0) {
			cout << "Contact found!\n";
			cout << "Contact deleted!\n";
			v.erase(v.begin());
			return;
		}
	}
	cout << "Contact not found!\n";
	cout << "Unable to delete contact\n";
}



// main method
int main()
{
	int choice;
	while (true)
	{

		cout << "\t\t\t*** Phone Directory ***";
		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "\n\t\t1) *** Add a telephone directory entry ***\n";
		cout << "\n\t\t2) *** Search for an entry by name ***\n";
		cout << "\n\t\t3) *** Reverse number lookup ***\n";
		cout << "\n\t\t4) *** Delete an entry by phone number ***\n";
		cout << "\n\t\t5) *** Exit ***";
		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\tPlease Enter Your Choice (1-5): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addEntry();
			break;
		case 2:
			searchLastName();
			break;
		case 3:
			searchPhoneNumber();
			break;
		case 4:
			deletenumber();
			break;
		case 5:
			cout << "Have a nice day!";
			cout << "Thank You!\n";
			exit(1);
		default:
			cout << "Invalid option selected!\n";
		}
	}
}
//2.
//analysis:
//b.I chose to use a string as the data type for the directory because it is much easier to read in the names, number and address information from the text file

//c.I chose to use a struc and vector for the structure of the program.Because you can create data type that can be used under a single name.The reason is used a vector is that a vector has the ability to resize itself when data is inserted or deleted.

//d.The data structure that I chose is more efficient for my data structure for each function because I can create various string data types like the first name, last name, and phone number under the same struc name and use it where ever I want to use them.

//3.             
// output:
//*** Phone Directory ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//
//1) *** Add a telephone directory entry ***
//
//2) *** Search for an entry by name ***
//
//3) *** Reverse number lookup ***
//
//4) *** Delete an entry by phone number ***
//
//5) *** Exit ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Please Enter Your Choice(1 - 5) : 2
//Enter last name you want to search :
//Walder
//Contact found!
//Contact information is :
//
//First Name : Marge
//Last Name : Walder
//Phone Number : 312 - 840 - 3405
//Address : 670DrydenHill
//	City : Chicago
//	State : Illinois
//	Postal code : 60619
//	* ** Phone Directory ***
//*** Phone Directory ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//
//1) *** Add a telephone directory entry ***
//
//2) *** Search for an entry by name ***
//
//3) *** Reverse number lookup ***
//
//4) *** Delete an entry by phone number ***
//
//5) *** Exit ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Please Enter Your Choice(1 - 5) : 3
//Enter phone number you want to search :
//773 - 672 - 8385
//Contact found!
//Contact information is :
//
//First Name : Cissiee
//Last Name : Capponer
//Phone Number : 773 - 672 - 8385
//Address : 89BaysideTerrace
//	City : Chicago
//	State : Illinois
//	Postal code : 60624
//*** Phone Directory ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//
//1) *** Add a telephone directory entry ***
//
//2) *** Search for an entry by name ***
//
//3) *** Reverse number lookup ***
//
//4) *** Delete an entry by phone number ***
//
//5) *** Exit ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Please Enter Your Choice(1 - 5) : 4
//What entry do you want to delete ? (enter a phone.no) :
//	309 - 729 - 9076
//	Contact found!
//	Contact deleted!
//*** Phone Directory ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//
//1) *** Add a telephone directory entry ***
//
//2) *** Search for an entry by name ***
//
//3) *** Reverse number lookup ***
//
//4) *** Delete an entry by phone number ***
//
//5) *** Exit ***
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Please Enter Your Choice(1 - 5) : 5
//Have a nice day!Thank You!
//
//C : \Users\raide\Desktop\FinalProject\Debug\FinalProject.exe(process 452) exited with code 1.
//	Press any key to close this window . . .
//
