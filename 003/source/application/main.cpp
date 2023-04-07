//
//  mainwindow.cpp
//  QT homework #3
//
//  Created by Denis Fedorov on 07.04.2023.

#include "mainwindow.h"
#include <QApplication>

auto main(int argc, char * argv[]) -> int
{
	QApplication app(argc, argv);
	MainWindow window;
	window.show();
	return app.exec();
}