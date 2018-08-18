#pragma once
#include <queue>
#include <mutex>

#include <condition_variable>
#include "NetworkMessage.h"


using namespace std;

class QueueNetworkMessage
{
private:
	queue<NetworkMessage*> queueNetworkMessage;
	mutex mutex_;
	condition_variable cond_;
public:
	QueueNetworkMessage();
	~QueueNetworkMessage();
	void push(NetworkMessage* newtworkMessage);
	NetworkMessage* pop();
};

