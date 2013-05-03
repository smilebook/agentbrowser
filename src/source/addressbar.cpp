#include"addressbar.h"


#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QString>

AddressBar::AddressBar(QWidget *parent/* = 0 */):QWidget(parent)
{
	addressEdit = new QLineEdit(parent);
	goButton = new QPushButton("Go", parent);
	newButton = new QPushButton("new", parent);

	layout = new QHBoxLayout;
	layout->addWidget(newButton);
	layout->addWidget(addressEdit);
	layout->addWidget(goButton);
	this->setLayout(layout);

	connect(goButton, SIGNAL(clicked()), this, SLOT(goToSite()));
	connect(addressEdit, SIGNAL(returnPressed()), this, SLOT(goToSite()));
	connect(newButton, SIGNAL(clicked()), this, SIGNAL(newPage()));
};

void AddressBar::doAddressChanged(const QUrl& url)
{
	addressEdit->setText(url.toString());
}
void AddressBar::goToSite()
{
	QString address = addressEdit->text();
	emit go(QUrl(address));
}
