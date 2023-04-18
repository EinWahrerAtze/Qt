//
//  mainwindow.cpp
//  QT homework #5
//
//  Created by Denis Fedorov on 17.04.2023.

#include <QStringBuilder>
#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget * parent) : QWidget(parent)
{
	this->setMinimumSize({250, 400});
	this->setMaximumSize({250, 400});
	this->setWindowTitle("Stopwatch");

	m_layout = new QGridLayout();
	this->SetupOutputSection();
	this->SetupButtonsSection();
	this->SetupResultsSection();
	m_layout->setContentsMargins(5, 5, 5, 5);
	this->setLayout(m_layout);

	QObject::connect(&m_stopwatch, &Stopwatch::UpdateTime, this, &MainWindow::Update);
}

auto MainWindow::SetupOutputSection() -> void
{
	m_display_widget = new QLCDNumber();
	m_display_widget->setDigitCount(8);
	m_display_widget->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
	m_display_widget->display("00:00.0");

	m_layout->addWidget(m_display_widget, 0, 0, 1, 0);
}

auto MainWindow::SetupButtonsSection() -> void
{
	m_control_button = new QPushButton("Start");
	m_utility_button = new QPushButton("Reset");
	m_utility_button->setEnabled(false);

	QObject::connect(m_control_button, &QPushButton::pressed, this, [this]()
					 {
						 if (this->m_stopwatch.IsActive())
						 {
							 this->m_stopwatch.Stop();
							 this->m_control_button->setText("Start");
							 this->m_utility_button->setText("Reset");
						 }
						 else
						 {
							 this->m_stopwatch.Start();
							 this->m_utility_button->setEnabled(true);
							 this->m_control_button->setText("Stop");
							 this->m_utility_button->setText("Lap");
						 }
					 });

	QObject::connect(m_utility_button, &QPushButton::pressed, this, [this]()
					 {
						 if (this->m_stopwatch.IsActive())
						 {
							 auto [index, time] { this->m_stopwatch.GetLap() };
							 QString minutes {time.minutes < 10 ? QChar('0') % QString::number(time.minutes) : QString::number(time.minutes)};
							 QString seconds {time.seconds < 10 ? QChar('0') % QString::number(time.seconds) : QString::number(time.seconds)};
							 QString milliseconds {QString::number(time.milliseconds)};

							 this->m_list_widget->append("Lap: " % QString::number(index) % "\t\t" % minutes % ":" % seconds % "." % milliseconds);
							 m_list_widget->setAlignment(Qt::AlignCenter);
						 }
						 else
						 {
							 this->m_stopwatch.Reset();
							 this->m_list_widget->clear();
							 this->m_utility_button->setEnabled(false);
						 }
					 });

	m_layout->addWidget(m_utility_button, 2, 0);
	m_layout->addWidget(m_control_button, 2, 1);
}

auto MainWindow::SetupResultsSection() -> void
{
	m_list_widget = new QTextEdit();
	m_list_widget->setReadOnly(true);
	m_list_widget->setFontPointSize(12);

	m_layout->addWidget(m_list_widget, 3, 0, 4, 0);
}

auto MainWindow::Update() -> void
{
	auto time {m_stopwatch.GetTime()};
	QString minutes {time.minutes < 10 ? QChar('0') % QString::number(time.minutes) : QString::number(time.minutes)};
	QString seconds {time.seconds < 10 ? QChar('0') % QString::number(time.seconds) : QString::number(time.seconds)};
	QString milliseconds {QString::number(time.milliseconds)};

	m_display_widget->display(minutes % QChar(':') % seconds % QChar('.') % milliseconds);
}