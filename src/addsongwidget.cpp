#include "include/addsongwidget.h"
#include "ui_addsongwidget.h"

AddSongWidget::AddSongWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSongWidget)
{
    ui->setupUi(this);

    QObject::connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->searchBtn, SIGNAL(clicked()), this, SLOT(launchDialog()));
    QObject::connect(ui->addBtn, SIGNAL(clicked()), this, SLOT(addSong()));
}

AddSongWidget::~AddSongWidget()
{
    delete ui;
}

void AddSongWidget::launchDialog()
{
    m_dialog = new QFileDialog();
    m_dialog->exec();

    QStringList output = m_dialog->selectedFiles();
    if (output.length() > 0)
    {
        ui->fileInput->setText(output[0]);
    }
}

void AddSongWidget::addSong()
{
    m_song = new Song(ui->songName->text().toStdString(), ui->fileInput->text().toStdString());
    emit addedSong(*m_song);
    close();

}
