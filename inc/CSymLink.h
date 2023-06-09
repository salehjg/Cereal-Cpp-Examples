#pragma once

#include "CSymbolic.h"
#include <cereal/types/base_class.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/access.hpp>


class CSymLink : public CSymbolic {
	friend class cereal::access;
public:
	CSymLink() { m_uGlobalId = m_uLinkId = 0; m_eType = Types::kLink; }
	CSymLink(size_t globalId, size_t linkId);

private:
	size_t m_uLinkId; 

        // Since the base class uses `serialize` method, we cannot use `load` and `save` split methods in this class. We should use `serialize` here as well.
	template<class Archive>
	void serialize(Archive& ar)
	{
		ar(
			CEREAL_NVP(m_uLinkId),
			cereal::base_class<CSymbolic>(this)
		);
	}
};
