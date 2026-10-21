module disxx.ui.Tree;

namespace disxx::ui
{
	std::unique_ptr<Widget> Tree::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget Tree::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_TREE);

		return std::move(self);
	}
} /* disxx::ui */
