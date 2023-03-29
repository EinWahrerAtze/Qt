//
//  main.cpp
//  QT sample project
//
//  Created by Denis Fedorov on 28.03.2023.

#include "socket.hpp"
#include <string>
#include <QSqlDatabase>

auto main(int argc, char * argv[]) -> int
{
	// network object
	const std::string address {"51.38.81.49"};
	simple_socket socket;
	socket.connect(address);

	std::cout << "\n\n\n";
	// database object
	QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
	db.setHostName("acidalia");
	db.setDatabaseName("customdb");
	db.setUserName("mojito");
	db.setPassword("J0a1m8");

	if (db.isOpen())
	{
		std::cout << "connected to database\n";
	}
	else
	{
		std::cout << "could not connect to database\n";
	}
	return 0;
}