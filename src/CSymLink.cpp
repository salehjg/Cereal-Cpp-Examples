#include "CSymLink.h"

CSymLink::CSymLink(size_t globalId, size_t linkId)
{
	m_uGlobalId = globalId;
	m_uLinkId = linkId;
	m_eType = Types::kLink;
}
