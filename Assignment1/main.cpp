#include "Dna.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{

  ifstream inFile;
  ofstream outFile;

  outFile.open("JenniferMoy.txt");
  if (outFile.is_open())
  {
    outFile << "Jennifer Moy \n2253823 \nAssignment 1\n" << endl;
  }
  else
  {
    cout << "unable to open file" << endl;
  }

  bool user = true;
  
  while (true)
  {
    string fileName;
    cout << "enter file name: ";
    cin >> fileName;

    inFile.open(fileName.c_str());

    Dna test;

    test.dnaString(inFile);
    test.calculations(outFile);
    test.probability(outFile);
    test.generateDna(outFile);

    inFile.close();

    cout << "***File Processed***" << endl;

    while (user)
    {
      cout << "Do you want to input another file? (y/n)" << endl;
      string answer;
      cin >> answer;

      if (answer == "y" || answer == "Y")
      {
        break;
      }
      else if (answer == "n" || answer == "N")
      {
        inFile.close();
        return 0;
      }
      else
      {
        cout << "invalid input" << endl;
        continue;
      }
    }
  }

  return 0;
}
