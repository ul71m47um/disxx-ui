module disxx.ui.Text;

export namespace disxx::ui
{
	Text::Text(std::string_view text) noexcept
		: Widget{}
		, m_Text{text}
	{}

	std::unique_ptr<Widget> Text::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget Text::ProduceIntermidiateRepresentation(void) const noexcept
	{
		ir::Widget self{};
		self.SetType(ir::Type::TYPE_TEXT);

		ir::Property<ir::Type::TYPE_TEXT> prop{};
		prop.SetText(this->m_Text);
		prop.SetColor(this->m_Color);
		self.SetProperty(std::move(prop));

		return std::move(self);
	}
} /* disxx::ui */
