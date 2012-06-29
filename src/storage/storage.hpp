#include <memory>

#include "connection.hpp"

namespace ruuster
{
	class storage
	{
	private:
		std::shared_ptr<mysql::connection> conn;
		
	public:
		storage(const std::string host, const std::string user, const std::string password, const std::string database)
		: conn(std::make_shared<mysql::connection>(mysql::connection::connection_info(host, user, password, database)))
		{}
	};
}
