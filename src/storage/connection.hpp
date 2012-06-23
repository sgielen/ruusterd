#pragma once

#include <string>
#include <memory>

#include <mysql_connection.h>

#include "statement.hpp"

namespace ruuster
{
	namespace mysql
	{
		class statement;

		class connection
		{
		public:
			struct connection_info
			{
				const std::string host, user, password, database;
			
				connection_info(const std::string host, const std::string user, const std::string password, const std::string database)
				: host(host)
				, user(user)
				, password(password)
				, database(database)
				{}
			};
		
		private:
			connection_info info;
			std::unique_ptr<sql::Connection> conn;
		
			void connect();
	
		public:
			connection(const connection_info& info)
			: info(info)
			, conn()
			{
				connect();
			}
		
			bool execute(const std::string q);
			statement prepare(const std::string q);
		};
	}
}
