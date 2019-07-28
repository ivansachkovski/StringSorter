#include "Application.h"
#include "StringHandler.h"

#include <algorithm>
#include <iostream>

#define _S(exp) { if (!(exp)) return false; }

bool CommandLineArguments::ParseCommandLineArguments(int argc, char** argv)
{
	if (argc == 4)
	{
		m_pathToInputFile = argv[1];
		m_pathToOutputFile = argv[3];
	
		return true;
	}
	else
	{
		printf("Impossible to parse command line arguments.\n");
		PrintUsageCommandLine();
	}

	return false;
}

void CommandLineArguments::PrintUsageCommandLine() const
{
	printf("Possible command line arguments:\n");
	printf("\tapp.exe <input file> <word to delete> <output file>\n");
}

bool Application::Run(int argc, char** argv) const
{
	CommandLineArguments arguments;
	_S(arguments.ParseCommandLineArguments(argc, argv));
	
	std::fstream inputStream;
	_S(OpenFileStream(arguments.m_pathToInputFile, inputStream, std::ios_base::in));

	StringHandler handler;
	
	std::vector<std::string> lines;
	handler.ReadLines(inputStream, lines);
	handler.SortLines(lines);
	
	std::fstream outputStream;
	_S(OpenFileStream(arguments.m_pathToOutputFile, outputStream, std::ios_base::out));

	handler.PrintLines(outputStream, lines);

	return true;
}

bool Application::OpenFileStream(const std::string& pathToFile, std::fstream& stream, std::ios_base::openmode mode) const
{
	// Of course, we can add some tests for this method to simulate different situations like:
	// file not exist, don't have access to file, file is broken...
	// But it's difficult enough and it can be useless.
	stream.open(pathToFile, mode);

	if (!stream.is_open())
	{
		printf("Impossible to open file '%s'.\n", pathToFile.c_str());

		return false;
	}

	return true;
}