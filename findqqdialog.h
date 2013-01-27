// =====================================================================================
// 
//       Filename:  findqqdialog.h
//
//    Description:  ����QQ��Ϣ�Ի����������ļ�
//
//        Version:  1.0
//        Created:  2013��01��26�� 21ʱ01��49��
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef FINDQQDIALOG_H_
#define FINDQQDIALOG_H_

#include <QDialog>

#include "ui_findqqdialog.h"

class FindQQDialog : public QDialog, public Ui::FindQQDialog
{
	Q_OBJECT

public:
	FindQQDialog(QWidget *parent = 0);

private slots:
	void showHelpInfo();
};

#endif	// FINDQQDIALOG_H_