#pragma once

#include <unordered_map>

#include "exception.hpp"

namespace Dict
{
	template<class Key, class Value>
	class dictionary
	{
	public:
		virtual ~dictionary() = default;

		virtual const Value& get(const Key& key) const = 0;
		virtual void set(const Key& key, const Value& value) = 0;
		virtual bool is_set(const Key& key) const = 0;
	};

	template<class Key, class Value>
	class dictionaryImpl : public dictionary<Key, Value>
	{
	public:

		virtual ~dictionaryImpl() override = default;

		const Value& get(const Key& key) const override
		{
			if (!is_set(key)) {
				throw not_found_exceptionIpml<Key>(key);
			}
			return m_Data.at(key);
		}

		void set(const Key& key, const Value& value) override
		{
			m_Data[key] = value;
		}

		bool is_set(const Key& key) const override
		{
			return m_Data.find(key) != m_Data.end();
		}

	private:
		std::unordered_map<Key, Value> m_Data;
	};
}