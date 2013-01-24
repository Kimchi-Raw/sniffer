// =====================================================================================
// 
//       Filename:  sniffer.h
//
//    Description:  派生出的数据捕获类的声明头文件
//
//        Version:  1.0
//        Created:  2013年01月24日 14时36分49秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef SNIFFER_H_
#define SNIFFER_H_

#include <string>
#include <vector>

#include "csniffer.h"

// 网络设备的信息结构
struct NetDevInfo
{
	std::string strNetDevname;
	std::string strNetDevDescribe;
	std::string strIPV4FamilyName;
	std::string strIPV4Addr;
	std::string strIPV6FamilyName;
	std::string strIPV6Addr;
};

// 捕获的数据结构
struct SnifferData
{
	int			iNum;			// 序号
	std::string strTime;		// 时间
	std::string strSIP;			// 源 IP 地址，格式 IP:port
	std::string strDIP;			// 目标 IP 地址，格式 IP:port
	std::string strProto;		// 使用的协议
	int			iLength;		// 数据长度
	std::string strData;		// 原始数据
};

class Sniffer : public CSniffer
{
public:
	Sniffer();
	~Sniffer();

	void getNetDevInfo();				// 构建网络设备的信息结构
	void consolePrint();				// 控制台打印的函数
	void startCapture(int iDevNum);		// 开始捕获数据包（线程函数）

private:
	std::vector<NetDevInfo>  netDevInfo;
	std::vector<SnifferData> snifferDataVector;
};

#endif	// SNIFFER_H_
