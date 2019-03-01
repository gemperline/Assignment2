#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "person.cpp"

void readData(string fileName)
{
  ifstream inFile;
  inFile.open(fileName);
  string input;

  for(int i = 0; i < numRecords; i++)
  {
    inFile >> employees.setFirstName() >> employees.setLastName() >> employees.setHoursWorked() >> employees.setPayRate();
  
  }
}

int main()
{
  ifstream inFile;
  inFile.open("input.txt");

  int numPersons = 0;Person::Person()
{
  inFile.open("input.txt");
  << "file opened" << endl
);
  string line;

  if(inFile.is_open())
  {
    cout << "File opened successfully" << endl;

    while(getline(inFile, line))
    {
      numPersons++;
    }
    inFile.close();
  }
  else
  {
    cout << "ERROR: file not opened" << endl;
  }

//  inFile.open();

// create a array of 20 empty people
  Person employees[20];

  for(int i = 0; i < numPersons; i++)
  {
    employees[i].getFirstName();
    employees[i].getLastName();
    employees[i].getHoursWorked();
    employees[i].getPayRate();
  }



//  inFile.close();

  return 0;
}
