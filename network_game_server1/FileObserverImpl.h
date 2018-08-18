#pragma once
#include "FileObserver.h"
#include <iostream>

class FileObserverImpl : public FileObserver
{
public:
	~FileObserverImpl();
	void onFileResult(int result);
};

