#pragma once
template<typename Data>
class DataProvider
{
public:
	DataProvider();
	virtual ~DataProvider();
	virtual void saveData(Data data)=0;
	virtual Data getData() = 0;
};

