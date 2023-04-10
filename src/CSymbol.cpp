#include "CSymbol.h"

CSymbol::CSymbol(size_t globalId, size_t symbolId)
{
	m_uGlobalId = globalId;
	m_uSymbolId = symbolId;
	m_eType = Types::kSymbol;
}
