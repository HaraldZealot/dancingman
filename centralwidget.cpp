#include "centralwidget.h"
#include <QtWidgets>
#include "manscreen.h"
#include "formulavalidator.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *layout5 = new QHBoxLayout;
    setLayout(layout5);
    ManScreen *screen = new ManScreen;
    layout5->addWidget(screen);
    QVBoxLayout *layout6 = new QVBoxLayout;
    layout5->addLayout(layout6);
    QGroupBox *headBox = new QGroupBox(tr("head"));
    layout6->addWidget(headBox);
    QVBoxLayout *layout7 = new QVBoxLayout;
    headBox->setLayout(layout7);
    QLineEdit *headText = new QLineEdit();
    headText->setPlaceholderText(tr("Enter formula..."));
    layout7->addWidget(headText);
    FormulaValidator *headValidator = new FormulaValidator();
    connect(headText, SIGNAL(textChanged(QString)), headValidator, SLOT(reciveText(QString)));
    connect(headValidator, SIGNAL(newValidFormula(QString)), screen, SLOT(setHeadFormula(QString)));
}
