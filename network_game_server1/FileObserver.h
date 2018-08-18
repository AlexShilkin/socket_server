#pragma once

class FileObserver
{
public:
	virtual ~FileObserver() {};

	virtual void onFileResult(int result) = 0;
};

