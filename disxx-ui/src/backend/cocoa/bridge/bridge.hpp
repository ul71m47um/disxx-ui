#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include <type_traits>
#include <filesystem>
#include <functional>
#include <concepts>
#include <optional>
#include <variant>
#include <vector>
#include <string>
#include <array>

namespace disxx::ui::bridge
{
	enum class Type
	{
		// Regular widgets
		TYPE_TEXT,
		TYPE_IMAGE,
		TYPE_BUTTON,
		TYPE_TEXTINPUT,

		// Containers
		TYPE_LIST,
		TYPE_TREE,
		TYPE_VSTACK,
		TYPE_HSTACK,
		TYPE_VSPLITVIEW,
        TYPE_HSPLITVIEW,
		TYPE_SCROLLVIEW,
		TYPE_LAZYVSTACK,
		TYPE_LAZYHSTACK
	};

	template <Type Kind>
	class __attribute__((visibility("default"))) [[nodiscard]] Property;

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_TEXT>
	{
	  private:
		std::array<float, 4> m_Color{};
		std::string m_Text{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetColor(std::array<float, 4>) noexcept;
		inline void SetText(std::string_view) noexcept;
	
		inline std::array<float, 4>	GetColor(void) const noexcept;
		inline std::string_view GetText(void) const noexcept;
	};

	inline void Property<Type::TYPE_TEXT>::SetColor(std::array<float, 4> color) noexcept
	{ this->m_Color = color; }
	
	inline void Property<Type::TYPE_TEXT>::SetText(std::string_view text) noexcept
	{ this->m_Text = text; }

	inline std::array<float, 4> Property<Type::TYPE_TEXT>::GetColor(void) const noexcept
	{ return this->m_Color; }

	inline std::string_view Property<Type::TYPE_TEXT>::GetText(void) const noexcept
	{ return this->m_Text; }

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_IMAGE>
	{
	  private:
		std::filesystem::path m_Path{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetPath(const std::filesystem::path) noexcept;
		
		inline std::filesystem::path GetPath(void) const noexcept;
	};

	inline void Property<Type::TYPE_IMAGE>::SetPath(const std::filesystem::path path) noexcept
	{ this->m_Path = path; }

	inline std::filesystem::path Property<Type::TYPE_IMAGE>::GetPath(void) const noexcept
	{ return this->m_Path; }

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_BUTTON>
	{
	  private:
		std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> m_Property{};
		std::function<void(void)> m_Callback{};
		std::array<float, 4> m_Color{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetPropery(std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>>) noexcept;
		inline void SetCallback(std::function<void(void)>) noexcept;
		inline void SetColor(std::array<float, 4>) noexcept;
	
		inline std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> GetProperty(void) const noexcept;
		inline std::function<void(void)> GetCallback(void) const noexcept;
		inline std::array<float, 4> GetColor(void) const noexcept;
	};

	inline void Property<Type::TYPE_BUTTON>::SetPropery(std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> property) noexcept
	{ this->m_Property = property; }	
	
	inline void Property<Type::TYPE_BUTTON>::SetCallback(std::function<void(void)> callback) noexcept
	{ this->m_Callback = callback; }	

	inline void Property<Type::TYPE_BUTTON>::SetColor(std::array<float, 4> color) noexcept
	{ this->m_Color = color; }

	inline std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> Property<Type::TYPE_BUTTON>::GetProperty(void) const noexcept
	{ return this->m_Property; }

	inline std::function<void(void)> Property<Type::TYPE_BUTTON>::GetCallback(void) const noexcept
	{ return this->m_Callback; }

	inline std::array<float, 4> Property<Type::TYPE_BUTTON>::GetColor(void) const noexcept
	{ return this->m_Color; }

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_TEXTINPUT>
	{
	  private:
		std::function<void(std::string)> m_Callback{};
		std::string m_Text{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetCallback(std::function<void(std::string)>) noexcept;
		inline void SetText(std::string_view) noexcept;
	
		inline const std::function<void(std::string)> GetCallback(void) const noexcept;	
		inline std::string_view GetText(void) const noexcept;
	};

	inline void Property<Type::TYPE_TEXTINPUT>::SetCallback(std::function<void(std::string)> callback) noexcept
	{ this->m_Callback = callback; }

	inline void Property<Type::TYPE_TEXTINPUT>::SetText(std::string_view text) noexcept
	{ this->m_Text = text; }

	inline std::string_view Property<Type::TYPE_TEXTINPUT>::GetText(void) const noexcept
	{ return this->m_Text; }
	
	inline const std::function<void(std::string)> Property<Type::TYPE_TEXTINPUT>::GetCallback(void) const noexcept
	{ return this->m_Callback; }

	using AnyProperty = std::variant
	<
		Property<Type::TYPE_TEXT>,
		Property<Type::TYPE_IMAGE>,
		Property<Type::TYPE_BUTTON>,
		Property<Type::TYPE_TEXTINPUT>
	>;

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
        inline void SetProperty(std::variant<AnyProperty, std::vector<Widget>> &&) noexcept;

        inline Type GetType(void) const noexcept;
        inline const std::variant<AnyProperty, std::vector<Widget>> &GetProperty(void) const noexcept;
    };

    inline void Widget::SetType(Type type) noexcept
    { this->m_Type = type; }

    inline void Widget::SetProperty(std::variant<AnyProperty, std::vector<Widget>> &&property) noexcept
    { this->m_Property = std::forward<std::variant<AnyProperty, std::vector<Widget>> &&>(property); }

    inline Type Widget::GetType(void) const noexcept
    { return this->m_Type; }

    inline const std::variant<AnyProperty, std::vector<Widget>> &Widget::GetProperty(void) const noexcept
    { return this->m_Property; }

	inline std::optional<std::vector<Widget>> mkvec(Widget widget) noexcept
	{
		return std::visit
		(
			[](auto &&prop) -> std::optional<std::vector<Widget>>
			{
				if constexpr (std::same_as<decltype(prop), std::vector<Widget>>)
					return prop;
				return std::nullopt;
			},
			widget.GetProperty()
		);
	}

	inline std::optional<AnyProperty> mkprop(Widget widget) noexcept
	{
		return std::visit
		(
			[](auto &&prop) -> std::optional<AnyProperty>
			{
				if constexpr (std::same_as<decltype(prop), AnyProperty>)
					return prop;
				return std::nullopt;
			},
			widget.GetProperty()
		);
	}

    inline std::optional<Property<Type::TYPE_TEXT>> mktxt(AnyProperty property) noexcept
    {
        return std::visit
        (
            [](auto &&prop) -> std::optional<Property<Type::TYPE_TEXT>>
            {
                if constexpr (std::same_as<decltype(prop), Property<Type::TYPE_TEXT>>)
					return prop;
				return std::nullopt;
            },
			property
        );
    }

	inline std::optional<Property<Type::TYPE_IMAGE>> mkimg(AnyProperty property) noexcept
    {
        return std::visit
        (
            [](auto &&prop) -> std::optional<Property<Type::TYPE_IMAGE>>
            {
                if constexpr (std::same_as<decltype(prop), Property<Type::TYPE_IMAGE>>)
					return prop;
				return std::nullopt;
            },
			property
        );
    }

	inline std::optional<Property<Type::TYPE_TEXT>> mktxt(Property<Type::TYPE_BUTTON> button) noexcept
    {
        return std::visit
        (
            [](auto &&prop) -> std::optional<Property<Type::TYPE_TEXT>>
            {
                if constexpr (std::same_as<decltype(prop), Property<Type::TYPE_TEXT>>)
					return prop;
				return std::nullopt;
            },
        	button.GetProperty()
		);
    }

	inline std::optional<Property<Type::TYPE_IMAGE>> mkimg(Property<Type::TYPE_BUTTON> button) noexcept
    {
        return std::visit
        (
            [](auto &&prop) -> std::optional<Property<Type::TYPE_IMAGE>>
            {
                if constexpr (std::same_as<decltype(prop), Property<Type::TYPE_IMAGE>>)
					return prop;
				return std::nullopt;
            },
        	button.GetProperty()
		);
    }
	
	inline std::optional<Property<Type::TYPE_BUTTON>> mkbtn(AnyProperty property) noexcept
    {
        return std::visit
        (
            [](auto &&prop) -> std::optional<Property<Type::TYPE_BUTTON>>
            {
                if constexpr (std::same_as<decltype(prop), Property<Type::TYPE_BUTTON>>)
					return prop;
				return std::nullopt;
            },
			property
        );
    }

	inline std::optional<Property<Type::TYPE_TEXTINPUT>> mktxtin(AnyProperty property) noexcept
    {
        return std::visit
        (
            [](auto &&prop) -> std::optional<Property<Type::TYPE_TEXTINPUT>>
            {
                if constexpr (std::same_as<decltype(prop), Property<Type::TYPE_TEXTINPUT>>)
					return prop;
				return std::nullopt;
            },
			property
        );
    }

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

        inline const std::vector<Widget> GetWidgets(void) const noexcept;
        inline const std::array<float, 2> GetSize(void) const noexcept;
        inline std::string_view GetTitle(void) const noexcept;
    };

    inline void Window::AddWidget(Widget &&widget) noexcept
    { this->m_Widgets.emplace_back(std::forward<Widget &&>(widget)); }

    inline void Window::SetSize(const std::array<float, 2> size) noexcept
    { this->m_Size = size; }

    inline void Window::SetTitle(std::string_view title) noexcept
    { this->m_Title = title; }

    inline const std::vector<Widget> Window::GetWidgets(void) const noexcept
    { return this->m_Widgets; }

    inline const std::array<float, 2> Window::GetSize(void) const noexcept
    { return this->m_Size; }

    inline std::string_view Window::GetTitle(void) const noexcept
    { return this->m_Title; }
} /* disxx::ui::bridge */

#endif // !BRIDGE_HPP
