#include <cookie.h>

using namespace Cookie;

int main(int argc, char* argv[])
{
	Jar jar;

	while (jar.alive())
	{
		jar.events();

		jar.render();
	}

	return 0;
}