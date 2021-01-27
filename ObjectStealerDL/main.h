#pragma once

#pragma comment(lib, "User32.lib")
#pragma comment(lib, "shell32.lib")

#pragma warning( disable : 4091 )

#define NOMINMAX
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <cstdio>
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <queue>
#include <algorithm>
#include <process.h>
//#include <d3dx9.h> // We use #define D3DCOLOR now so you don't really need SDK just for this.
#include <cstring>
#include <thread>
#include <ctime>
#include <iomanip>
#include <shlobj.h>

#include "functions.h"

#include "ADE32.h"
#include "CDetour.h"
#include "BitStream.h"
#include "RakClient.h"
#include "HookedRakClient.h"
#include "concurrentqueue.h"

using namespace std;


bool OnReceivePacket(Packet* p);
bool OnSendPacket(BitStream* parameters, PacketPriority priority, PacketReliability reliability, char orderingChannel);
bool OnSendRPC(int uniqueID, BitStream* parameters, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp);
void HandleRPCPacketFunc(unsigned char id, RPCParameters* rpcParams, void(*callback) (RPCParameters*));

extern DWORD g_SAMP;
extern HANDLE g_DllHandle;


#define SAMP_CHAT_INFO_OFFSET						0x2ACA10
#define SAMP_CHAT_INPUT_INFO_OFFSET					0x2ACA14
#define SAMP_INFO_OFFSET							0x2ACA24
#define SAMP_MISC_INFO								0x2ACA3C
#define SAMP_DRAWING_DISTANCE						0x11812C


#define SAMP_FUNC_ADDTOCHATWND						0x67650
#define SAMP_FUNC_SAY								0x5860
#define SAMP_FUNC_SENDCMD							0x69340
#define SAMP_FUNC_ADDCLIENTCMD						0x691B0


#define SAMP_HOOKENTER_HANDLE_RPC					0x3A9ED
#define SAMP_HOOKENTER_HANDLE_RPC2					0x3A979
#define SAMP_HOOKEXIT_HANDLE_RPC					0x3A9F3
#define SAMP_HOOKEXIT_HANDLE_RPC2					0x3AA01
#define SAMP_FUNC_CNETGAMEDESTRUCTOR				0x9570
#define SAMP_HOOKENTER_CNETGAME_DESTR				0xC5533
#define SAMP_HOOKENTER_CNETGAME_DESTR2				0xC6736