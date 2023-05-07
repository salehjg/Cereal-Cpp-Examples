#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/access.hpp>

enum Types {
	kUndef = 0,
	kConst = 1,
	kSymbol = 2,
	kLink = 3
};
class CSymbolic {
	friend class cereal::access;
public:
	CSymbolic() {m_uGlobalId = 0; m_eType = Types::kUndef;}

	size_t GetId() { return m_uGlobalId; }
	void SetId(size_t id) { m_uGlobalId = id; }

	Types GetType() { return m_eType; }
	void SetType(Types type) { m_eType = type; }

	virtual ~CSymbolic() {}; // for polymorphism

protected:
	size_t m_uGlobalId;
	Types m_eType;

private:
        // Since we are using `serialize` method instead of split `load` and `save` methods, the derived classes of this class should also use `serialize`.
	template<class Archive>
	void serialize(Archive& ar)
	{
		ar(
			CEREAL_NVP(m_uGlobalId),
			CEREAL_NVP(m_eType)
		);
	}
};
