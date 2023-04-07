//
//  mainwindow.cpp
//  QT homework #3
//
//  Created by Denis Fedorov on 07.04.2023.

#include "mainwindow.h"
#include "./build/main_autogen/include/ui_mainwindow.h"

MainWindow::MainWindow(QWidget * parent) : QMainWindow {parent}, m_ui {new Ui::MainWindow}
{
	m_ui->setupUi(this);

	QObject::connect(m_ui->HelloButton, &QPushButton::released, this, [this]()
					 {
						 m_ui->HelloTextEdit->append("Hello!");
					 });

	QObject::connect(m_ui->HalloButton, &QPushButton::released, this, [this]()
					 {
						 m_ui->HalloTextEdit->append("Hallo!");
					 });
}

MainWindow::~MainWindow()
{
	delete m_ui;
}