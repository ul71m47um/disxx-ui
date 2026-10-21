module disxx.ui.VStack;

namespace disxx::ui
{
	std::unique_ptr<Widget> VStack::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget VStack::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_VSTACK);

		return std::move(self);
	}
} /* disxx::ui */
