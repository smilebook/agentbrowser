#ifndef HTMLVIEM_H
#define HTMLVIEM_H

#include<QWebView>
#include<QUrl>
class HtmlView: public QWebView
{
	Q_OBJECT
public:
	explicit HtmlView(QWidget *parent = 0);
signals:
public slots:
	void loadNewPage(const QUrl &url);

};



#endif
