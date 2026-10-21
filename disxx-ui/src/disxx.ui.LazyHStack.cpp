module disxx.ui.LazyHStack;

namespace disxx::ui
{
	std::unique_ptr<Widget> LazyHStack::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget LazyHStack::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_LAZYHSTACK);

		return std::move(self);
	}
} /* disxx::ui */
