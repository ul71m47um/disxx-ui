export module disxx.ui.Container;

import disxx.ui.Widget;

import std;

namespace disxx::ui
{
	template <typename T>
	concept WidgetChild = std::base_of<Widget, T>::value;

	template <WidgetChild Args...>
	export class __attribute__((visibility("default"))) [[nodiscard]] WidgetList
	{
	  private:
		std::tuple<Args...> m_Args{};

	  public:
		constexpr WidgetList(void) noexcept = default;
		constexpr WidgetList(Args &&...args) noexcept;

		WidgetList(const WidgetList &) noexcept = default;
		WidgetList &operator=(const WidgetList) noexcept = default;

		consteval std::vector<std::unique_ptr<Widget>> ProducePointers(void) const noexcept;
	};

	template <WidgetChild Args...>
	WidgetList::WidgetList(Args &&...args) noexcept
		: m_Args{std::forward<Args>(args...)}
	{}

	template <WidgetChild Args...>
	consteval std::vector<std::unique_ptr<Widget>> WidgetList::ProducePointers(void) const noexcept
	{
		std::vector<std::unique_ptr<Widget>> widgets{};
		std::apply
		(
			[&widgets](const auto &...args) mutable -> void
			{ widgets.emplace_back(std::make_unique<typename std::decay<decltype(args)>::type>(args)...); }
		);

		return std::move(widgets);
	}
	
	export class __attribute__((visibility("default"))) [[nodiscard]] Container : public Widget
	{
	  private:
		std::vector<std::unique_ptr<Widget>> m_Children{};

	  public:
		explicit Container(void) noexcept = default;
		template <typename Args...> explicit Container(WidgetList<Args...> &&) noexcept;

		Container(const Container &) noexcept = default;
		Container &operator=(const Container &) noexcept = default;

		virtual ir::Widget ProduceIntermidiateRepresentation(void) const noexcept override;
	};

	template <typename Args...> Container::Container(WidgetList<Args...> &&list) noexcept
		: m_Children{std::move(list.ProducePointers())}
	{}
} /* disxx::ui */
