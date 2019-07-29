#include "StringHandler.h"

#include <algorithm>
#include <sstream>

void StringHandler::ReadLines(std::fstream& inputStream, std::vector<std::string>& lines) const
{
    const int MAX_BUFFER_SIZE = 512;
    char pBuffer[MAX_BUFFER_SIZE];

    while (inputStream.getline(pBuffer, MAX_BUFFER_SIZE))
    {
        lines.push_back(pBuffer);
    }
}

void StringHandler::PrintLines(std::fstream& outputStream, const std::vector<std::string>& lines) const
{
    std::for_each(lines.begin(), lines.end(), [&outputStream](const std::string& line) { outputStream << line << '\n'; });
}

void StringHandler::RemoveWordFromEachLine(std::vector<std::string>& lines, const std::string& wordToRemove) const
{
    for (auto& line : lines)
    {
        RemoveWordFromSingleLine(line, wordToRemove);
    }
}

void StringHandler::RemoveWordFromSingleLine(std::string& line, const std::string& wordToRemove) const
{
    // There can be some interpretations for this task.
    // This function solve just one of them.
    std::stringstream sstream(line);
    line.clear();

    std::string word;
    while (sstream >> word)
    {
        if (word != wordToRemove)
        {
            // Add words separated with the space.
            // Don't add space to empty string(during the first iteration).
            line = line + (line.size() ? " " : "") + word;
        }
    }
}

void StringHandler::SortLines(std::vector<std::string>& lines) const
{
    // This method works can word incorrectly on not-english lines.
    // To support the other languages we can, for example, change string to wstring. 
    std::sort(lines.begin(), lines.end(), [](const std::string& first, const std::string& second) { return _strcmpi(first.c_str(), second.c_str()) < 0; });
}