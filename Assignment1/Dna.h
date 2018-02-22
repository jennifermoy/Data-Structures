#include <iostream>

using namespace std;

class Dna {

	public:
		Dna();
		~Dna();
		void dnaString(ifstream& inStream);
		void calculations(ofstream& outStream);
		void probability(ofstream& outStream);
		float calcGaussianDist();
		void generateDna(ofstream& outStream);
};
