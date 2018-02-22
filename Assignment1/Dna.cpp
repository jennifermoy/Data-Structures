#include "Dna.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

string dna;

double nucleoCount = 0.0;
double nucleoTotal = 0.0;
int countLine;
double sum = 0, mean = 0, variance = 0, stdDev = 0, sumvar = 0;

int numA = 0, numC = 0, numT = 0, numG = 0;
int numAA = 0, numAC = 0, numAT = 0, numAG = 0, numCA = 0, numCC = 0, numCT = 0, numCG = 0;
int numTA = 0, numTC = 0, numTT = 0, numTG = 0, numGA = 0, numGC = 0, numGT = 0, numGG = 0;

double probA = 0, probC = 0, probT = 0, probG = 0;
double probAA = 0, probAC = 0, probAT = 0, probAG = 0, probCA = 0, probCC = 0, probCT = 0, probCG = 0;
double probTA = 0, probTC = 0, probTT = 0, probTG = 0, probGA = 0, probGC = 0, probGT = 0, probGG = 0;

double a = 0, b = 0, c = 0, d = 0;

float tempD;
int tempRand = 0;

Dna::Dna() //constructor
{

}

Dna::~Dna() //deconstructor
{
  cout << "Object Deleted" << endl;
}

//putting the file information into a string variable
void Dna::dnaString(ifstream& inStream)
{
  countLine = 0;
	char c;
	while(!inStream.eof())
  {
    if(c == '\n')
    {
			countLine++;
		}
		inStream.get(c);
		dna += c;
	}
}

//calculations
void Dna::calculations(ofstream& outStream)
{
  int count = 0;
  double nucleoCount = 0;

  //calculating the sum and mean
  for (int i = 0; i < dna.size(); ++i)
  {
    if (dna[i] != '\n')
    {
      nucleoTotal++;
    }
    else
    {
      count++;
			if(count == countLine)
      {
        sum = nucleoTotal;
				mean = sum / countLine;
				count = 0;
				break;
      }
    }
  }

  outStream << "Sum is " << sum << endl;
  outStream << "Mean is " << mean << endl;

  //calculating the variance and standard deviation
  for(int j = 0; j < dna.size(); ++j)
  {
		if(dna[j] != '\n') {
			nucleoCount += 1;
		}
		else
    {
			variance += ((mean - nucleoCount) * (mean - nucleoCount));
			nucleoCount = 0;
			count += 1;
			if(count == countLine) {
				variance = variance / countLine;
				stdDev = sqrt(variance);
				break;
			}
		}
	}

  outStream << "Variance is " << variance << endl;
  outStream << "Standard Deviation is " << stdDev << endl;
}

