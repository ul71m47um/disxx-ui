module disxx.ui.TextInput;

export namespace disxx::ui
{
	TextInput::TextInput(std::string_view query, std::string &ref) noexcept
		: Widget{}
		, m_Query{query}
		, m_Text{std::forward<std::string &>(ref)}
	{}

	std::unique_ptr<Widget> TextInput::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget TextInput::ProduceIntermidiateRepresentation(void) const noexcept
	{
		ir::Widget self{};
		self.SetType(ir::Type::TYPE_TEXTINPUT);

		ir::Property<ir::Type::TYPE_TEXTINPUT> prop{};
		prop.SetText(this->m_Query);
		prop.SetCallback
		(
			[this](std::string input) -> void
			{ this->m_Text = input; }
		);
		self.SetProperty(std::move(prop));

		return std::move(self);
	}
} /* disxx::ui */
