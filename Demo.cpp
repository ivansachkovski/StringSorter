#include "Application.h"

int main(int argc, char** argv)
{
	printf("Application started.\n");

	Application app;
	// Run main application
	if (!app.Run(argc, argv))
	{
		printf("Impossible to run application.\n");

		return -1;
	}
	
	printf("Done.\n");

	return 0;
}