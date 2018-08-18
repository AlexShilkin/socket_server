#include "QueueNetworkMessage.h"



QueueNetworkMessage::QueueNetworkMessage()
{
}


QueueNetworkMessage::~QueueNetworkMessage()
{
}

void QueueNetworkMessage::push(NetworkMessage* newtworkMessage)
{
	unique_lock<mutex> mlock(mutex_);
	queueNetworkMessage.push(newtworkMessage);
	mlock.unlock();
	cond_.notify_one();

}

NetworkMessage * QueueNetworkMessage::pop()
{
	unique_lock<mutex> mlock(mutex_);
	while (queueNetworkMessage.empty()) {
		cond_.wait(mlock);
	}
	NetworkMessage* item = queueNetworkMessage.front();
	queueNetworkMessage.pop();
	return item;
}