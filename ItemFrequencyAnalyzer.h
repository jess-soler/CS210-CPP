// Jessica Soler
// Project 3
// ItemFrequencyAnalyzer.h
// header file for ItemFrequencyAnalyzer class
// ItemFrequencyAnalyzer reads the file, stores data into vector, handles menu functions, and backs up data

#pragma once

#ifndef ITEM_FREQUENCY_ANALYZER_H
#define ITEM_FREQUENCY_ANALYZER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ItemRecord.h"
using namespace std;

class ItemFrequencyAnalyzer {

public:
	// constructor
	ItemFrequencyAnalyzer();

	// read the input file and count item frequencies
	void ProcessInputFile(const string& inFile);

	// menu loop
	void RunMenuLoop();

	// write frequency data to backup file
	void WriteBackupFile(const string& outFile) const;

private:
	// vector to store itemRecord objects
	vector<ItemRecord> itemRecords;

	// menu functions
	void SearchItemFrequency() const;		// option 1: search specific item
	void DisplayAllFrequencies() const;		// option 2: display all items numerically
	void DisplayHistogram() const;			// option 3: display all items using asterisks
	void DisplayMenu() const;				// print menu
};

#endif // ITEM_FREQUENCY_ANALYZER_H