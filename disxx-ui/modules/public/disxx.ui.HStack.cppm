export module disxx.ui.HStack;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] HStack final : public Container
	{
	  public:
		explicit HStack(void) noexcept = default;
		template <typename ...Args> explicit HStack(Args &&...) noexcept;

		HStack(const HStack &) noexcept = default;
		HStack &operator=(const HStack &) noexcept = default;
	};

	template <typename ...Args> HStack::HStack(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
