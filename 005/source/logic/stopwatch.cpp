//
//  stopwatch.cpp
//  QT homework #5
//
//  Created by Denis Fedorov on 17.04.2023.

#include "stopwatch.hpp"

auto Stopwatch::Time::Increment() -> void
{
	if (++milliseconds == 10)
	{
		milliseconds = 0;
		if (++seconds == 60)
		{
			seconds = 0;
			++minutes;
		}
	}

}

Stopwatch::Stopwatch()
{
	m_timer.setTimerType(Qt::PreciseTimer);
	m_laps.emplace_back(Time());

	QObject::connect(&m_timer, &QTimer::timeout, this, [this]()
					 {
						 for (auto & item : this->m_laps)
						 {
							 item.Increment();
						 }
						 emit this->UpdateTime(this->m_laps.first());
					 });
}

auto Stopwatch::Start(unsigned duration) -> void
{
	m_timer.start(std::chrono::milliseconds(duration));
}

auto Stopwatch::Stop() -> void
{
	if (this->IsActive()) { m_timer.stop(); }
}

auto Stopwatch::Reset() -> void
{
	this->Stop();
	m_laps.clear();
	m_laps.emplace_back(Time());

	emit this->UpdateTime(this->m_laps.back());
}

auto Stopwatch::GetTime() const -> Time
{
	return m_laps.first();
}

auto Stopwatch::GetLap() -> QPair<qsizetype, Time>
{
	auto index {m_laps.size()};
	m_laps.emplace_back(Time());
	return QPair<qsizetype, Time>(index, m_laps.at(index - 1));
}

auto Stopwatch::IsActive() const -> bool
{
	return m_timer.isActive();
}