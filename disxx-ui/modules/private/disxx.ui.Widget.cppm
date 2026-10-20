export module disxx.ui.Widget;

import disxx.ui.ir.Widget;

export namespace disxx::ui
{
	class __attribute__((visibility("default"))) [[nodiscard]] Widget : public Clone
	{
	  public:
		explicit Widget(void) noexcept = default;
	
		Widget(const Widget &) noexcept = default;
		Widget &operator=(const Widget &) noexcept = default;

		virtual ir::Widget ProduceIntermidiateRepresentation(void) const noexcept = 0;
	};
} /* disxx::ui */
