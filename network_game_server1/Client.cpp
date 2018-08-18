#include "Client.h"


Client::Client()
{
}


Client::~Client()
{
}

void Client::setId(int id)
{
	this->id = id;
}

void Client::setName(char * name)
{
	this->name = name;
}

int Client::getId()
{
	return this->id;
}

char * Client::getName()
{
	return this->name;
}

char * Client::toString()
{
	char* strClass="";
	
	char* id = "{id:";
	//id = strcat(id, intToChar(this->id));
	id = strcat(id, ",");

	char* name = "name:";
	name = strcat(name, this->name);
	name = strcat(name, "}");

	strClass = strcat(id, name);

	return strClass;
}


/*
Client* Client::stringToClient(char * strClient)
{
	char* pattern = "{id:value,name:value}";
	Client client = Client();
	int positionId;
	int positionName;
	char* subStrClass = strstr(strClient, "id:");
	char* strId = "";
	for (int i = 0; i < strlen(subStrClass); i++) {
		if (subStrClass[i] != ',') {
			strcat(strId, (char*)subStrClass[i]);
		}
		else {
			break;
		}

	}
	subStrClass = strstr(strClient, "name:");
	return Client();
}
*/