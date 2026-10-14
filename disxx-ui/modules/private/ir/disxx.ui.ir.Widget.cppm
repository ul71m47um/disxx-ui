export module disxx.ui.ir.Widget;

export import :Property;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] Widget
	{
	  private:
		Type m_Type{};
		std::variant<AnyProperty, std::vector<Widget>> m_Property{};

	  public:
		explicit Widget(void) noexcept = default;

		Widget(const Widget &) noexcept = default;
		Widget &operator=(const Widget &) noexcept = default;

		inline void SetType(Type) noexcept;
		inline void SetProperty(std::variant<Property, std::vector<Widget>> &&) noexcept;

		inline Type GetType(void) const noexcept;
		inline const std::variant<Property, std::vector<Widget>> &GetProperty(void) const noexcept;
	};

	inline void Widget::SetType(Type type) noexcept
	{ this->m_Type = type; }

	inline void SetProperty(std::variant<Property, std::vector<Widget>> &&property) noexcept
	{ this->m_Property = std::forward<std::variant<Property, std::vector<Widget>> &&>(property); }

	inline Type Widget::GetType(void) const noexcept
	{ return this->m_Type; }

	inline const std::variant<Property, std::vector<Widget>> &Widget::GetProperty(void) const noexcept
	{ return this->m_Property; }
} /* disxx::ui::ir */
