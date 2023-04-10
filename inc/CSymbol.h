#pragma once

#include "CSymbolic.h"
#include <cereal/types/base_class.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/access.hpp>


class CSymbol : public CSymbolic {
	friend class cereal::access;
public:
	CSymbol() { m_uGlobalId = m_uSymbolId = 0;  m_eType = Types::kSymbol;}
	CSymbol(size_t globalId, size_t symbolId);

private:
	size_t m_uSymbolId;

	template<class Archive>
	void serialize(Archive& ar)
	{
		ar(
			CEREAL_NVP(m_uSymbolId),
			cereal::base_class<CSymbolic>(this)
		);
	}
};