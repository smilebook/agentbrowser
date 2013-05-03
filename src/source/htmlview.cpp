#include"htmlview.h"

HtmlView::HtmlView(QWidget *parent /* = 0 */): QWebView(parent)
{

}

void HtmlView::loadNewPage(const QUrl &url)
{
	this->load(url);
}
