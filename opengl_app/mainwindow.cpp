#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pose_SR = Matrix::eye(3);
    pose_ST = Matrix::Matrix(3,1);
    img_width = 640;
    img_height = 512;
    num = img_width * img_height;
    // allocate model and template memory
    M = (double*)calloc(3 * num, sizeof(double));
    T = (double*)calloc(3 * num, sizeof(double));
    M_color = (int *)calloc(3 * num, sizeof(int));    
    T_color = (int *)calloc(3 * num, sizeof(int));
/*
    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);*/
}

MainWindow::~MainWindow()
{
    delete M;
    delete T;
    delete M_color;
    delete T_color;
    delete ui;
}

void MainWindow::on_OpenButton_1_clicked()
{
    QStringList mimeTypeFilters;
//    foreach (const QByteArray &mimeTypeName, QImageReader::supportedMimeTypes())
//        mimeTypeFilters.append(mimeTypeName);
//    mimeTypeFilters.sort();
//    const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
//    QFileDialog dialog(this, tr("Open File"),
//                       picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.first());
    QFileDialog dialog(this, tr("Open File"), QDir::currentPath());
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
//    dialog.setMimeTypeFilters(mimeTypeFilters);
//    dialog.selectMimeTypeFilter("image/jpeg");
    if(dialog.exec() == QDialog::Accepted)
         loadFile(dialog.selectedFiles().first());
//    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}

bool MainWindow::loadFile(const QString &fileName)
{
    QImage image(fileName);
    if (image.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1.").arg(QDir::toNativeSeparators(fileName)));
        setWindowFilePath(QString());
        imageLabel->setPixmap(QPixmap());
        imageLabel->adjustSize();
        return false;
    }
    /*
//! [2] //! [3]
    imageLabel->setPixmap(QPixmap::fromImage(image));
//! [3] //! [4]
    scaleFactor = 1.0;

    printAct->setEnabled(true);
    fitToWindowAct->setEnabled(true);
    updateActions();

    if (!fitToWindowAct->isChecked())
        imageLabel->adjustSize();

    setWindowFilePath(fileName);*/
    return true;
}

void MainWindow::on_OpenButton_2_clicked()
{
    QFileDialog dialog(this, tr("Open File"), "D:/3DScanEXP/stitch_test");
    //QFileDialog dialog(this, tr("Open File"), QDir::currentPath());
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    //dialog.selectMimeTypeFilter("image/jpeg");
    if(dialog.exec() == QDialog::Accepted)
    {
        LoadPly(dialog.selectedFiles().first());
    }
}

void MainWindow::LoadPly(const QString &fileName)
{
    QByteArray ba = fileName.toLatin1();
    const char *c_str = ba.data();

    //std::cout << c_str << std::endl;

    FILE *fptr;
    fptr = fopen(c_str, "r");
    if (fptr == NULL)
    {
        printf("Can't open file!!");
        return;
    }
    //std::cout << "file open ok!" << std::endl;

    char strtemp[100];
    memset(strtemp, 0, sizeof(char) * 100);
    memset(M, 0, sizeof(double) * num * 3);
    while (strcmp(strtemp, "end_header") != 0)
    {
        fscanf_s(fptr, "%s", &strtemp);
        std::cout << strtemp << std::endl;
        if (strcmp(strtemp, "vertex") == 0)
        {
            fscanf_s(fptr, "%d", &vertex_a);
        }
    }
    //std::cout << "vertex:" << vertex_a << std::endl;

    for (int i = 0; i < vertex_a; i++)
    {
        fscanf_s(fptr, "%lf", &M[3 * i]);
        fscanf_s(fptr, "%lf", &M[3 * i + 1]);
        fscanf_s(fptr, "%lf", &M[3 * i + 2]);
        fscanf_s(fptr, "%d", &M_color[3 * i]);
        fscanf_s(fptr, "%d", &M_color[3 * i + 1]);
        fscanf_s(fptr, "%d", &M_color[3 * i + 2]);
    }
    memcpy(T_color, M_color, sizeof(int)*num*3);
    fclose(fptr);
}

void MainWindow::on_OpenButton_3_clicked()
{
    QFileDialog dialog(this, tr("Open File"), "D:/3DScanEXP/stitch_test");
    //QFileDialog dialog(this, tr("Open File"), QDir::currentPath());
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    if(dialog.exec() == QDialog::Accepted)
    {
        QByteArray ba = dialog.selectedFiles().first().toLatin1();
        const char *c_str = ba.data();

        FILE *lfptr;
        lfptr = fopen(c_str, "r");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                fscanf_s(lfptr, "%lf ", &pose_SR.val[i][j]);
            fscanf_s(lfptr, "%lf", &pose_ST.val[i][0]);
        }
        fclose(lfptr);

        double temp[3];
        for (int i = 0; i < vertex_a; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                    temp[j] = (pose_SR.val[j][0] * M[i * 3 + 0] +
                        pose_SR.val[j][1] * M[i * 3 + 1] +
                        pose_SR.val[j][2] * M[i * 3 + 2] + pose_ST.val[j][0]);
            }
            T[i * 3 + 0] = temp[0];
            T[i * 3 + 1] = temp[1];
            T[i * 3 + 2] = temp[2];
        }

        lfptr = fopen("D:/test.ply", "w");
        fprintf(lfptr, "ply\nformat ascii 1.0\ncomment author : Liteon\ncomment object : 3D scanner point cloud output\n");
        fprintf(lfptr, "element vertex %d\n", vertex_a);
        fprintf(lfptr, "property float x\nproperty float y\nproperty float z\n");
        fprintf(lfptr, "property uchar red\nproperty uchar green\nproperty uchar blue\n");
        fprintf(lfptr, "end_header\n");
        for (int i = 0; i < vertex_a; i++)
        {
            fprintf(lfptr, "%lf  ", T[i * 3]);
            fprintf(lfptr, "%lf  ", T[i * 3 + 1]);
            fprintf(lfptr, "%lf  ", T[i * 3 + 2]);
            fprintf(lfptr, "%d  ", T_color[i * 3]);
            fprintf(lfptr, "%d  ", T_color[i * 3 + 1]);
            fprintf(lfptr, "%d  ", T_color[i * 3 + 2]);
            fprintf(lfptr, "\n");
        }
		fclose(lfptr);
        std::cout << "finish!!" << std::endl;
        QMessageBox msgBox;
        msgBox.setText("ICP OK!!");
        msgBox.exec();
    }
    return;
}

void MainWindow::on_Move_Origin_clicked()
{
    ui->widget->Set_Default_Pos();
    //ui->widget->updateGL();
}

void MainWindow::on_Move_Up_clicked()
{
    ui->widget->Increase_Xrot();
    //ui->widget->updateGL();
}

void MainWindow::on_Move_Down_clicked()
{
    ui->widget->Decrease_Xrot();
    //ui->widget->updateGL();
}

void MainWindow::on_Move_Left_clicked()
{
    ui->widget->Decrease_Xdis();
    //ui->widget->updateGL();
}

void MainWindow::on_Move_Right_clicked()
{
    ui->widget->Increase_Xdis();
    //ui->widget->updateGL();
}
