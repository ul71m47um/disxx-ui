export module disxx.ui.LazyVStack;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] LazyVStack final : public Container
	{
	  public:
		explicit LazyVStack(void) noexcept = default;
		template <typename Args...> explicit LazyVStack(Args &&...) noexcept;

		LazyVStack(const LazyVStack &) noexcept = default;
		LazyVStack &operator=(const LazyVStack &) noexcept = default;
	};

	template <typename Args...> LazyVStack::LazyVStack(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
