//
//  mainwindow.h
//  QT homework #4
//
//  Created by Denis Fedorov on 14.04.2023.

#pragma once
#include <QComboBox>
#include <QGroupBox>
#include <QBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QStringList>
#include <QRadioButton>
#include <QProgressBar>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget * parent = nullptr);
private:
	auto CreateControlBox() -> QGroupBox *;
	auto CreateColourBox() -> QGroupBox *;
	auto CreateButton() -> QPushButton *;
	auto CreateProgressBar() -> QProgressBar *;

private:
	bool m_bLocked;

	QGroupBox * m_gboxControl;
	QGroupBox * m_gboxFormat;
	QPushButton * m_btnMain;
	QProgressBar * m_pbarMain;
};