#pragma once
#include "AsyncFile.h"
#include "Observable.h"
#include "FileObserver.h"
#include <functional>
#include <future>


class FileManager:public Observable<FileObserver>
{
private:
	AsyncFile* file;
public:
	FileManager();
	~FileManager();
	
	void createFile(std::function<void(bool)> callback, char* name);
	void writeFile(std::function<void(unsigned long)> callback, char *data, bool append);
	void readFile(std::function<void(char*)> callback, unsigned long readLength);
	void clearFile(std::function<void(bool)> callback);
	void deleteFile(std::function<void(bool)> callback);
};

