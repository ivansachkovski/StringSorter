#include "gtest/gtest.h"
#include "..\Application.h"
#include "..\StringHandler.h"

TEST(CommandLineArguments, InvalidAmountOfArguments)
{
	CommandLineArguments arguments;
	char* argv[8] = { "1", "2", "3", "4", "5", "6", "7", "8" };
	for (int i = 0; i <= 8; ++i)
	{
		if (i != 4)
		{
			EXPECT_FALSE(arguments.ParseCommandLineArguments(i, argv));
		}
	}
}

TEST(CommandLineArguments, ValidAmountOfArguments)
{
	CommandLineArguments arguments;
	char* argv[8] = { "1", "2", "3", "4", "5", "6", "7", "8" };
	EXPECT_TRUE(arguments.ParseCommandLineArguments(4, argv));
}

TEST(StringHandler, SortDigitalLines) 
{
	StringHandler handler;
	
	const std::vector<std::string> expected_lines = { "123", "245", "3", "456" };

	std::vector<std::string> lines = { "123", "456", "245", "3" };
	
	handler.SortLines(lines);
	
	EXPECT_EQ(lines, expected_lines);
}

TEST(StringHandler, SortStringLines)
{
	StringHandler handler;

	const std::vector<std::string> expected_lines = { "fAsd", "fdsdq", "Gqwe", "qwea", "qwrzsw" };

	std::vector<std::string> lines = { "qwea", "fAsd", "fdsdq", "qwrzsw", "Gqwe" };

	handler.SortLines(lines);

	EXPECT_EQ(lines, expected_lines);
}

TEST(StringHandler, RemoveExistingWordFromLine)
{
    StringHandler handler;

    std::string line("One two three four five 8 5");

    handler.RemoveWordFromSingleLine(line, "One");
    EXPECT_EQ(line, "two three four five 8 5");

    handler.RemoveWordFromSingleLine(line, "three");
    EXPECT_EQ(line, "two four five 8 5");

    handler.RemoveWordFromSingleLine(line, "5");
    EXPECT_EQ(line, "two four five 8");
}

TEST(StringHandler, RemoveNotExistingWordFromLine)
{
    StringHandler handler;

    std::string line("One two three four five 8 5");

    handler.RemoveWordFromSingleLine(line, "One1");
    EXPECT_EQ(line, "One two three four five 8 5");

    handler.RemoveWordFromSingleLine(line, "three,");
    EXPECT_EQ(line, "One two three four five 8 5");

    handler.RemoveWordFromSingleLine(line, "51");
    EXPECT_EQ(line, "One two three four five 8 5");
}

TEST(StringHandler, RemoveWordFromEachLine)
{
    StringHandler handler;

    const std::vector<std::string> expected_lines = { "The first", "The second", "And the third", "The fourth without-one" };
    std::vector<std::string> lines = { "The first one", "The second one", "And the third one", "The fourth without-one" };

    handler.RemoveWordFromEachLine(lines, "one");
    EXPECT_EQ(lines, expected_lines);
}