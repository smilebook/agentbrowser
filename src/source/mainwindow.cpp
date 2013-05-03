#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QWidget>
#include<QGridLayout>
#include<QtWebkit>

#include"addressbar.h"
#include"htmlview.h"
#include"tabpage.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)/*,
    ui(new Ui::MainWindow)*/
{
   //ui->setupUi(this);
   QWidget *centralWidget = new QWidget(this);
   AddressBar *bar = new AddressBar;
   //HtmlView *view = new HtmlView;
   TabPage *tab = new TabPage;

   QGridLayout *layout = new QGridLayout;
   layout->addWidget(bar, 0, 0, 1, 10);
   layout->addWidget(tab, 1, 0, 1, 10);
   
   centralWidget->setLayout(layout);

   QObject::connect(bar, SIGNAL(go(QUrl)), tab, SLOT(doLoadNewPage(QUrl)));
   QObject::connect(bar, SIGNAL(newPage()), tab, SLOT(doNewTab()));
   QObject::connect(tab, SIGNAL(urlChanged(QUrl)), bar, SLOT(doAddressChanged(QUrl)));


   this->setCentralWidget(centralWidget);
   this->setWindowTitle("AgentBrowser v1.0");
   this->resize(800,600);
}

MainWindow::~MainWindow()
{
 //   delete ui;
}
