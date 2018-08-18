#pragma once
#pragma warning(disable:4996)
#include "Utils.h"
#include <cstring>

class Client
{
private:
	int id;
	char* name;
public:
	Client();
	~Client();
	void setId(int id);
	void setName(char* name);
	int getId();
	char* getName();
	char *toString();
};

