module disxx.ui.ir.Widget:Property;

namespace disxx::ui::ir
{
	enum class Type
	{
		// Regular widgets
		TYPE_TEXT,
		TYPE_IMAGE,
		TYPE_BUTTON,
		TYPE_TEXTINPUT,

		// Containers
		TYPE_LIST,
		TYPE_TREE,
		TYPE_VSTACK,
		TYPE_HSTACK,
		TYPE_SPLITVIEW,
		TYPE_SCROLLVIEW,
		TYPE_LAZYVSTACK,
		TYPE_LAZYHSTACK
	};

	template <Type Kind>
	class __attribute__((visibility("default"))) [[nodiscard]] Property;

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_TEXT>
	{
	  private:
		std::array<float, 4> m_Color{};
		std::string m_Text{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetColor(std::array<float, 4>) noexcept;
		inline void SetText(std::string_view) noexcept;
	
		inline std::array<float, 4>	GetColor(void) const noexcept;
		inline std::string_view GetText(void) const noexcept;
	};

	inline void Property<Type::TYPE_TEXT>::SetColor(std::array<float, 4> color) noexcept
	{ this->m_Color = color; }
	
	inline void Property<Type::TYPE_TEXT>::SetText(std::string_view text) noexcept
	{ this->m_Text = text; }

	inline std::array<float, 4> Property<Type::TYPE_TEXT>::GetColor(void) const noexcept
	{ return this->m_Color; }

	inline std::string_view Property<Type::TYPE_TEXT>::GetText(void) const noexcept
	{ return this->m_Text; }

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_IMAGE>
	{
	  private:
		std::filesystem::path m_Path{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetPath(const std::filesystem::path) noexcept;
		
		inline std::filesystem::path GetPath(void) const noexcept;
	};

	inline void Property<Type::TYPE_IMAGE>::SetPath(const std::filesystem::path path) noexcept
	{ this->m_Path = path; }

	inline std::filesystem::path Property<Type::TYPE_IMAGE>::GetPath(void) const noexcept
	{ return this->m_Path; }

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_BUTTON>
	{
	  private:
		std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> m_Property{};
		std::function<void(void)> m_Callback{};
		std::array<float, 4> m_Color{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetPropery(std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>>) noexcept;
		inline void SetCallback(std::function<void(void)>) noexcept;
		inline void SetColor(std::array<float, 4>) noexcept;
	
		inline const std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> &GetProperty(void) const noexcept;
		inline const std::function<void(void)> &GetCallback(void) const noexcept;
		inline const std::array<float, 4> &GetColor(void) const noexcept;
	};

	inline void Property<Type::TYPE_BUTTON>::SetPropery(std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> property) noexcept
	{ this->m_Property = property; }	
	
	inline void Property<Type::TYPE_BUTTON>::SetCallback(std::function<void(void)> callback) noexcept
	{ this->m_Callback = callback; }	

	inline void Property<Type::TYPE_BUTTON>::SetColor(std::array<float, 4> color) noexcept
	{ this->m_Color = color; }

	inline const std::variant<Property<Type::TYPE_TEXT>, Property<Type::TYPE_IMAGE>> &Property<Type::TYPE_BUTTON>::GetProperty(void) const noexcept
	{ return this->m_Property; }

	inline const std::function<void(void)> &Property<Type::TYPE_BUTTON>::GetCallback(void) const noexcept
	{ return this->m_Callback; }

	inline const std::array<float, 4> &Property<Type::TYPE_BUTTON>::GetColor(void) const noexcept
	{ return this->m_Color; }

	template <>
	class __attribute__((visibility("default"))) [[nodiscard]] Property<Type::TYPE_TEXTINPUT>
	{
	  private:
		std::function<void(std::string)> m_Callback{};
		std::string m_Text{};

	  public:
		explicit Property(void) noexcept = default;

		Property(const Property &) noexcept = default;
		Property &operator=(const Property &) noexcept = default;

		inline void SetCallback(std::function<void(std::string)>) noexcept;
		inline void SetText(std::string_view) noexcept;
	
		inline const std::function<void(std::string)> &GetCallback(void) const noexcept;	
		inline std::string_view GetText(void) const noexcept;
	};

	inline void Property<Type::TYPE_BUTTON>::SetCallback(std::function<void(std::string)> callback) noexcept
	{ this->m_Callback = callback; }	

	inline void Property<Type::TYPE_TEXTINPUT>::SetText(std::string_view text) noexcept
	{ this->m_Text = text; }

	inline std::string_view Property<Type::TYPE_TEXTINPUT>::GetText(void) const noexcept
	{ return this->m_Text; }
	
	inline const std::function<void(std::string)> &Property<Type::TYPE_BUTTON>::GetCallback(void) const noexcept
	{ return this->m_Callback; }

	using AnyProperty = std::variant
	<
		Property<Type::TYPE_TEXT>,
		Property<Type::TYPE_IMAGE>,
		Property<Type::TYPE_BUTTON>,
		Property<Type::TYPE_TEXTINPUT>
	>;
} /* disxx::ui::ir */
