// Damian Strojek s184407
#include <iostream>
#include <string>
#include <vector>

void permutationWithoutRepetition(std::string& orig, std::string& perm);
void permutationWithRepetition(std::vector<std::string>&, std::string, std::string, const int);

int main(){
	std::string input;
	std::cin >> input;
	//std::string perm;
	//permutationWithoutRepetition(input, perm);
	
	int length = input.size();		// length of permutations
	std::vector<std::string> permutations;
	// Here we loop through all the possible lengths
	for (int i = 1; i <= length; i++)
		permutationWithRepetition(permutations, input, "", i);

	for (int i = 0; i < permutations.size(); i++)
		std::cout << permutations[i] << "\n";
	
	return 0;
}

void permutationWithoutRepetition(std::string& orig, std::string& perm) {
	if (orig.empty()) {
		std::cout << perm << "\n";
		return;
	}

	for (int i = 0; i < orig.size(); i++) {
		std::string temp1 = orig;
		temp1.erase(i, 1);
		std::string temp2 = perm;
		temp2 += orig.at(i);
		permutationWithoutRepetition(temp1, temp2);
	}
}

void permutationWithRepetition(std::vector<std::string> &permutations, std::string input, std::string prefix, const int length) {
	//Base case: length = 1, print the string "length" times + the remaining letter
	if (length == 1)
		for (int i = 0; i < input.size(); i++)
			permutations.push_back(prefix + input[i]);
	// One by one add all characters from "str" and recursively call for "length" equals to "length"-1
	else 
		for (int i = 0; i < input.size(); i++)
			// Next character of input added
			// "length" is decreased, because we have added a new character
			permutationWithRepetition(permutations, input, prefix + input[i], length - 1);
};
