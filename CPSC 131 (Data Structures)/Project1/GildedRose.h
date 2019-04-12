#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

// This is already done for you...
class Item {
public:
	string name;
	int sellIn;
	int quality;
	Item(string, int, int);
};

Item::Item(string new_name, int new_sellIn, int new_quality)
	: name(new_name), sellIn(new_sellIn), quality(new_quality) {
}

class GildedRose {
private:
	size_t m_size;
	vector<Item> items;

public:	
	GildedRose() {
		m_size = items.size();
	};

	size_t size() const {
		return m_size;
	};
	Item& get(size_t index) {
		return items.at(index);
	};
	void add(const Item& val) {
		items.push_back(val);
		m_size = items.size();
	};
	Item& operator[](size_t val) {
		return items.at(val);
	};
};
