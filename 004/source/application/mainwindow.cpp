//
//  mainwindow.cpp
//  QT homework #4
//
//  Created by Denis Fedorov on 14.04.2023.

#include "mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget * parent) :
	QMainWindow(parent),
	m_bLocked(true),
	m_gboxControl(),
	m_gboxFormat(),
	m_btnMain(),
	m_pbarMain()
{
	this->setMinimumSize({400, 400});
	this->setMaximumSize({600, 600});
	this->setWindowTitle("MainWindow");
	this->setCentralWidget(new QWidget);

	m_gboxControl = this->CreateControlBox();
	m_gboxFormat = this->CreateColourBox();
	m_btnMain = this->CreateButton();
	m_pbarMain = this->CreateProgressBar();

	auto main_layout {new QVBoxLayout(this->centralWidget())};
	main_layout->addWidget(m_gboxControl);
	main_layout->addWidget(m_gboxFormat);
	main_layout->addWidget(m_pbarMain);
	main_layout->addWidget(m_btnMain);
}

auto MainWindow::CreateControlBox() -> QGroupBox *
{
	auto control_section {new QGroupBox("Progress bar control")};
	auto radio_one {new QRadioButton("Lock")};
	auto radio_two {new QRadioButton("Unlock")};
	radio_one->setChecked(true);

	QObject::connect(radio_one, &QRadioButton::clicked, this, [this]() -> void
	{
		this->m_bLocked = true;
	});

	QObject::connect(radio_two, &QRadioButton::clicked, this, [this]() -> void
	{
		this->m_bLocked = false;
	});

	auto vertical_layout {new QVBoxLayout};
	vertical_layout->addWidget(radio_one);
	vertical_layout->addWidget(radio_two);
	vertical_layout->addStretch(1);
	control_section->setLayout(vertical_layout);

	return control_section;
}

auto MainWindow::CreateColourBox() -> QGroupBox *
{
	auto format_section {new QGroupBox("Progress bar format")};
	auto formats_list {new QStringList({"Value", "Percentage"})};
	auto formats_box {new QComboBox};
	formats_box->addItems(*formats_list);

	QObject::connect(formats_box, &QComboBox::activated, this, [this](int n) -> void
	{
		switch (n)
		{
			case 0:
			{
				this->m_pbarMain->setFormat("%v");
				break;
			}
			case 1:
			{
				this->m_pbarMain->setFormat("%p");
				break;
			}
			default:
			{
				break;
			}
		}
	});

	auto vertical_layout {new QVBoxLayout};
	vertical_layout->addWidget(formats_box);
	vertical_layout->addStretch(1);
	format_section->setLayout(vertical_layout);

	return format_section;
}

auto MainWindow::CreateButton() -> QPushButton *
{
	auto button {new QPushButton("Push progress bar")};
	button->setCheckable(true);

	QObject::connect(button, &QPushButton::released, this, [this]() -> void
	{
		if (!m_bLocked)
		{
			if (this->m_pbarMain->value() == 10)
			{
				this->m_pbarMain->setValue(0);
			}
			else
			{
				this->m_pbarMain->setValue(this->m_pbarMain->value() + 1);
			}
		}
	});

	return button;
}

auto MainWindow::CreateProgressBar() -> QProgressBar *
{
	auto progress_bar {new QProgressBar};
	progress_bar->setRange(0, 10);
	progress_bar->setValue(0);
	progress_bar->setFormat("%v");
	progress_bar->setStyleSheet("QProgressBar { text-align: center; }");

	return progress_bar;
}