export module disxx.ui.Tree;

export import disxx.ui.Container;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] Tree final : public Container
	{
	  public:
		explicit Tree(void) noexcept = default;
		template <typename ...Args> explicit Tree(Args &&...) noexcept;

		Tree(const Tree &) noexcept = default;
		Tree &operator=(const Tree &) noexcept = default;
	};

	template <typename ...Args> Tree::Tree(Args &&...args) noexcept
		: Container{std::forward<Args>(args...)}
	{}
} /* disxx::ui::ir */
