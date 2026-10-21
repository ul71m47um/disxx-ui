export module disxx.ui.VStack;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] VStack final : public Container
	{
	  public:
		explicit VStack(void) noexcept = default;
		template <typename ...Args> explicit VStack(Args &&...) noexcept;

		VStack(const VStack &) noexcept = default;
		VStack &operator=(const VStack &) noexcept = default;
	
		virtual std::unique_ptr<Widget> Clone(void) const noexcept override;
	};

	template <typename ...Args> VStack::VStack(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
