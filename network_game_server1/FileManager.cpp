#include "FileManager.h"



FileManager::FileManager()
{
	
}


FileManager::~FileManager()
{		
    if (file!=nullptr){
		file->~AsyncFile();
	}
}

void FileManager::createFile(std::function<void(bool)> callback, char * name)
{
	file = new AsyncFile(name);
	if (file->isCreatedFile()) {
		callback(true);
	}
	else {
		callback(false);
	}
}

void FileManager::writeFile(std::function<void(unsigned long)> callback, char * data, bool append)
{
	if (file->asyncWrite(data, append)) {
		std::future<unsigned long> asyncWrite = std::async(&AsyncFile::waitWrite, file);
		callback(asyncWrite.get());
	}
	else {
		callback(0);
	}
}


void FileManager::readFile(std::function<void(char*)> callback, unsigned long readLength)
{
	if (file->asyncRead(readLength)) {
		std::future<char*> asyncRead = std::async(&AsyncFile::waitRead,file);
		callback(asyncRead.get());
	}
	else {
		callback(nullptr);
	}
}

void FileManager::clearFile(std::function<void(bool)> callback)
{
	std::future<bool> asyncClear = std::async(&AsyncFile::clearFile, file);
	callback(asyncClear.get());
}

void FileManager::deleteFile(std::function<void(bool)> callback)
{
	std::future<bool> asyncDelete = std::async(&AsyncFile::removeFile, file);
	callback(asyncDelete.get());
}


