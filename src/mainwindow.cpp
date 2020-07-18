#include "include/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Beats Library");

    m_songWidget = new AddSongWidget();

    refreshUI();

    // Signals
    QObject::connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addSongDialog()));
    QObject::connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(m_songWidget, SIGNAL(addedSong(Song)), this, SLOT(addSong(Song)));

}

void MainWindow::refreshUI()
{
    std::vector<std::string> output = m_library.getSongStrs();
    ui->songTable->setRowCount(output.size());
    ui->songTable->setColumnCount(1);

    for (unsigned int i=0; i < output.size(); i++)
    {

        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(output[i]));
        ui->songTable->setItem(i, 0, item);
    }

}

void MainWindow::addSong(Song song)
{
    m_library.addSong(song);
    refreshUI();
}

void MainWindow::addSongDialog()
{
    // open add window
    m_songWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

