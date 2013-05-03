#ifndef ADDRESSBAR_H
#define ADDRESSBAR_H

#include<QWidget>
#include<QUrl>

class QLineEdit;
class QPushButton;
class QHBoxLayout;

class AddressBar:public QWidget
{
	Q_OBJECT
public:
	explicit AddressBar(QWidget *parent = 0);

signals:
	void go(QUrl);
	void newPage();

public slots:
	void goToSite();
	void doAddressChanged(const QUrl&);

private:
	QLineEdit *addressEdit;
	QPushButton *goButton;
	QPushButton *newButton;
	QHBoxLayout *layout;

};

#endif // ADDRESSBAR_H
