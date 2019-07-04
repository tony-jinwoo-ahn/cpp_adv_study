// prj4 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;


int main(int argc, char** argv)
{
	if (argc != 3) {
		cout << "Error!" << endl;
		cout << "Usage: preprocessor input.txt result.txt" << endl;		
		return -1;
	}

	string input_file_name = argv[1];
	string output_file_name = argv[2];
	ifstream inFile(input_file_name);
	ofstream outFile(output_file_name);
	
	unordered_map<string, int> umap;
	string s;
		
	while (getline(inFile, s)) {
		istringstream iss(s);
		string word;		
		string word_key, word_val;

		if (s.find("define") != string::npos) {
			if ((iss >> word) && (word == "define")) {
				if (iss >> word) {
					word_key = word;
					if (iss >> word) {
						word_val = word;
						int number = std::stoi(word_val);
						umap[word_key] = number;
					}
				}
			}
		} else if (s.length() > 0) {			
			while (iss >> word) {
				if (umap.find(word) != umap.end()) {
					word = to_string(umap[word]);
				}
				outFile << word << " ";
			}
			outFile << endl;
		}
	}

	inFile.close();
	outFile.close();
	return 0;
}