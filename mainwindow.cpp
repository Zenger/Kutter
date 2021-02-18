#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_browseBtn_clicked()
{
       this->videoPath = QFileDialog::getOpenFileName(this, tr("Select video"), "/", tr("Video Files (*.mp4 *.webm *.avi)") );
       this->ui->videoPath->setText( this->videoPath );

       this->ui->statusbar->showMessage("Loading ...");
       QString videoLength = this->GetVideoDuration();
       this->ui->statusbar->showMessage("Video is " + videoLength + " long");

       this->ui->endEdit->setText( videoLength );

}

void MainWindow::on_convertBtn_clicked()
{

    QString fullSavePath = QFileDialog::getSaveFileName(this, tr("Save as"), "/", tr("MP4 File (*.mp4)"));
    QProcess ffmpeg;
    QStringList params;
    params << "-i" << this->videoPath << "-ss" << this->ui->startEdit->text() << "-to" << this->ui->endEdit->text() << "-c" << "copy" << fullSavePath << "-hide_banner" << "-y";
    ffmpeg.start("ffmpeg", params);
    ffmpeg.waitForFinished();
    QString so (ffmpeg.readAllStandardOutput());
    QString eo (ffmpeg.readAllStandardError());

    if (ffmpeg.exitCode() > 0) {
        QMessageBox::warning(this, tr("ffmpeg failed"),
                                       eo, QMessageBox::Ok);
    }

    if (ffmpeg.exitCode() == 0) {
        QString msg = "Video was successfully converted and viewable at\n" + fullSavePath;
        QMessageBox::information(this, tr("Sucess"), tr(qPrintable(msg)), QMessageBox::Ok);
    }

}

QString MainWindow::GetVideoDuration() {

    QString videoLength = "00:00:00";
    QProcess ffmpeg;
    QStringList params;
    params << "-i" << this->videoPath << "-hide_banner";
    ffmpeg.start("ffmpeg", params);
    ffmpeg.waitForFinished();
    // err ouput, without an output ffmpeg errs out.
    QString errorOutput (ffmpeg.readAllStandardError());

    QRegularExpression re("Duration\\:\\s\\d\\d\\:\\d\\d\\:\\d\\d");
    QRegularExpressionMatch match = re.match( errorOutput );

    if (match.hasMatch()) {
       videoLength = match.captured(0).replace("Duration: ", "");
    }
    qDebug () << ffmpeg.error();

    if ( ffmpeg.error() == QProcess::FailedToStart) {
        QMessageBox msgBox;
        msgBox.setTextFormat(Qt::RichText);
        msgBox.setText("Kutter is a tiny UI for ffmpeg it cannot cut videos on its own. Please download ffmpeg from the official website at: <a href='https://ffmpeg.org/download.html'>https://ffmpeg.org/download.html</a> ");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setWindowTitle("ffmpeg is required");
        msgBox.setIcon( QMessageBox::Critical );
        msgBox.exec();

        QCoreApplication::exit();
    }

    return videoLength;
}
