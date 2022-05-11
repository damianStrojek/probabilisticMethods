// Damian Strojek s184407
#include <iostream>
#include <time.h>
#define TO_RAND 100000

int main() {
	std::srand(time(0));
	// Probability of the appearance of a pair of numbers
	float probabilities[4][4] = {
						{ 0.15, 0, 0, 0.2 },
						{ 0.05, 0, 0.1, 0 },
						{ 0, 0.1, 0, 0.05 },
						{ 0.2, 0, 0, 0.15 } };

	float x[4] = { 0 };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			x[j] += probabilities[j][i];

	float fx[4] = { 0 };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j <= i; j++)
			fx[i] += x[j];

	float tempVector[4][4] = { { 0 }, { 0 }, { 0 }, { 0 } };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			tempVector[j][i] = probabilities[j][i] / x[j];

	float tempVector2[4][4] = { { 0 }, { 0 }, { 0 }, { 0 } };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k <= i; k++)
				tempVector2[j][i] += tempVector[j][k];

	// The output of our program
	int out[4][4] = { { 0 }, { 0 }, { 0 }, { 0 } };
	int iterator = 0;
	// Flag so I can dodge using `goto`
	bool flag = 0;
	while (iterator < TO_RAND) {
		float x = (float)rand() / (float)RAND_MAX;
		for (int i = 0; i < 4; i++) {
			if (x < fx[i]) {
				float y = (float)rand() / (float)RAND_MAX;	
				for (int j = 0; j < 4; j++)
					if (y < tempVector2[i][j]) {
						out[i][j]++;
						flag = 1;
						break;
					}
			}
			if (flag) { flag = 0; break; }
		}
		iterator++;
	}

	for (int i = 0; i < 4; i++) {
		std::cout << i + 1 << ":    ";
		for (int j = 0; j < 4; j++) {
			std::cout << out[i][j] << " (p = " << probabilities[i][j] << ")";
			if (j != 3) std::cout << ", ";
		}
		std::cout << "\n";
	}
	return 0;
};
