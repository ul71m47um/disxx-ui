export module disxx.ui.Text;

export import disxx.ui.Widget;

export namespace disxx::ui
{
	class __attribute__((visibility("default"))) [[nodiscard]] Text final : public Widget
	{
	  private:
		std::string m_Text{};

	  public:
		explicit Text(void) noexcept = default;
		explicit Text(std::string_view) noexcept;

		Text(const Text &) noexcept = default;
		Text &operator=(const Text &) = default;

		virtual ~Text(void) noexcept override = default;
		virtual ir::Widget ProduceIntermidiateRepresentation(void) const noexcept override;
	};
} /* disxx::ui */
