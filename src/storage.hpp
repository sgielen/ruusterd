#include <memory>

#include <rusql/connection.hpp>
#include <boost/optional.hpp>

#include "typedefs.hpp"

namespace ruuster
{
	class storage
	{
	private:
		std::shared_ptr<rusql::connection> conn;
		
	public:
		storage(const std::string host, const std::string user, const std::string password, const std::string database)
		: conn(std::make_shared<rusql::connection>(rusql::connection::connection_info(host, user, password, database)))
		{}

		boost::optional<id> fetch_latest_revision(const id institute_id) const;
	};
}
