#include "CConst.h"

CConst::CConst(size_t globalId, size_t symbolId, float val)
{
	m_fValue = val;
	m_uGlobalId = globalId;
	m_uSymbolId = symbolId;
	m_eType = Types::kConst;
}
