export module disxx.ui.TextInput;

export import disxx.ui.Widget;

export namespace disxx::ui
{
	class __attribute__((visibility("default"))) [[nodiscard]] TextInput final : public Widget
	{
	  private:
		std::string m_Query{};
		std::string &m_Text{};

	  public:
		explicit TextInput(void) noexcept = default;
		explicit TextInput(std::string_view, std::string &) noexcept;

		TextInput(const TextInput &) noexcept = default;
		TextInput &operator=(const TextInput &) noexcept = default;

		virtual ~TextInput(void) noexcept override = default;
		virtual std::unique_ptr<Widget> Clone(void) const noexcept override;
		virtual ir::Widget ProduceIntermidiateRepresentation(void) const noexcept override;
	};
} /* disxx::ui */
