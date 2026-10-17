export module disxx.ui.List;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] List final : public Container
	{
	  public:
		explicit List(void) noexcept = default;
		template <typename Args...> explicit List(Args &&...) noexcept;

		List(const List &) noexcept = default;
		List &operator=(const List &) noexcept = default;
	};

	template <typename Args...> List::List(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
