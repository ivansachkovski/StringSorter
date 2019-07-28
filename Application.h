#pragma once

#include <string>
#include <fstream>

struct CommandLineArguments
{
	std::string m_pathToInputFile;
	std::string m_pathToOutputFile;

	bool ParseCommandLineArguments(int, char**);
	void PrintUsageCommandLine() const;
};

class Application
{
public:
	bool Run(int, char**) const;

private:
	bool OpenFileStream(const std::string&, std::fstream&, std::ios_base::openmode) const;
};