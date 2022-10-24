#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxrow = 10;

string EmpName[maxrow] = {};
string EmpID[maxrow] = {};
string Depart[maxrow] = {};
string Salary[maxrow] = {};

void AddRecord()
{
	char name[50];
	char empno[5];
	char depart[60];
	char salary[999999];

	cin.ignore();

	cout << "Employee ID,";
	cin.getline(empno, 5);
	cout << "Employee name,";
	cin.getline(name, 50);
	cout << "Employee Department,";
	cin.getline(depart, 60);
	cout << "Employee Salary,";
	cin.getline(salary, 999999);


	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] == "\0")
		{
			EmpID[x] = empno;
			EmpName[x] = name;
			Depart[x] = depart;
			Salary[x] = salary;

			break;
		}
	}
}

void ListRecord()
{
	system("CLS");
	cout << "Employee Record's" << endl;
	cout << "==============================" << endl;

	int counter = 0;
	cout << "No. | ID  |    NAME  |   Department |  Salary  " << endl << "---------------\n";
	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] != "\0")
		{	
		counter++;
		cout << "   " << counter << "   " << EmpID[x] << "        " << EmpName[x] << "      " << Depart[x]<< "      "<< Salary[x]<<endl;

	}
}

if (counter == 0)
{
	cout << "No Record Found" << endl;
		
}
cout << " ============================" << endl;

}

void SearchRecord(string search)
{
	system("CLS");
	cout << "Current Record's" << endl;
	cout << "===============================" << endl;
	int counter = 0;
	for (int x = 0; x < maxrow; x++)
	{
		
		if (EmpID[x] == search)
		{
			counter++;
			cout << "   " << counter << "   " << EmpID[x] << "        " << EmpName[x] << "      " << Depart[x] << "      " << Salary[x] << endl;
			break;
		}
	}
	
	if (counter==0)
	{
		cout << "No Record Found" << endl;

	}
	cout << " ============================" << endl;

}

int main()
{
	std::cout << "menu\n";
	int option;
	string EmpID;
	system ("CLS");
	do {
		cout << "1- Create Records" << endl;
		cout << "2- Update Records" << endl;
		cout << "3- Delete Records" << endl;
		cout << "4- Search Records" << endl;
		cout << "5- Display Records" << endl;
		cout << "6- Exit" << endl;
		cout << "===========================" << endl;

		cout << "Select option>>";
		cin >> option;

		switch (option)
		{
			case 1: AddRecord();
				system("CLS");
				break;
			case 4:
				cin.ignore();
				cout << "Search by ID >>";
				getline(cin, EmpID);
				SearchRecord(EmpID);
				break;
			case 5: ListRecord();
				break;
			

		}
	} while (option != 6);
}