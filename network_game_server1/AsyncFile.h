#pragma once
#include <Windows.h>

#define EVENT_FILE_READ "eventFileRead"
#define EVENT_FILE_WRITE "eventFileWrite"

class AsyncFile
{
private: 
	OVERLAPPED gOverlappedRead;
	OVERLAPPED gOverlappedWrite;
	HANDLE hFile;
	char *fileFullName;
	ULARGE_INTEGER size;

	unsigned long countByteToRead;
	unsigned long countByteToWrite;

	char* bufferRead;
	char* bufferWrite;
public:
	AsyncFile();
	AsyncFile(char* fileFullName);
	~AsyncFile();
	bool isCreatedFile();
	bool asyncRead(unsigned long nBytesToRead);
	bool asyncWrite(char* data,bool flag);
	char * waitRead();
	unsigned long waitWrite();
	bool clearFile();
	bool removeFile();
};

