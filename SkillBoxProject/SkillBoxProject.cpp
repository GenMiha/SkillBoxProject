// SkillBoxProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <unordered_map>

using namespace std;


void bot(string text) {
    cout << " [BOT]: "<<text<<endl;
}

void to_lower(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

string to_lower2(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string user() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    question = to_lower2(question);
    return question;
}

int main()
{
    unordered_map<string, string> database = {
        {"hello", "Oh, hello to you, hooman"},
        {"how are you", "I'm good"},
        {"what is your name","AUTOMATED SUPERBOT 3000"},
    };

    string question;
    bot("Hello, welcome to AUTOMATED SUPERBOT 3000, please ask any questions:");
    while (question.compare("exit")!=0) {
        question = user();
        for (auto entry : database) {
            auto expression = regex(".*" + entry.first + ".*");
            if (regex_match(question, expression)) {
                bot(entry.second);
            }

        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
