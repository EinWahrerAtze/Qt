//
//  stopwatch.cpp
//  QT homework #5
//
//  Created by Denis Fedorov on 17.04.2023.

#pragma once
#include <QTimer>
#include <QVector>

class Stopwatch : public QObject
{
	Q_OBJECT

public:
	struct Time
	{
		unsigned minutes;
		unsigned seconds;
		unsigned milliseconds;

		auto Increment() -> void;
	};

	Stopwatch();

	auto Start(unsigned duration = 10) -> void;
	auto Stop() -> void;
	auto Reset() -> void;

	auto GetTime() const -> Time;
	auto GetLap() -> QPair<qsizetype, Time>;

	auto IsActive() const -> bool;
signals:
	auto UpdateTime(const Time & time) -> void;
private:
	QTimer m_timer;
	QVector<Time> m_laps;
};