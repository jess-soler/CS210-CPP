// Jessica Soler
// Project 3
// source.cpp
// Main program file

#include <iostream>
#include "ItemFrequencyAnalyzer.h"
using namespace std;


int main() {
    // define file constants
	// INPUT_FILENAME: name of the input data file
	// OUTPUT_FILENAME: name of the output backup file
    const string INPUT_FILENAME = "InputFile.txt";
    const string OUTPUT_FILENAME = "frequency.dat";

    // create the analyzer object
    // ItemFrequencyAnalyzer class handles: reading, counting, displaying, and backing up item frequencies
    ItemFrequencyAnalyzer analyzer;

    // process the input file
    // check that we have records before proceeding with the menu
    // this reads every word in INPUT_FILENAME, counts frequencies, and stores them in a vector inside the analyzer
    analyzer.ProcessInputFile(INPUT_FILENAME);

	// create the backup data file to ensure data persistence
    analyzer.WriteBackupFile(OUTPUT_FILENAME);

    // run the interactive menu loop
	// option 1: search for item frequency
	// option 2: display all item frequencies
	// option 3: display histogram of item frequencies
	// option 4: exit program
    analyzer.RunMenuLoop();

    // successful program termination
    return 0;
}
