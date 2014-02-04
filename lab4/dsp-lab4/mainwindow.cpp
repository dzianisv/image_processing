#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QFileDialog>
#include <QString>
#include <QDir>

#include <imagecontainer.h>
#include "logfilter.h".h"
#include "robertsfilter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    action0Widget = new logfilter();
    connect(this->ui->actionOpen, SIGNAL(triggered()), this, SLOT(openImage()));
    connect( ImageContainer::getInstance(), SIGNAL(loaded(QPixmap*)),
            (action0Widget->imageWidgets), SLOT(setPixmap(QPixmap*)) );

    this->setCentralWidget(action0Widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    if(fileName.isEmpty())
        return;

    ImageContainer::getInstance()->load(fileName);
}
