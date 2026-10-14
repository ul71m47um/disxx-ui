export module disxx.ui.TextInput;

export import disxx.ui.Widget;

export namespace disxx::ui
{
	class __attribute__((visibility("default"))) [[nodiscard]] TextInput final : public Widget
	{
	  private:
		std::string m_Text{};
		std::function<void(std::string)> m_Callback{};

	  public:
		explicit TextInput(void) noexcept = default;
		explicit TextInput(std::string_view) noexcept;

		TextInput(const TextInput &) noexcept = default;
		TextInput &operator=(const TextInput &) = default;

		virtual ~TextInput(void) noexcept override = default;
		virtual ir::Widget ProduceIntermidiateRepresentation(void) const noexcept override;
	};
} /* disxx::ui */
