module disxx.ui.Container;

namespace disxx::ui
{
	Container::Container(const Container &other) noexcept
		: Widget{other}
		, m_Children{}
	{
		for (const auto &pChild : other.m_Children)
			if (pChild) [[likely]]
				this->m_Children.emplace_back(pChild->Clone());
	}

	Container &Container::operator=(const Container &other) noexcept
	{
		if (this != &other) [[likely]]
		{
			Widget::operator=(other);
			for (const auto &pChild : other.m_Children)
				if (pChild) [[likely]]
					this->m_Children.emplace_back(pChild->Clone());
		}

		return *this;
	}

	Container::Container(Container &&other) noexcept
		: Widget{std::forward<Container &&>(other)}
		, m_Children{std::move(other.m_Children)}
	{}

	Container &Container::operator=(const Container &other) noexcept
	{
		if (this != &other) [[likely]]
		{
			Widget::operator=(std::forward<Container &&>(other));
			this->m_Children = std::move(other.m_Children);
		}

		return *this;
	}

	ir::Widget Container::ProduceIntermidiateRepresentation(void) const noexcept
	{
		std::vector<ir::Widget> children{};
		children.reserve(this->m_Children.size());
		for (const auto &pChild : this->m_Children)
			if (pChild) [[likely]]
				children.emplace_back(pChild->ProduceIntermidiateRepresentation());

		ir::Widget self{};
		self.SetProperty(std::move(children));

		return std::move(self);
	}
} /* disxx::ui */
