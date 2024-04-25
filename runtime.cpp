#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

// program w dużej mierze napisany z ChatGPT
double runOriginalProgram(const string& programName, const vector<string>& arguments)
{

    string command = "./" + programName;
    for (size_t i = 0; i < arguments.size(); ++i)
    {
        const string& arg = arguments[i];
        command += " " + arg;
    }

    high_resolution_clock::time_point start = high_resolution_clock::now();
    system(command.c_str());
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    duration<double> duration = stop - start;

    return duration.count();
}

int main()
{
    const string originalProgramName = "driver_zad3";
    const string outputFileName = "runtimes.txt";
    const int numIterations = 100;

    vector<string> baseArguments;
    baseArguments.push_back("msg.txt");
    baseArguments.push_back("0");
    baseArguments.push_back("100");
    baseArguments.push_back("1");

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    int increment = 1000;

    for (int i = 0; i < numIterations; ++i)
    {
        baseArguments[2] = to_string(increment * (i + 1)); // Increment starts from 1
        double runtime = runOriginalProgram(originalProgramName, baseArguments);
        outputFile << runtime << endl;
    }

    outputFile.close();
    cout << "Runtimes saved to " << outputFileName << endl;

    return 0;
}
