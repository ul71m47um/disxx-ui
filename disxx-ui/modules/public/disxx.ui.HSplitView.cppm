export module disxx.ui.HSplitView;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] HSplitView final : public Container
	{
	  public:
		explicit HSplitView(void) noexcept = default;
		template <typename Args...> explicit HSplitView(Args &&...) noexcept;

		HSplitView(const HSplitView &) noexcept = default;
		HSplitView &operator=(const HSplitView &) noexcept = default;
	};

	template <typename Args...> HSplitView::HSplitView(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
