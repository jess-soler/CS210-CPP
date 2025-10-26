// Jessica Soler
// Project 3
// ItemFrequencyAnalyzer.cpp
// contains all function definitions for ItemFrequencyAnalyzer class
// which analyzes the frequency of items in a given dataset

#include "ItemFrequencyAnalyzer.h"
#include <iostream>
#include <string>

// constructor
// no extra initialization needed, vector and ItemRecord have their own default constructors
ItemFrequencyAnalyzer::ItemFrequencyAnalyzer() {}

// open and read the input file to count item frequencies
void ItemFrequencyAnalyzer::ProcessInputFile(const string& inFile) {
	ifstream inFS;
	string currentItem;
	bool found;

	// open the input file
	cout << "Opening file: " << inFile << endl;
	inFS.open(inFile);

	// check if file opened successfully
	if (!inFS.is_open()) {
		cerr << "Warning: Error opening " << inFile << endl;
		return;
	}

	// while loop to read each item from the file
	// for each item read, store as currentItem
	while (inFS >> currentItem) {
		found = false;
		int i;

		// cycle through existing item records to see if currentItem already exists
		// if it exists, increment its count
		for (i = 0; i < itemRecords.size(); ++i) {
			if (itemRecords.at(i).GetItemName() == currentItem) {
				itemRecords.at(i).IncrementCount();
				found = true;
				break;
			}
		}

		// if currentItem was not found in existing records, create a new record with count 1 and add to the vector
		if (!found) {
			ItemRecord newItem(currentItem, 1);
			itemRecords.push_back(newItem);
		}
	}

	// check for input failure that is not end of file
	// this could indicate a read error
	if (!inFS.eof() && inFS.fail()) {
		cout << "Warning: Input failure occurred before reaching the end of the file." << endl;
	}

	// close the input file
	inFS.close();
	cout << "Finished processing file: " << inFile << endl;
}

// menu loop to interact with the user
void ItemFrequencyAnalyzer::RunMenuLoop() {
	int choice = 0;
	bool quit = false;

	// loop until user chooses to quit
	while (!quit) {
		// display menu and get user choice
		DisplayMenu();
		cout << "Enter your choice: ";
		
		// validate input
		if (!(cin >> choice)) {
			cout << "Warning: Invalid input.  Please enter a number." << endl;
			cin.clear();
			cin.ignore(300, '\n');
			continue;
		}

		// call the function based on user choice
		switch (choice) {
		case 1:
			SearchItemFrequency();
			break;
		case 2:
			DisplayAllFrequencies();
			break;
		case 3:
			DisplayHistogram();
			break;
		case 4:
			cout << "Exiting Program. Goodbye!" << endl;
			quit = true;
			break;
		default:
			cout << "Invalid menu choice.  Please choose 1, 2, 3, or 4" << endl;
			break;
		}

		cout << endl;
	}
}

// search for a specific item's frequency and display it
void ItemFrequencyAnalyzer::SearchItemFrequency() const {
	string searchItem;
	int frequency = 0;
	int i;

	// user input for which item to search, saved as searchItem
	cout << "Enter the item name to search: ";
	cin >> searchItem;

	// search through item records to find the searchItem
	// get its frequency
	for (i = 0; i < itemRecords.size(); ++i) {
		if (itemRecords.at(i).GetItemName() == searchItem) {
			frequency = itemRecords.at(i).GetCount();
			break;
		}
	}

	// display the frequency result
	cout << searchItem << " appeared " << frequency << " time(s)." << endl;
}

// display the item frequencies numerically
void ItemFrequencyAnalyzer::DisplayAllFrequencies() const {
	int i;

	cout << endl << "Purchase Frequencies: " << endl << endl;

	// loop through all items and display their name and count
	for (i = 0; i < itemRecords.size(); ++i) {
		cout << itemRecords.at(i).GetItemName() << " " << itemRecords.at(i).GetCount() << endl;
	}
}

// display the item frequencies as a histogram using asterisks*
void ItemFrequencyAnalyzer::DisplayHistogram() const {
	int i;
	int j;

	cout << endl << "Purchase Histogram: " << endl << endl;

	// loop through all items and display their name
	// nested for loop to increment and print asterisks based on count
	for (i = 0; i < itemRecords.size(); ++i) {
		const ItemRecord& record = itemRecords.at(i);
		cout << record.GetItemName() << " ";
		for (j = 0; j < record.GetCount(); ++j) {
			cout << "*";
		}
		cout << endl;
	}
}

// display the menu options
void ItemFrequencyAnalyzer::DisplayMenu() const {
	cout << "--------------------------------------" << endl;
	cout << "Corner Grocer Purchase Analyzer Menu" << endl;
	cout << "1: Search Item Frequency" << endl;
	cout << "2: Display All Frequencies" << endl;
	cout << "3: Display Histogram" << endl;
	cout << "4: Exit Program" << endl;
	cout << "--------------------------------------" << endl;
}

// write the item and frequency data to a backup file
void ItemFrequencyAnalyzer::WriteBackupFile(const string& backupFilename) const {
	int i;

	// open the output file
	ofstream outFS;
	cout << "Attempting to create backup file: " << backupFilename << endl;
	outFS.open(backupFilename);

	// check if file opened successfully
	if (!outFS.is_open()) {
		cout << "Error: Could not open backup file " << backupFilename << "." << endl;
		return;
	}

	// write each item and its count to the backup file
	for (i = 0; i < itemRecords.size(); ++i) {
		outFS << itemRecords.at(i).GetItemName() << " " << itemRecords.at(i).GetCount() << endl;
	}

	// close the output file
	outFS.close();
	cout << "Backup data successfully written to " << backupFilename << "." << endl;
}