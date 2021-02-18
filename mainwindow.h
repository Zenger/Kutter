#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString GetVideoDuration();
    ~MainWindow();
    QString videoPath;


private slots:
    void on_browseBtn_clicked();

    void on_convertBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
