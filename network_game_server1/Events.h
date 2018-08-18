#pragma once
#include "NetworkBase.h"
//Events server function
#define EVENT_ACCEPT_CLIENT			"EventAcceptClient"
#define EVENT_NEW_CONNECT_CLIENT	"EventNewConnectClient"
#define EVENT_DISCONNECT_CLIENT		"EventDisconnectClient"

//Events RecieveModule
#define EVENT_RECV_MESSAGE			"EventRecvMessage"
#define EVENT_SEND_MESSAGE			"EventSendMessage"
#define EVENT_NEW_MESSAGE			"EventNewMessage"
#define EVENT_PUSH_MESSAGE_IN_QUEUE "EventPushMessageInQueue"
#define EVENT_CLOSE_RECEIVE_THREAD  "EventCloseReceiveThread"

//Events game use case
#define EVENT_GAME_START			"EventGameStart"
#define EVENT_GAME_FINISH			"EventGameFinish"


void initEvents();

HANDLE GetEventAcceptClient();
HANDLE GetEventNewConnetClient();
HANDLE GetEventDisconnectClient();

HANDLE GetEventRecvMessage();
HANDLE GetEventSendMessage();
HANDLE GetEventNewMessage();
HANDLE GetEventPushMessageInQueue();
HANDLE GetEventCloseReceiveThread();

HANDLE GetEventGameStart();
HANDLE GetEventGameFinish();

