// Jessica Soler
// Project 3
// ItemRecord.h
// Defines ItemRecord class
// stores item and its frequency
// Inline functions, no separate implementation file

#pragma once

#ifndef ITEM_RECORD_H
#define ITEM_RECORD_H

#include <string>
using namespace std;

class ItemRecord {

public:
	// constructor to initialize name and count
	ItemRecord(string name = "", int count = 0) : itemName(name), count(count) {}

	// accessor for item name
	// const because it does not modify the object
	string GetItemName() const {
		return itemName;
	}

	// accessor for count
	// const because it does not modify the object
	int GetCount() const {
		return count;
	}

	// mutator to increment count
	// called each time the item is found in the input file
	void IncrementCount() {
		count++;
	}

private:
	string itemName; // name of produce item
	int count;       // frequency of the item
};

#endif // ITEM_RECORD_H

