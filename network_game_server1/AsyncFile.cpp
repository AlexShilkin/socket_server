#include "AsyncFile.h"
#include <stdio.h>



AsyncFile::AsyncFile()
{
}

AsyncFile::AsyncFile(char* fileFullName)
{
	this->fileFullName = fileFullName;

	this->hFile = CreateFile(fileFullName, 
		GENERIC_READ | GENERIC_WRITE, 
		FILE_SHARE_READ|FILE_SHARE_WRITE| FILE_SHARE_DELETE,
		NULL, 
		OPEN_ALWAYS, 
		/*FILE_FLAG_NO_BUFFERING|*/FILE_FLAG_OVERLAPPED, 
		0);
	if (INVALID_HANDLE_VALUE == this->hFile) {
		printf("Open file(%s) error : %d", fileFullName, this->hFile);
		this->hFile = NULL;
	}
}

AsyncFile::~AsyncFile()
{
	if (this->hFile != NULL) {
		CloseHandle(this->hFile);
		this->hFile = NULL;
	}
}

bool AsyncFile::isCreatedFile()
{
	return this->hFile!=NULL;
}

//If nBytesToRead == 0 -> read the whole file 
bool AsyncFile::asyncRead(unsigned long nBytesToRead)
{	
	bool bReadResult=false;
	if (this->hFile != NULL) {
		this->gOverlappedRead.Offset = 0;
		this->gOverlappedRead.OffsetHigh = 0;
		this->gOverlappedRead.hEvent = CreateEvent(NULL, TRUE, FALSE, EVENT_FILE_READ);
		this->countByteToRead = 0;
		
		if (nBytesToRead == 0)
		{
			this->size.LowPart = GetCompressedFileSize(this->fileFullName, &size.HighPart);
			this->bufferRead = new char[this->size.LowPart];

			bReadResult = ReadFile(this->hFile, this->bufferRead, this->size.LowPart, NULL, &this->gOverlappedRead);
			if (bReadResult == FALSE) {
				if (ERROR_IO_PENDING == GetLastError()) {
					bReadResult = true;
				}
				else {
					printf("Read file(%s) error : %d", fileFullName, GetLastError());
					bReadResult = false;
				}
			}
		}
		else {
			bReadResult = ReadFile(this->hFile, this->bufferRead, nBytesToRead, NULL, &this->gOverlappedRead);
			if (bReadResult == FALSE) {
				if (ERROR_IO_PENDING == GetLastError()) {
					bReadResult = true;
				}
				else {
					printf("Read file(%s) error : %d", fileFullName, GetLastError());
					bReadResult = false;
				}
			}
		}
	}
	else {
		printf("Read file(%s) error : hFile = NULL", fileFullName);
	}
	return bReadResult;
}
//flag == true -> write to end 
bool AsyncFile::asyncWrite(char * data,bool flag)
{
	bool bWriteResult=false;
	if (this->hFile != NULL) {
		this->gOverlappedWrite.Offset = 0;
		this->gOverlappedWrite.OffsetHigh = 0;
		this->gOverlappedWrite.hEvent = CreateEvent(NULL, FALSE, FALSE, EVENT_FILE_WRITE);
		if (data != NULL) {
			if (flag == true) {
				this->gOverlappedWrite.Offset = 0xffffffff;
				this->gOverlappedWrite.OffsetHigh = 0xffffffff;
			}
			bWriteResult = WriteFile(this->hFile, data, strlen(data), NULL, &this->gOverlappedWrite);
			if (bWriteResult == FALSE) {
				if (ERROR_IO_PENDING == GetLastError()) {
					bWriteResult = true;
				}
				else {
					printf("Write file(%s) error : %d", fileFullName, GetLastError());
					bWriteResult = false;
				}
			}
		}
	}
	else {
		printf("Write file(%s) error : hFile = NULL", fileFullName);
	}
	
	return bWriteResult;
}

char * AsyncFile::waitRead()
{
	if (this->hFile != NULL) {
		DWORD dwWaitResult = WaitForSingleObject(this->gOverlappedRead.hEvent, INFINITE);
		if (dwWaitResult == WAIT_OBJECT_0) {
			this->countByteToRead = this->gOverlappedRead.InternalHigh;
			this->bufferRead[this->countByteToRead] = 0;
			return this->bufferRead;
		}
		else return "";
	}
	else {
		printf("waitRead file(%s) error : hFile = NULL", fileFullName);
		return "";
	}
}

unsigned long AsyncFile::waitWrite()
{
	if (this->hFile != NULL) {
		DWORD dwWaitResult = WaitForSingleObject(this->gOverlappedWrite.hEvent, INFINITE);
		if (dwWaitResult == WAIT_OBJECT_0) {
			this->countByteToWrite = this->gOverlappedWrite.InternalHigh;
			return this->countByteToWrite;
		}
		else return 0;
	}
	else {
		printf("waitWrite file(%s) error : hFile = NULL", fileFullName);
		return 0;
	}
}

bool AsyncFile::clearFile()
{
	bool bRet = true;

	this->hFile = CreateFile(fileFullName,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE| FILE_SHARE_DELETE,
		NULL,
		CREATE_ALWAYS,
		/*FILE_FLAG_NO_BUFFERING|*/FILE_FLAG_OVERLAPPED,
		0);
	
	if (INVALID_HANDLE_VALUE == this->hFile) {
		printf("Clear file(%s) error : %d", fileFullName, this->hFile);
		this->hFile = NULL;
		bRet = false;
	}
	return bRet;
}

bool AsyncFile::removeFile()
{
	bool bRet = false;
	
	if (this->hFile != NULL) {
		CloseHandle(this->hFile);
		this->hFile = NULL;
	}

	if (this->fileFullName != nullptr) {
		bRet = DeleteFile(this->fileFullName);
	}

	return bRet;
}
