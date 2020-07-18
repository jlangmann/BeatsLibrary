#ifndef ADDSONGWIDGET_H
#define ADDSONGWIDGET_H

#include <QDialog>
#include <QFileDialog>
#include <iostream>
#include "include/song.h"


namespace Ui {
class AddSongWidget;
}

class AddSongWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AddSongWidget(QWidget *parent = nullptr);
    ~AddSongWidget();

private:
    Ui::AddSongWidget *ui;
    QFileDialog *m_dialog = new QFileDialog();
    Song *m_song;

public slots:
    void launchDialog();
    void addSong();

signals:
    void addedSong(Song);

};

#endif // ADDSONGWIDGET_H
