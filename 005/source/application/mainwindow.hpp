//
//  mainwindow.hpp
//  QT homework #5
//
//  Created by Denis Fedorov on 17.04.2023.

#pragma once
#include <QLineEdit>
#include <QLCDNumber>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <stopwatch.hpp>

class MainWindow : public QWidget
{
public:
	explicit MainWindow(QWidget * parent = nullptr);
private:
	auto SetupOutputSection() -> void;
	auto SetupButtonsSection() -> void;
	auto SetupResultsSection() -> void;

	auto Update() -> void;
private:
	Stopwatch m_stopwatch;

	QGridLayout * m_layout;
	QTextEdit * m_list_widget;
	QLCDNumber * m_display_widget;
	QPushButton * m_control_button;
	QPushButton * m_utility_button;
};