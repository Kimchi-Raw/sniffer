// =====================================================================================
// 
//       Filename:  prototreeview.h
//
//    Description:  Э�������������ļ�
//
//        Version:  1.0
//        Created:  2013��01��30�� 23ʱ08��10��
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef PROTOTREEVIEW_H_
#define PROTOTREEVIEW_H_

#include <QTreeView>
#include <QString>

struct AnalyseProtoType
{
	QString strEthTitle;		// ������·��
	QString strDMac;
	QString strSMac;
	QString strType;

	QString strIPTitle;			// �����
	QString strVersion;
	QString strHeadLength;
	QString strServerType;
	QString strLength;
	QString strNextProto;
	QString strSIP;
	QString strDIP;

	QString strTranProto;		// �����
	QString strSPort;
	QString strDPort;

	QString strAppProto;		// Ӧ�ò�
	QString strSendInfo;

	AnalyseProtoType()
	{
		strEthTitle = "������·�� Ethrmet II";
		strDMac = "Ŀ��MAC��ַ��";
		strSMac = "��ԴMAC��ַ��";
		strType = "��̫�����ͣ�";

		strIPTitle = "IP Э��";
		strVersion = "�汾��";
		strHeadLength = "Э��ͷ���ȣ�";
		strServerType = "�������ͣ�";
		strLength = "�ܳ���";
		strNextProto = "�߲�Э�����ͣ�";
		strSIP = "��ԴIP��ַ��";
		strDIP = "Ŀ��IP��ַ��";

		strSPort = "��Դ�˿ںţ�";
		strDPort = "Ŀ��˿ںţ�";
	}
};

class QStandardItemModel;
class QByteArray;

class ProtoTreeView : public QTreeView
{
	Q_OBJECT

public:
	ProtoTreeView();
	~ProtoTreeView();

	void rebuildInfo();
	void AnalyseProto(QByteArray *rawData);
	void ShowTreeAnalyseInfo();

private:
	QStandardItemModel *mainModel;
	AnalyseProtoType   *protoInfo;
};

#endif	PROTOTREEVIEW_H_
