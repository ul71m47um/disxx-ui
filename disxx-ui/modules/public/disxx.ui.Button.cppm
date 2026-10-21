export module disxx.ui.Button;

export import disxx.ui.Widget;

export namespace disxx::ui
{
	class __attribute__((visibility("default"))) [[nodiscard]] Button final : public Widget
	{
	  private:
		std::string m_Text{};
		std::function<void(void)> callback{};

	  public:
		explicit Button(void) noexcept = default;
		explicit Button(std::string_view, std::function<void(void)>) noexcept;

		Button(const Button &) noexcept = default;
		Button &operator=(const Button &) noexcept = default;

		virtual ~Button(void) noexcept override = default;
		virtual std::unique_ptr<Widget> Clone(void) const noexcept override;
		virtual ir::Widget ProduceIntermidiateRepresentation(void) const noexcept override;
	};
} /* disxx::ui */
