#pragma once
#include "Events.h"

void initEvents() {
	CreateEvent(NULL, FALSE, FALSE, EVENT_ACCEPT_CLIENT);
	CreateEvent(NULL, FALSE, FALSE, EVENT_NEW_CONNECT_CLIENT);
	CreateEvent(NULL, FALSE, FALSE, EVENT_DISCONNECT_CLIENT);

	CreateEvent(NULL, FALSE, FALSE, EVENT_RECV_MESSAGE);
	CreateEvent(NULL, FALSE, FALSE, EVENT_SEND_MESSAGE);
	CreateEvent(NULL, FALSE, FALSE, EVENT_NEW_MESSAGE);
	CreateEvent(NULL, FALSE, FALSE, EVENT_PUSH_MESSAGE_IN_QUEUE);
	CreateEvent(NULL, FALSE, FALSE, EVENT_CLOSE_RECEIVE_THREAD);

	CreateEvent(NULL, FALSE, FALSE, EVENT_GAME_START);
	CreateEvent(NULL, FALSE, FALSE, EVENT_GAME_FINISH);
}

HANDLE GetEventAcceptClient() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_ACCEPT_CLIENT);
}
HANDLE GetEventNewConnetClient() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_NEW_CONNECT_CLIENT);
}

HANDLE GetEventDisconnectClient()
{
	return CreateEvent(NULL, FALSE, FALSE, EVENT_DISCONNECT_CLIENT);
}

HANDLE GetEventRecvMessage() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_RECV_MESSAGE);
}
HANDLE GetEventSendMessage() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_SEND_MESSAGE);
}
HANDLE GetEventNewMessage() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_NEW_MESSAGE);
}
HANDLE GetEventPushMessageInQueue() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_PUSH_MESSAGE_IN_QUEUE);
}
HANDLE GetEventCloseReceiveThread() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_CLOSE_RECEIVE_THREAD);
}



HANDLE GetEventGameStart() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_GAME_START);
}
HANDLE GetEventGameFinish() {
	return CreateEvent(NULL, FALSE, FALSE, EVENT_GAME_FINISH);
}
