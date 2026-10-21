module disxx.ui.Image;

export namespace disxx::ui
{
	Image::Image(std::filesystem::path path) noexcept
		: Widget{}
		, m_Path{path}
	{}

	std::unique_ptr<Widget> Image::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget Image::ProduceIntermidiateRepresentation(void) const noexcept
	{
		ir::Widget self{};
		self.SetType(ir::Type::TYPE_IMAGE);

		ir::Property<ir::Type::TYPE_IMAGE> prop{};
		prop.SetText(this->m_Path);
		self.SetProperty(std::move(prop));

		return std::move(self);
	}
} /* disxx::ui */
