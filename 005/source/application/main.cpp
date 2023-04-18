//
//  main.cpp
//  QT homework #5
//
//  Created by Denis Fedorov on 17.04.2023.

#include <QApplication>
#include "mainwindow.hpp"

auto main(int argc, char * argv[]) -> int
{
	QApplication app(argc, argv);
	MainWindow window;
	window.show();
	return app.exec();
}