//calculating the probability of each nucleotide and bigram
void Dna::probability(ofstream& outStream)
{
  for (int i = 0; i < dna.size(); ++i)
  {
    if (dna[i] == 'A' || dna[i] == 'a')
    {
      numA++;
      if (dna[i + 1] == 'A' || dna[i + 1] == 'a')
      {
        numAA++;
      }
      else if (dna[i + 1] == 'C' || dna[i + 1] == 'c')
      {
        numAC++;
      }
      else if (dna[i + 1] == 'T' || dna[i + 1] == 't')
      {
        numAT++;
      }
      else if (dna[i + 1] == 'G' || dna[i + 1] == 'g')
      {
        numAG++;
      }
    }

    else if (dna[i] == 'C' || dna[i] == 'c')
    {
      numC++;

      if (dna[i + 1] == 'A' || dna[i + 1] == 'a')
      {
        numCA++;
      }
      else if (dna[i + 1] == 'C' || dna[i + 1] == 'c')
      {
        numCC++;
      }
      else if (dna[i + 1] == 'T' || dna[i + 1] == 't')
      {
        numCT++;
      }
      else if (dna[i + 1] == 'G' || dna[i + 1] == 'g')
      {
        numCG++;
      }
    }

    else if (dna[i] == 'T' || dna[i] == 't')
    {
      numT++;

      if (dna[i + 1] == 'A' || dna[i + 1] == 'a')
      {
        numTA++;
      }
      else if (dna[i + 1] == 'C' || dna[i + 1] == 'c')
      {
        numTC++;
      }
      else if (dna[i + 1] == 'T' || dna[i + 1] == 't')
      {
        numTT++;
      }
      else if (dna[i + 1] == 'G' || dna[i + 1] == 'g')
      {
        numTG++;
      }
    }

    else if (dna[i] == 'G' || dna[i] == 'g')
    {
      numG++;

      if (dna[i + 1] == 'A' || dna[i + 1] == 'a')
      {
        numGA++;
      }
      else if (dna[i + 1] == 'C' || dna[i + 1] == 'c')
      {
        numGC++;
      }
      else if (dna[i + 1] == 'T' || dna[i + 1] == 't')
      {
        numGT++;
      }
      else if (dna[i + 1] == 'G' || dna[i + 1] == 'g')
      {
        numGG++;
      }
    }
  }

//calculating the probabilities of each nucleotide and bigram
  probA = ((double)(numA / sum) * 100);
  probC = ((double)(numC / sum) * 100);
  probT = ((double)(numT / sum) * 100);
  probG = ((double)(numG / sum) * 100);

  double bigramTotal = sum - countLine;
  probAA = ((double)(numAA / bigramTotal) * 100);
  probAC = ((double)(numAC / bigramTotal) * 100);
  probAT = ((double)(numAT / bigramTotal) * 100);
  probAG = ((double)(numAG / bigramTotal) * 100);
  probCA = ((double)(numCA / bigramTotal) * 100);
  probCC = ((double)(numCC / bigramTotal) * 100);
  probCG = ((double)(numCG / bigramTotal) * 100);
  probCT = ((double)(numCT / bigramTotal) * 100);
  probTA = ((double)(numTA / bigramTotal) * 100);
  probTC = ((double)(numTC / bigramTotal) * 100);
  probTT = ((double)(numTT / bigramTotal) * 100);
  probTG = ((double)(numTG / bigramTotal) * 100);
  probGA = ((double)(numGA / bigramTotal) * 100);
  probGC = ((double)(numGC / bigramTotal) * 100);
  probGT = ((double)(numGT / bigramTotal) * 100);
  probGG = ((double)(numGG / bigramTotal) * 100);

//printing the probabilities to the out file
  outStream << "\nProbability of A: " << probA << "%" << endl;
  outStream << "Probability of C: " << probC << "%" << endl;
  outStream << "Probability of T: " << probT << "%" << endl;
  outStream << "Probability of G: " << probG << "%" << endl;

  outStream << "\nProbability of AA: " << probAA << "%" << endl;
  outStream << "Probability of AC: " << probAC << "%" << endl;
  outStream << "Probability of AT: " << probAT << "%" << endl;
  outStream << "Probability of AG: " << probAG << "%" << endl;
  outStream << "Probability of CA: " << probCA << "%" << endl;
  outStream << "Probability of CC: " << probCC << "%" << endl;
  outStream << "Probability of CG: " << probCG << "%" << endl;
  outStream << "Probability of CT: " << probCT << "%" << endl;
  outStream << "Probability of TA: " << probTA << "%" << endl;
  outStream << "Probability of TC: " << probTC << "%" << endl;
  outStream << "Probability of TT: " << probTT << "%" << endl;
  outStream << "Probability of TG: " << probTG << "%" << endl;
  outStream << "Probability of GA: " << probGA << "%" << endl;
  outStream << "Probability of GC: " << probGC << "%" << endl;
  outStream << "Probability of GT: " << probGT << "%" << endl;
  outStream << "Probability of GG: " << probGG << "%" << endl;

  outStream << endl;
}

float Dna::calcGaussianDist()
{
  a = ((double) rand() / (RAND_MAX));
  b = ((double) rand() / (RAND_MAX));
  c = (sqrt(-2 * log(a))) * (cos(2 * (M_PI) * b));
  d = (stdDev * c) + mean;

  return d;
}

//generating 1000 DNA strands that follow the gaussian distribution
void Dna::generateDna(ofstream& outStream)
{
  string genDNA = "";

  outStream << "1000 Generated DNA Strings based on the Gaussian Distribution: " << endl;
  outStream << endl;

  for (int i = 0; i < 1000; ++i)
  {
    genDNA = "";
    tempD = calcGaussianDist();
    while(genDNA.length() <= tempD)
    {
      tempRand = rand() % 100 + 1;
      if(tempRand > 0 && tempRand < probA) {
				genDNA.append("A");
			}
			else if(tempRand > probA && tempRand < probA + probC) {
				genDNA.append("C");
			}
			else if(tempRand > probA + probC && tempRand < probA + probC + probT) {
				genDNA.append("T");
			}
			else if(tempRand > probA + probC + probT && tempRand < probA + probC + probT + probG) {
				genDNA.append("G");
			}
    }
    outStream << genDNA << endl;
  }
}
