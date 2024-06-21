#include "application.h"

int main()
{
	CApplication App;

	App.Initialize();
	App.Run();
	App.Finalize();

	return 0;
}