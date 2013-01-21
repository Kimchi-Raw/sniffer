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

// ʹ�õ������ǰ������ P.S.��ͷ�ļ��������һ�����ͷ�ļ�����ʲô�õķ��
class QAction;
class QLabel;
class QSplitter;
class QTextEdit;
class QTreeView;
class QStandardItemModel;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

	void sleep(unsigned int msec);	// ��ʱ����

protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void about();

private:
	void createMainWeiget();		// ����������
	void createActions();			// ��������
	void createMenus();				// �������˵�
	void createContextMenu();		// �����������˵�
	void createToolBars();			// ����������
	void createStatusBar();			// ����״̬��

	bool isToContinue();			// ѯ���Ƿ����

	QSplitter *rightSplitter;		// �ұߵ��зִ���
	QSplitter *mainSplitter;		// ������зִ���

	QStandardItemModel *mainModel;	// ��������ݰ��б�����ģʽ

	QTreeView *mainTreeView;		// ��������ݰ��б�
	QTreeView *explainTreeView;		// �������ݵĽ���

	QTextEdit *originalEdit;		// �����ԭʼ���ݰ�

	QLabel *statusLabel;			// ״̬���ı�					
	
	QMenu *fileMenu;				// ���˵�-�ļ��Ӳ˵�ָ��
	QMenu *toolsMenu;				// ���˵�-�����Ӳ˵�ָ��
	QMenu *optionsMenu;				// ���˵�-ѡ���Ӳ˵�ָ��
	QMenu *helpMenu;				// ���˵�-�����Ӳ˵�ָ��

	QToolBar *fileToolBar;			// �ļ���ع�����ָ��
	QToolBar *workToolBar;			// ������ع�����ָ��
	QToolBar *setToolBar;			// ������ع�����ָ��
	QToolBar *infoToolBar;			// ������ع�����ָ��

	QAction *newAction;				// ����һ���µĲ��������ʷ��
	QAction *openAction;			// ����ʷ��һ�������¼
	QAction *saveAction;			// ���汾�β�����Ϣ���ļ�
	QAction *printAction;			// ��ӡ��ǰ���������
	QAction *exitAction;			// �˳�����

	QAction *beginAction;			// ��ʼ����
	QAction *endAction;				// ֹͣ����
	QAction *filterAction;			// ���ù�����
	QAction *findQQAction;			// ����QQ��Ϣ
	QAction *setAction;				// ȫ������

	QAction *aboutAction;			// �ر��ڳ���
	QAction *aboutQtAction;			// ����Qt
};

#endif // MAINWINDOW_H_
