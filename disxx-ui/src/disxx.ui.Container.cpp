module disxx.ui.Container;

namespace disxx::ui
{
	ir::Widget Container::ProduceIntermidiateRepresentation(void) const noexcept
	{
		std::vector<ir::Widget> children{};
		children.reserve(this->m_Children.size());
		for (const auto &pChild : this->m_Children)
			if (pChild) [[likely]]
				children.emplace_back(pChild->ProduceIntermidiateRepresentation());

		ir::Widget self{};
		self.SetProperty(std::move(children));

		return self;
	}
} /* disxx::ui */
