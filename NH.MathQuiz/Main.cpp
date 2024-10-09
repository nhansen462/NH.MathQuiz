//Nicholas Hansen
//Math Quiz

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	std::cout << "Math Quiz\n";
	std::string filepath = "MathQuiz.txt";
	
	srand(time(NULL));
	int randomNumber;
	const int numQuestions = 3;
	

	std::string questions[10];
	std::vector<float> answers;

	std::ifstream ifs;
	ifs.open(filepath);
	std::string line;
	int count = 0;
	while (getline(ifs, line)) {
		questions[count] = line;
		count++;
	}
	ifs.close();

	float answer;
	for (int i = 0; i < numQuestions; i++) {
		randomNumber = rand() % 10;
		std::cout << "\nQuestion " << (i+1) << ": " << questions[randomNumber] << "\n";
		std::cout << "Enter your answer: ";
		std::cin >> answer;
		answers.push_back(answer);
	}

	std::ofstream ofs("QuizResults.txt");

	for (float i : answers) {
		ofs << i << "\n";
	}
	ofs.close();

	std::cout << "\nResults saved to QuizResults.txt";

	(void)_getch();
	return 0;
}