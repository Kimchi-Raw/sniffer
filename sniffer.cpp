// =====================================================================================
// 
//       Filename:  sniffer.cpp
//
//    Description:  派生出的数据捕获类的实现文件
//
//        Version:  1.0
//        Created:  2013年01月24日 14时37分49秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef WIN32
	#include <sys/socket.h>
	#include <netinet/in.h>
#else
	#include <pcap.h>
	#define WPCAP
	#define HAVE_REMOTE 
	#include <remote-ext.h>
	#pragma comment(lib, "wpcap.lib")
	#pragma comment(lib, "Packet.lib")
	#pragma comment(lib, "ws2_32.lib")
	#pragma warning(disable:4996)
	#include <winsock.h>
#endif

#include <iostream>

#include "Sniffer.h"

Sniffer::Sniffer()
{
}

Sniffer::~Sniffer()
{
}

void Sniffer::getNetDevInfo()
{
	if (pAllNetDevs == NULL) {
		findAllNetDevs();
	}

	pcap_if_t	*index;
	pcap_addr_t *pAddr;
	NetDevInfo	tmpNetDevInfo;
	char ip6str[128];

	for (index = pAllNetDevs; index != NULL; index = index->next) {
		tmpNetDevInfo.strNetDevname =  index->name;

		if (index->description) {
			tmpNetDevInfo.strNetDevDescribe = index->description;
		} else {
			tmpNetDevInfo.strNetDevDescribe = "(No description available)";
		}

		for (pAddr = index->addresses; pAddr != NULL; pAddr = pAddr->next) {
			switch(pAddr->addr->sa_family)
			{
			case AF_INET:
				tmpNetDevInfo.strIPV4FamilyName = "AF_INET(IPV4)";
				if (pAddr->addr) {
					tmpNetDevInfo.strIPV4Addr = 
						iptos(((struct sockaddr_in *)pAddr->addr)->sin_addr.s_addr);
				}
				break;
			case AF_INET6:
				tmpNetDevInfo.strIPV6FamilyName = "AF_INET6(IPV6)";
				if (pAddr->addr) {
					tmpNetDevInfo.strIPV6Addr = 
						ip6tos(pAddr->addr, ip6str, sizeof(ip6str));
				}
				break;
			default:
				break;
			}
		}
		netDevInfo.push_back(tmpNetDevInfo);
	}
}

void Sniffer::consolePrint()
{
	for (std::vector<NetDevInfo>::iterator index = netDevInfo.begin();
			index < netDevInfo.end(); ++index) {
		std::cout << index->strNetDevname << "\n" << index->strNetDevDescribe << "\n"
				<< index->strIPV4FamilyName << "\n" << index->strIPV4Addr << "\n"
				<< index->strIPV6FamilyName << "\n" << index->strIPV6Addr << std::endl;
	}
}

void Sniffer::startCapture(int iDevNum)
{
	int res;
	struct tm *ltime;
	char timestr[16];
	time_t local_tv_sec;

	int num = 1;
	SnifferData tmpSnifferData;
	
	if (openNetDev(iDevNum) == true) {
		while ((res = captureOnce()) >= 0)
		{
			if (res == 0) {
				continue;
			}

			tmpSnifferData.iNum = num++;

			local_tv_sec = header->ts.tv_sec;
			ltime = localtime(&local_tv_sec);
			strftime(timestr, sizeof(timestr), "%H:%M:%S", ltime);

			tmpSnifferData.strTime = timestr;
			tmpSnifferData.iLength = header->len;

			snifferDataVector.push_back(tmpSnifferData);
		}

		if (res == -1) {
			return;
		}
	}
}