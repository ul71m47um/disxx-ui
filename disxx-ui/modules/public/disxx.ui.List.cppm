export module disxx.ui.List;

export import disxx.ui.Widget;

export namespace disxx::ui::ir
{
	class __attribute__((visibility("default"))) [[nodiscard]] List final : public Widget
	{
	  private:
		std::vector<std::unique_ptr<Widget>> m_Children{};

	  public:
		
	};
} /* disxx::ui::ir */
