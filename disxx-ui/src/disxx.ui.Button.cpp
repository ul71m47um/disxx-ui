module disxx.ui.Button;

export namespace disxx::ui
{
	Button::Button(std::string_view text, std::function<void(void)> callback) noexcept
		: Widget{}
		, m_Text{text}
		, m_Callback{callback}
	{}

	std::unique_ptr<Widget> Button::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget Button::ProduceIntermidiateRepresentation(void) const noexcept
	{
		ir::Widget self{};
		self.SetType(ir::Type::TYPE_BUTTON);

		ir::Property<ir::Type::TYPE_BUTTON> prop{};
		prop.SetText(this->m_Text);
		prop.SetCallback(this->m_Callback);
		self.SetProperty(std::move(prop));

		return std::move(self);
	}
} /* disxx::ui */
