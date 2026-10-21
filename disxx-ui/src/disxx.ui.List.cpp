module disxx.ui.List;

namespace disxx::ui
{
	std::unique_ptr<Widget> List::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget List::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_LIST);

		return std::move(self);
	}
} /* disxx::ui */
