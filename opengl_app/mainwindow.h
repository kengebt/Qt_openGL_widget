#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QFileDialog>
#include <QMessageBox>
#include "libicp/icpPointToPlane.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // image processing
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    bool loadFile(const QString &);

private slots:
    void on_OpenButton_1_clicked();

    void on_OpenButton_2_clicked();

    void on_OpenButton_3_clicked();

    void on_Move_Origin_clicked();

    void on_Move_Up_clicked();

    void on_Move_Down_clicked();

    void on_Move_Left_clicked();

    void on_Move_Right_clicked();

private:
    Ui::MainWindow *ui;

    int num, img_width, img_height;
    int vertex_a;
    int *M_color, *T_color;
    double *M, *T;
    Matrix pose_SR, pose_ST;
    void LoadPly(const QString &fileName);
};

#endif // MAINWINDOW_H
