#include "scene.h"

int main()
{
	CScene App;

	App.Initialize();
	App.Run();
	App.Finalize();

	return 0;
}