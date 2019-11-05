#pragma once

#include <string>

using std::string;

public ref class GUIHandler {
public:
	string* key;
	int keyPreviousState;
	int keyMaxLength;

	string* textIn;
	int textInPreviousState;

	string* textOut;
	int textOutPreviousState;



public:
	GUIHandler();

};

