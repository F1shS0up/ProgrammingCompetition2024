#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "email.h"

int main()
{
    std::ifstream ifs("emails.txt");
    std::string line;

    std::vector<std::string> output;

    GetEmailsInArray(ifs, line, output);//Get UNIQUE emails into array

    std::ofstream outfile("unique_emails.txt");//Create new file

    for(int i = 0; i < output.size(); i++){
        outfile << output[i] << std::endl; //Write in
    }
    outfile.close();

    std::cout << "Output file is located at: " << std::filesystem::current_path() << "  (output.txt)" << std::endl;
}

void GetEmailsInArray(std::ifstream& ifs, std::string& line, std::vector<std::string>& output)
{
    while (std::getline(ifs, line)) {
        if (std::find(output.begin(), output.end(), line) != output.end()) {
            //contains
            continue;
        }
        else {
            //doesnt contain
            output.push_back(line);
        }
    }
}