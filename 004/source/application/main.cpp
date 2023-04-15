//
//  main.cpp
//  QT homework #4
//
//  Created by Denis Fedorov on 14.04.2023.

#include <QApplication>
#include "mainwindow.h"

auto main(int argc, char * argv[]) -> int
{
	QApplication app(argc, argv);
	auto window {std::make_unique<MainWindow>()};
	window->show();
	return app.exec();
}