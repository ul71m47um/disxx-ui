export module disxx.ui.Image;

export import disxx.ui.Widget;

export namespace disxx::ui
{
	class __attribute__((visibility("default"))) [[nodiscard]] Image final : public Widget
	{
	  private:
		std::filesystem::path m_Image{};

	  public:
		explicit Image(void) noexcept = default;
		explicit Image(std::filesystem::path) noexcept;

		Image(const Image &) noexcept = default;
		Image &operator=(const Image &) = default;

		virtual ~Image(void) noexcept override = default;
		virtual ir::Widget ProduceIntermidiateRepresentation(void) const noexcept override;
	};
} /* disxx::ui */
