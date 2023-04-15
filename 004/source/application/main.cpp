//
//  main.cpp
//  QT sample project
//
//  Created by Denis Fedorov on 28.03.2023.

#include <QApplication>
#include "mainwindow.h"

auto main(int argc, char * argv[]) -> int
{
	QApplication app(argc, argv);
	auto window {new MainWindow()};
	window->show();
	return app.exec();
}