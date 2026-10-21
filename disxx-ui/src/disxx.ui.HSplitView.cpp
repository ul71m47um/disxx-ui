module disxx.ui.HSplitView;

namespace disxx::ui
{
	std::unique_ptr<Widget> HSplitView::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget HSplitView::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_HSPLITVIEW);

		return std::move(self);
	}
} /* disxx::ui */
