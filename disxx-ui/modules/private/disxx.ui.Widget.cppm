export module disxx.ui.Widget;

export namespace disxx::ui
{
	class __attribute__((visibility("default"))) [[nodiscard]] Widget
	{
	  public:
		enum class Identifier
		{
			ID_TEXT,
			ID_IMAGE,
			ID_BUTTON,
			ID_VSTACK,
			ID_HSTACK,
			ID_SCROLLVIEW,
			ID_VSPLITVIEW,
			ID_HSPLITVIEW
		};

		class __attribute__((visibility("default"))) [[nodiscard]] Property
		{
		  private:
			
		};

	  private:
		Identifier
	}
} /* disxx::ui */
