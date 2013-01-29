// =====================================================================================
// 
//       Filename:  listtreeview.h
//
//    Description:  ���������ݲ���ؼ���������ͷ�ļ�
//
//        Version:  1.0
//        Created:  2013��01��22�� 14ʱ50��49��
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef LISTTREEVIEW_H_
#define LISTTREEVIEW_H_

#include <QTreeView>

class QStandardItemModel;
class QString;

class ListTreeView : public QTreeView
{
	Q_OBJECT

	friend class MainWindow;

public:
	ListTreeView();
	~ListTreeView();

	void rebuildInfo();
	bool isChanged();

	void addOneCaptureItem(const char *szNum, const char *szTime, const char *szSIP, 
							const char *szDIP, const char *szProto, const char *szLength);

private:
	QStandardItemModel *mainModel;
	int iPosition;
};

#endif // LISTTREEVIEW_H_
