#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#include "person.cpp"

int readData(Person P[], string fileName, const int SIZE, int &numPeople)
{
  string fName;
  string lName;
  float  hours;
  float  pay;

  ifstream inFile;
  inFile.open("input.txt");

  if (inFile.is_open())
  {
    cout << "File opened successfully ...\n" << endl;

    while(inFile >> fName && numPeople < SIZE)
    {
      inFile >> lName >> hours >> pay;

      P[numPeople].setFirstName(fName);
      P[numPeople].setLastName(lName);
      P[numPeople].setHoursWorked(hours);
      P[numPeople].setPayRate(pay);

      numPeople++;
    }
    inFile.close();
  }
  else
    cout << "ERROR: could not open file ..." << endl;

    return numPeople;
}


void writeData(Person P[], string fileName, int numPeople)
{
  ofstream outFile;
  outFile.open(fileName);

  for(int i = 0; i < numPeople; i++)
  {
    outFile << P[i].fullName() << " " << fixed << setprecision(2) << P[i].totalPay() << endl;
    cout << P[i].fullName() << endl;
  }
  outFile.close();
}


int main()
{
  int numPeople = 0;
  const int SIZE = 20;
  // create an array of 20 empty people
  Person employees[SIZE];

  // read the data from file into the array
  readData(employees, "input.txt", SIZE, numPeople);
  // write data to an output file
  writeData(employees, "output.txt", numPeople);

  return 0;
}
