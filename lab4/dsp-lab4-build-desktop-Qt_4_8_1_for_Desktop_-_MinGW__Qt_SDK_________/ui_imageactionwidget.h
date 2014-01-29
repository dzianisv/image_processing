/********************************************************************************
** Form generated from reading UI file 'imageactionwidget.ui'
**
** Created: Wed 20. Nov 22:14:42 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEACTIONWIDGET_H
#define UI_IMAGEACTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "histogramwidget.h"

QT_BEGIN_NAMESPACE

class Ui_ImageActionWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sourceImageWidget;
    QLabel *destinationImageWidget;
    QHBoxLayout *horizontalLayout;
    HistogramWidget *sourceHistogramWidget;
    HistogramWidget *destinationHistogramWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QProgressBar *progressBar;

    void setupUi(QWidget *ImageActionWidget)
    {
        if (ImageActionWidget->objectName().isEmpty())
            ImageActionWidget->setObjectName(QString::fromUtf8("ImageActionWidget"));
        ImageActionWidget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ImageActionWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sourceImageWidget = new QLabel(ImageActionWidget);
        sourceImageWidget->setObjectName(QString::fromUtf8("sourceImageWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sourceImageWidget->sizePolicy().hasHeightForWidth());
        sourceImageWidget->setSizePolicy(sizePolicy);
        sourceImageWidget->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(sourceImageWidget);

        destinationImageWidget = new QLabel(ImageActionWidget);
        destinationImageWidget->setObjectName(QString::fromUtf8("destinationImageWidget"));
        sizePolicy.setHeightForWidth(destinationImageWidget->sizePolicy().hasHeightForWidth());
        destinationImageWidget->setSizePolicy(sizePolicy);
        destinationImageWidget->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(destinationImageWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sourceHistogramWidget = new HistogramWidget(ImageActionWidget);
        sourceHistogramWidget->setObjectName(QString::fromUtf8("sourceHistogramWidget"));
        sizePolicy.setHeightForWidth(sourceHistogramWidget->sizePolicy().hasHeightForWidth());
        sourceHistogramWidget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(sourceHistogramWidget);

        destinationHistogramWidget = new HistogramWidget(ImageActionWidget);
        destinationHistogramWidget->setObjectName(QString::fromUtf8("destinationHistogramWidget"));
        sizePolicy.setHeightForWidth(destinationHistogramWidget->sizePolicy().hasHeightForWidth());
        destinationHistogramWidget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(destinationHistogramWidget);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton = new QPushButton(ImageActionWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        progressBar = new QProgressBar(ImageActionWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_3->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ImageActionWidget);

        QMetaObject::connectSlotsByName(ImageActionWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageActionWidget)
    {
        ImageActionWidget->setWindowTitle(QApplication::translate("ImageActionWidget", "Form", 0, QApplication::UnicodeUTF8));
        sourceImageWidget->setText(QString());
        destinationImageWidget->setText(QString());
        pushButton->setText(QApplication::translate("ImageActionWidget", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageActionWidget: public Ui_ImageActionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEACTIONWIDGET_H
