#include <iostream>
#include <vector>
#include "adresar.h"

int main()
{
	std::string A, B;
	std::cout << "Adresa A:";
	std::cin >> A;
	std::cout << "Adresa B:";
	std::cin >> B;

	std::vector<std::string> Aresult, Bresult;
	Aresult.push_back(std::string(1, A[0]));
	Bresult.push_back(std::string(1, B[0]));

	GetFoldersInArray(A, Aresult);
	GetFoldersInArray(B, Bresult);

	std::cout << "Output: ";

	int stopIndex = 0;
	FindFurthestCommonFolder(Aresult, Bresult, stopIndex);//We need to find the "furthest" folder that's same for both...

	for (int i = stopIndex + 1; i < Aresult.size(); i++) {
		std::cout << "\\.."; //After getting furthest folder we will display \.. for every left there
	}

	for (int i = stopIndex + 1; i < Bresult.size(); i++) {
		std::cout << Bresult[i];//Then we simply print remaining folders of B
	}
}

void FindFurthestCommonFolder(std::vector<std::string>& Aresult, std::vector<std::string>& Bresult, int& stopIndex)
{
	for (int i = 0; i < Aresult.size(); i++) {
		if (Bresult.size() > i && Aresult[i] == Bresult[i]) {
			stopIndex = i;
			break;
		}
		else {
			std::cout << "\\..";
		}
	}
}

void GetFoldersInArray(std::string& A, std::vector<std::string>& Aresult)
{
	int index = 0;

	for (int i = 1; i < A.length(); i++) {
		if (A[i] == '\\') {
			Aresult.push_back("\\");
			index++;
			continue;
		}
		Aresult[index] += A[i];
	}
}
