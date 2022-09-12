#include "LoadCSV.h"
#include <stdio.h>
#include <cstdlib>
#include <cstdarg>
#include <vector>

void CSV::Schan(std::wstring fileName, const char* format, ...) {
	FILE* file;

	errno_t nonerror = _wfopen_s(&file, fileName.c_str(), L"r");
	if (nonerror != 0)
		std::abort();

	char dummyLine[512];
	fgets(dummyLine, 500, file);

	va_list args;
	va_start(args, format);

	vfscanf_s(file, format, args);

	va_end(args);

	fclose(file);
}

void CSV::Schan(std::wstring fileName, std::map<std::string, float> maplist) {
	FILE* file;

	errno_t nonerror = _wfopen_s(&file, fileName.c_str(), L"r");
	if (nonerror != 0)
		std::abort();

	char keyLine[512];
	fgets(keyLine, 500, file);



	std::string sLine = keyLine;
	std::vector<std::string> keyList;

	int cpos = 0;
	int numberOfParameter = 0;
	
	// キーの読み取り
	while (sLine != "") {
		cpos = sLine.find_first_of(',');
		keyList.push_back(sLine.substr(0, cpos));
		sLine.erase(0, cpos + 1);
		++numberOfParameter;
	}

	//char paramLine[512];
	//fgets(paramLine, 500, file);

	//sLine = paramLine;

	//// パラメーターの読み取り・設定
	//for (int i = 0; i < numberOfParameter; ++i) {
	//	cpos = sLine.find_first_of(',');
	//	maplist.insert(keyList[i], sLine.substr(0, cpos));
	//	sLine.erase(0, cpos + 1);
	//}

	fclose(file);
}