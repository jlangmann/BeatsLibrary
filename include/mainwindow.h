#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include/library.h"

#include "include/addsongwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addSong(Song);
    void addSongDialog();

private:
    void refreshUI();

    Ui::MainWindow *ui;
    AddSongWidget *m_songWidget;

    Library m_library;
};
#endif // MAINWINDOW_H
