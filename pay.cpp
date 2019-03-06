#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "person.cpp"

void readData(Person P[], string fileName, const int SIZE)
{
  string fName;
  string lName;
  float  hours;
  float  pay;
  int numPersons = 0;

  ifstream inFile;
  inFile.open("input.txt");

  if (inFile.is_open())
  {
    cout << "File opened successfully ..." << endl;

    while(inFile >> fName && numPersons < SIZE)
    {
      inFile >> lName >> hours >> pay;

      P[numPersons].setFirstName(fName);
      P[numPersons].setLastName(lName);
      P[numPersons].setHoursWorked(hours);
      P[numPersons].setPayRate(pay);

      cout << P[numPersons].getFirstName() << endl;
      numPersons++;
    }
    cout << "Number of people: " << numPersons << endl;

    inFile.close();
  }
  else
    cout << "ERROR: could not open file ..." << endl;
}


void writeData(Person P[], string fileName, const int SIZE)
{
  ofstream outFile;
  outFile.open(filename);

  for(int i = 0; i < SIZE; i++)
  {
    outFile << P[i].fullName << P[i].totalPay << endl;
  }
}


int main()
{
  const int SIZE = 20;
  // create an array of 20 empty people
  Person employees[SIZE];

  // read the data from file into the array
  readData(employees, "input.txt", SIZE);

  // write data to an output file
  writeData(employees, "output.txt", SIZE);

  return 0;
}
