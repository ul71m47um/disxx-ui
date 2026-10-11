#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include <optional>
#include <string>

namespace disxx::ui::bridge
{
	class [[nodiscard]] Widget
	{
	  public:
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
			TYPE_SPLITVIEW,
			TYPE_SCROLLVIEW,
			TYPE_LAZYVSTACK,
			TYPE_LAZYHSTACK
		};

	  private:
		class Impl;

	  private:
		const Impl *pImpl{nullptr};

	  public:
		explicit Widget(const Impl *const pImpl{nullptr}) noexcept;

		Widget(const Widget &) noexcept;
		Widget &operator=(const Widget &) noexcept;

		Widget(Widget &&) noexcept;
		Widget &operator=(Widget &&) noexcept;

		std::optional<Type> GetType(void) const noexcept;
	
		std::optional<std::string> GetText(void) noexcept;
	};
} /* disxx::ui::bridge */

#endif
