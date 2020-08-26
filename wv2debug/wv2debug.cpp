
#include <sstream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

using namespace std;

int main(int argn, char** argv, char **env) {

	stringstream ss;

	ss << "argn: " << argn << endl;
	for (int i = 0; i < argn; i++) {
		ss << "argv[" << i << "]: " << argv[i] << endl;
	}

	char env_entry[1024];
	size_t size = sizeof(env_entry);
	
	getenv_s(&size, env_entry, "WV_ENTRY");
	ss << "WV_ENTRY: " << env_entry << endl;

	char cwd[1024];
	GetCurrentDirectoryA(MAX_PATH, cwd);
	ss << "cwd: " << cwd << endl;

	MessageBoxA(nullptr, ss.str().c_str(), nullptr, MB_OK);

	// Just for testing WebView2 Debugging
	// No need to write real WebView2 codes

	return 0;
}