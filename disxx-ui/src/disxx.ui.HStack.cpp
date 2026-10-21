module disxx.ui.HStack;

namespace disxx::ui
{
	std::unique_ptr<Widget> HStack::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget HStack::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_HSTACK);

		return std::move(self);
	}
} /* disxx::ui */
