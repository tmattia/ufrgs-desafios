#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> panc;

void flip(int p) {
	vector<int> newp;

	for (int i = 0; i < p; i++) {
		newp.push_back(panc[i]);
	}
	
	for (int i = panc.size()-1; i >= p; i--) {
		newp.push_back(panc[i]);
	}
	
	panc = newp;
	
}	

int main() {
	int flips[61];
	char l[256];
	
	int maior, pos, qtfl;
	
	string s;
	istringstream iss;
	vector<int> rev;
		
	while (!cin.eof()) {
		rev.clear();
		panc.clear();

		getline(cin, s);
		iss.clear();
		iss.str(s);
		copy(istream_iterator <int> (iss), istream_iterator <int> (), back_inserter(rev));
		
		for (int i = rev.size()-1; i >= 0; i--) {
			panc.push_back(rev[i]);
		}
		qtfl = 0;
		for (int i = 0; i < panc.size(); i++) {
				maior = 0;
				pos = 0;
				
				for (int j = i; j < panc.size(); j++) {
					if (panc[j] > maior) {
						maior = panc[j];
						pos = j;
					}
				}
				
				if (pos != i) {
				
					if (pos != panc.size()-1) {
						//flip pancakes
						flip(pos);
						flips[qtfl] = pos+1;
						qtfl++;
					}
					
					flip(i);
					flips[qtfl] = i+1;
					qtfl++;
				}
			}
			for (int i = 0; i < rev.size(); i++) {
			cout << rev[i] << " ";
		}
		cout << endl;
			
		for (int i = 0; i < qtfl; i++) {
			cout << flips[i] << " ";
		}
		cout << "0" << endl;
	}
	
	return 0;
}
