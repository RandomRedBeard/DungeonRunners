

#pragma once 

#include <oid.h>

namespace DR {
	struct HasId {
		virtual const OID get_id() = 0;
	};
}