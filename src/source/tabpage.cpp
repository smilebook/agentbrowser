#include"tabpage.h"

#include<QWebView>
#include<QUrl>
#include<QtDebug>

#include"htmlview.h"

TabPage::TabPage(QWidget *parent /* = 0 */):QTabWidget(parent)
{
	this->setTabsClosable(true);

	connect(this, SIGNAL(currentChanged(int)), this, SLOT(doTabChanged(int)));
	connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(doTabClosed(int)));

	this->doNewTab();
};

TabPage::~TabPage()
{
}

void TabPage::doNewTab()
{
	HtmlView *view = new HtmlView;
	view->load(QUrl("http://www.baidu.com"));
	
	view->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

	connect(view, SIGNAL(linkClicked(const QUrl&)), this, SLOT(doLinkClicked(const QUrl&)));
	int index = this->addTab(view, "home");
	this->setCurrentIndex(index);

	viewList.append(view);
}

void TabPage::doLoadNewPage(const QUrl& url)
{
	qDebug()<< "loadNewPage:"<< url.toString();

	HtmlView *view = (HtmlView*)this->currentWidget();

	view->load(url);
}

void TabPage::doTabChanged(int index)
{
	if(index > viewList.length()-1)
		return;

	QWebView *view = viewList[index];
	emit urlChanged(view->url());
}

void TabPage::doTabClosed(int index)
{
	if(index > viewList.length()-1)
		return;

	QWebView *view = viewList[index];
	viewList.removeAt(index);

	delete view;
}

void TabPage::doLinkClicked(const QUrl &url)
{
	qDebug()<<"doLinkClicked"<<url.toString();
	HtmlView *view = (HtmlView*)this->currentWidget();
	view->load(url);
	emit urlChanged(url);
}
