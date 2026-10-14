export module disxx.ui.ir.Window;

export import disxx.ui.ir.Widget;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] Window
	{
	  private:
		std::vector<Widget> m_Widgets{};
		std::array<float, 2> m_Size{};
		std::string m_Title{};

	  public:
		explicit Window(void) noexcept = default;

		Window(const Window &) noexcept = default;
		Window &operator=(const Window &) noexcept = default;

		inline void AddWidget(Widget &&) noexcept;
		inline void SetSize(const std::array<float, 2>) noexcept;
		inline void SetTitle(std::string_view) noexcept;

		inline const std::vector<Widget> &GetWidgets(void) const noexcept;
		inline const std::array<float, 2> &GetSize(void) const noexcept;
		inline std::string_view GetTitle(void) const noexcept;
	};

	inline void Window::AddWidget(Widget &&widget) noexcept
	{ this->m_Widgets.emplace_back(std::forward<Widget &&>(widget)); }

	inline void Window::SetSize(const std::array<float, 2> size) noexcept
	{ this->m_Size = size; }
	
	inline void Window::SetTitle(std::string_view title) noexcept
	{ this->m_Title = title; }

	inline const std::vector<Widget> &Window::GetWidgets(void) const noexcept
	{ return this->m_Widgets; }
	
	inline const std::array<float, 2> &Window::GetSize(void) const noexcept
	{ return this->m_Size; }
	
	inline std::string_view Window::GetTitle(void) const noexcept
	{ return this->m_Title; }
} /* disxx::ui::ir */
