export module disxx.ui.VSplitView;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] VSplitView final : public Container
	{
	  public:
		explicit VSplitView(void) noexcept = default;
		template <typename ...Args> explicit VSplitView(Args &&...) noexcept;

		VSplitView(const VSplitView &) noexcept = default;
		VSplitView &operator=(const VSplitView &) noexcept = default;
	};

	template <typename ...Args> VSplitView::VSplitView(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
