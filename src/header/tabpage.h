#ifndef TABPAGE_H
#define TABPAGE_H

#include<QTabWidget>
#include<QList>

class QWebView;
class QUrl;

class TabPage:public QTabWidget
{
	Q_OBJECT
public:
	explicit TabPage(QWidget *parent = 0);
	~TabPage();
signals:
	void urlChanged(const QUrl&);
public slots:
	void doNewTab();
	void doLoadNewPage(const QUrl&);
private slots:
	void doTabChanged(int);
	void doTabClosed(int);
	void doLinkClicked(const QUrl&);
private:
	QList<QWebView*> viewList;
};

#endif
