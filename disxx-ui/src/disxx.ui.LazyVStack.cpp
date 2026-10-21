module disxx.ui.LazyVStack;

namespace disxx::ui
{
	std::unique_ptr<Widget> LazyVStack::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget LazyVStack::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_LAZYVSTACK);

		return std::move(self);
	}
} /* disxx::ui */
