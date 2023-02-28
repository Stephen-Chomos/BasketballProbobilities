#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	double freeThrow = 0.0;
	double threePt = 0.0;
	bool cont = true;
	int threeInt;
	int freeThrowInt;
	
	cout << "Welcome to the matrix decision maker: Version 1.0" << endl;
	
	int matrix[101][101];
	
	
	cout << "Note: Only works for whole numbers and 3 pointers in V 1.0. Will count on it being a 3-point game Round up for best results. 1 is foul. 2 is no foul. 3 is same percentage" << endl;
	
	for(int i = 0; i < 101; ++i) {
		for (int y = 0; y < 101;++y) {
			freeThrow = static_cast<double>(i);
			threePt = static_cast<double>(y);
			freeThrow = freeThrow / 100;
			threePt = threePt / 100;
			freeThrow = freeThrow * freeThrow * freeThrow;
			if (freeThrow < threePt) {
				matrix[i][y] = 1;
			}
			else if (freeThrow == threePt) {
				matrix[i][y] = 3;
			}
			else {
				matrix[i][y] = 2;
			}
		}
	}//END of creation of Matrix
	
	//Printing the matrix
	
	cout << "Printing matrix:" << endl;
	cout << "3PT | ";
	for(int i = 0; i < 101; ++i) {
		cout << i << " |";
	}
	cout << endl;
	cout << "FT:";
	for (int i = 0; i < 101; ++i){
	cout << i << " |";
		for (int y = 0; y < 101; ++y) {
		cout << matrix[i][y] << " |";
		}
		cout << endl;
	}
	
	while (cont == true) {
		int checker = 0;
		char contChar;
		cout << "Please input whole number of players 3PT percentage: ";
		cin >> threeInt;
		cout << "Please input whole number of players FT percentage: ";
		cin >> freeThrowInt;
		
		if(freeThrowInt >= 0 || freeThrowInt <= 100 || threeInt >= 0 || threeInt <= 100) {
			checker = matrix[freeThrowInt][threeInt];
			switch (checker) {
				case 1:
				cout << "You should statistically foul the shooter" << endl;
				break;
				case 2:
				cout << "You should statistically NOT foul the shooter" << endl;
				break;
				case 3:
				cout << "It is a statistical push" << endl;
				break;
				
			}
		}
		
		else {
			cout << "Error invalid input" << endl;
		}
		cout << "Continue y/n:";
		cin >> contChar;
		
		if (contChar == 'n' || contChar == 'N') {
			cont = false;
		}
		
	}
}