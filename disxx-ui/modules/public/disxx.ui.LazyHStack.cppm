export module disxx.ui.LazyHStack;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] LazyHStack final : public Container
	{
	  public:
		explicit LazyHStack(void) noexcept = default;
		template <typename ...Args> explicit LazyHStack(Args &&...) noexcept;

		LazyHStack(const LazyHStack &) noexcept = default;
		LazyHStack &operator=(const LazyHStack &) noexcept = default;
	
		virtual std::unique_ptr<Widget> Clone(void) const noexcept override;
	};

	template <typename ...Args> LazyHStack::LazyHStack(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
