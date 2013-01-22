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

class ListTreeView : public QTreeView
{
	Q_OBJECT

public:
	ListTreeView();
	~ListTreeView();

	void rebuildInfo();
	bool isChanged();

private:
	QStandardItemModel *mainModel;
};

#endif // LISTTREEVIEW_H_
