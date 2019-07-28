#include "StringHandler.h"

#include <algorithm>

void StringHandler::ReadLines(std::fstream& inputStream, std::vector<std::string>& lines) const
{
	const int MAX_BUFFER_SIZE = 256;
	char pBuffer[MAX_BUFFER_SIZE];

	while (inputStream >> pBuffer)
	{
		lines.push_back(pBuffer);
	}
}

void StringHandler::PrintLines(std::fstream& outputStream, const std::vector<std::string>& lines) const
{
	std::for_each(lines.begin(), lines.end(), [&outputStream](const std::string& line) { outputStream << line << '\n'; });
}

void StringHandler::RemoveWord(std::vector<std::string>& lines, const std::string& word) const
{
	for (const auto& line : lines)
	{

	}
}

void StringHandler::SortLines(std::vector<std::string>& lines) const
{
	std::sort(lines.begin(), lines.end(), [](const std::string& first, const std::string& second) { return _strcmpi(first.c_str(), second.c_str()) < 0; });
}