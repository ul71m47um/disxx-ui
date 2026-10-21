module disxx.ui.VSplitView;

namespace disxx::ui
{
	std::unique_ptr<Widget> VSplitView::Clone(void) const noexcept
	{ return std::make_unique<decltype(*this)>(*this); }

	ir::Widget VSplitView::ProduceIntermidiateRepresentation(void) const noexcept
	{
		auto self{Container::ProduceIntermidiateRepresentation()};
		self.SetType(ir::Type::TYPE_VSPLITVIEW);

		return std::move(self);
	}
} /* disxx::ui */
