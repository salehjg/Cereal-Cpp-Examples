#pragma once

#include "CSymbolic.h"
#include <cereal/types/base_class.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/access.hpp>


class CConst : public CSymbolic {
	friend class cereal::access;
public:
	CConst() { m_uGlobalId = m_uSymbolId = 0; m_eType = Types::kConst;}
	CConst(size_t globalId, size_t symbolId, float val);

private:
	size_t m_uSymbolId;
	float m_fValue;

	template<class Archive>
	void serialize(Archive& ar)
	{
		ar(
			CEREAL_NVP(m_uSymbolId),
			CEREAL_NVP(m_fValue),
			cereal::base_class<CSymbolic>(this)
		);
	}
};