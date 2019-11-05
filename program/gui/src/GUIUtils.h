#pragma once

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace System::Windows::Forms;
using System::String;
using std::string;

ref class GUIUtils {
public:
	string getFilePath();

	string setFilePath();

	string sStringToString(String^ str);

	String^ stringToSString(string str);

	string changeTextDisplayType(int from, int to, string oldString);

	string readKeyFile(string filePath);

	void saveKeyFile(string filePath, string text);
};

