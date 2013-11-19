#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QFileDialog>
#include <QString>
#include <QDir>

#include "imagecontainer.h"
#include "logarithmcorrection.h"
#include "robertsfilter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    action0Widget = new LogarithmCorrection();
    action1Widget = new RobertsFilter();

    QTabWidget *tabWidget = new QTabWidget();
    tabWidget->addTab(action0Widget, "Part 1");
    tabWidget->addTab(action1Widget, "Part 2");

    connect( ImageContainer::getInstance(), SIGNAL(loaded(QPixmap*)), action0Widget, SLOT(loadSourceImage(QPixmap*)));
    connect( ImageContainer::getInstance(), SIGNAL(loaded(QPixmap*)), action1Widget, SLOT(loadSourceImage(QPixmap*)));
    connect(this->ui->actionOpen, SIGNAL(triggered()), this, SLOT(openImage()));

    this->setCentralWidget(tabWidget);
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
