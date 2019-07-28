#pragma once

#include <vector>
#include <string>
#include <fstream>

class StringHandler
{
public:
	void ReadLines(std::fstream&, std::vector<std::string>&) const;
	void PrintLines(std::fstream&, const std::vector<std::string>&) const;

	void RemoveWord(std::vector<std::string>&, const std::string&) const;
	void SortLines(std::vector<std::string>&) const;
};