#pragma once

namespace Dict
{
	template<class Key>
	class not_found_exception : public std::exception
	{
	public:
		virtual const Key& get_key() const noexcept = 0;
	};

	template <typename Key>
	class not_found_exceptionIpml : public not_found_exception<Key>
	{
	public:
		not_found_exceptionIpml(const Key& key)
			:m_Key(key)
		{
		}

		virtual const Key& get_key() const noexcept override
		{
			return m_Key;
		}

		const char* what() const noexcept override
		{
			return "Error: Key is not found";
		}
	private:
		Key m_Key;
	};
}