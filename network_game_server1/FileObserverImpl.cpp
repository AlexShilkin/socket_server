#include "FileObserverImpl.h"



FileObserverImpl::~FileObserverImpl()
{
}

void FileObserverImpl::onFileResult(int result)
{
	std::cout << "Type: " << result << std::endl;
}
