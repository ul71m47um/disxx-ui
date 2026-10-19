export module disxx.ui.ScrollView;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] ScrollView final : public Container
	{
	  public:
		explicit ScrollView(void) noexcept = default;
		template <typename ...Args> explicit ScrollView(Args &&...) noexcept;

		ScrollView(const ScrollView &) noexcept = default;
		ScrollView &operator=(const ScrollView &) noexcept = default;
	};

	template <typename ...Args> ScrollView::ScrollView(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
