#include "connection.hpp"

#include <mysql_driver.h>

namespace ruuster
{
	namespace mysql
	{
		void connection::connect()
		{
			conn = std::unique_ptr<sql::Connection>(sql::mysql::get_mysql_driver_instance()->connect(
				info.host,
				info.user,
				info.password
			));
		
			conn->setSchema(info.database);
		}
	
		bool connection::execute(const std::string q)
		{
			return prepare(q).execute();
		}
	
		statement connection::prepare(const std::string q)
		{
			return statement(conn->prepareStatement(q));
		}
	}
}
