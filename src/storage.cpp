#include "storage.hpp"

namespace ruuster
{
	boost::optional<id> storage::fetch_latest_revision(const id institute_id) const
	{
		rusql::statement stmt = conn->prepare("SELECT MAX(revision.id) AS id FROM revision WHERE revision.finished = 'yes' AND revision.institute_id = ?");
		stmt << institute_id;
		
		stmt.query();
		
		for(auto row : stmt.query()){
			uint64_t r;
			stmt >> r;
		}

		return r;
	}
}
