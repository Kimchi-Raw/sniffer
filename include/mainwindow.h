// =====================================================================================
// 
//       Filename:  mainwindow.h
//
//    Description:  �����ڵ�������ͷ�ļ�
//
//        Version:  1.0
//        Created:  2013��01��20�� 17ʱ02��49��
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

#include "settinginfo.h"

class QAction;
class QLabel;
class QSplitter;
class QTextEdit;
class ListTreeView;
class QStandardItemModel;
class QTemporaryFile;
class QItemSelection;

class ProtoTreeView;
class CaptureThread;
class Sniffer;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

	void sleep(unsigned int msec);	// ��ʱ����

	SettingInfo *settingInfo;		// ����ȫ������

protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void newFile();
    void open();
    void save();
    void print();
	
	void chooseDev();
	void begin();
	void end();
	void findQQ();

	void about();

	void addRawDataToEdit(const QItemSelection &nowSelect);
	void addDataToTree(const QItemSelection &nowSelect);

private:
	void createMainWeiget();		// ����������
	void createActions();			// ��������
	void createMenus();				// �������˵�
	void createToolBars();			// ����������
	void createStatusBar();			// ����״̬��
	
	void readSettings();			// ��ȡ�����ļ�
	void writeSettings();			// д�������ļ�

	int isToContinue();				// ѯ���Ƿ����

	bool loadFile(const QString &fileName);			// ���벶���ļ�
	bool saveFile(const QString &fileName);			// ���沶���ļ�
	void setCurrentFile(const QString &fileName);	// ���õ�ǰ���ļ�

	CaptureThread *captureThread;	// ���ݲ����߳�

	Sniffer *sniffer;				// ���ݲ�����
	friend class FindQQDialog;

	QString curFile;				// ��ǰ���ļ�

	QSplitter *rightSplitter;		// �ұߵ��зִ���
	QSplitter *mainSplitter;		// ������зִ���

	ListTreeView *mainTreeView;		// ��������ݰ��б�
	ProtoTreeView *explainTreeView;	// �������ݵĽ���

	QTextEdit *originalEdit;		// �����ԭʼ���ݰ�

	QLabel *statusLabel;			// ״̬���ı�					
	
	QMenu *fileMenu;				// ���˵�-�ļ��Ӳ˵�ָ��
	QMenu *toolsMenu;				// ���˵�-�����Ӳ˵�ָ��
	QMenu *helpMenu;				// ���˵�-�����Ӳ˵�ָ��

	QToolBar *fileToolBar;			// �ļ���ع�����ָ��
	QToolBar *workToolBar;			// ������ع�����ָ��
	QToolBar *infoToolBar;			// ������ع�����ָ��

	QAction *newAction;				// ����һ���µĲ��������ʷ��
	QAction *openAction;			// ����ʷ��һ�������¼
	QAction *saveAction;			// ���汾�β�����Ϣ���ļ�
	QAction *printAction;			// ��ӡ��ǰ���������
	QAction *exitAction;			// �˳�����

	QAction *chooseDevAction;		// ѡ��򿪵�����
	QAction *beginAction;			// ��ʼ����
	QAction *endAction;				// ֹͣ����
	QAction *findQQAction;			// ����QQ��Ϣ

	QAction *aboutAction;			// �ر��ڳ���
	QAction *aboutQtAction;			// ����Qt
};

#endif // MAINWINDOW_H_
