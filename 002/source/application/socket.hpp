#pragma once
#include <QTcpSocket>
#include <iostream>
#include <vector>

class simple_socket
{
public:
	simple_socket()
	{
		m_buffer.resize(5 * 1024);
	}

	~simple_socket()
	{
		if (m_socket->isOpen()) { m_socket->close(); }
	}

	auto connect(const std::string & address) -> void
	{
		m_socket = new QTcpSocket();
		m_socket->connectToHost(address.c_str(), 80);

		if (m_socket->isValid())
		{
			const std::string request
			{
				"GET /index.html HTTP/1.1\r\n"
					"Host: example.com\r\n"
					"Connection: close\r\n\r\n"
			};

			auto value {m_socket->write(request.c_str(), request.size())};
			std::cout << "bytes sent: " << value << '\n';

			m_socket->waitForReadyRead(3000);
			value = m_socket->read(m_buffer.data(), m_buffer.size());
			std::cout << "bytes read: " << value << '\n';

			for (auto c : m_buffer)
			{
				std::cout << c;
			}
		}
		else
		{
			std::cout << "could not connect to host\n";
		}
	}
private:
	QTcpSocket * m_socket;
	std::vector<char> m_buffer;
};