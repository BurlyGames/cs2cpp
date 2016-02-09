// Arrays internals
template <typename T> class __array : public <<%assemblyName%>>::System::Array
{
	int32_t _rank;
	int32_t _length;
	T _data[0];
public:
    typedef CoreLib::System::Array base;
	// TODO: finish checking boundries
	__array(size_t length) : _rank(1) { _length = length; }
	inline const T operator [](size_t index) const { return _data[index]; }
	inline T& operator [](size_t index) { return _data[index]; }
	inline operator size_t() const { return (size_t)_length; }
};

template <typename T, size_t RANK> class __multi_array : public <<%assemblyName%>>::System::Array
{
	size_t _rank;
	int32_t _length;
	int32_t _lowerBoundries[RANK];
	int32_t _upperBoundries[RANK];
	T _data[0];
public:
    typedef CoreLib::System::Array base;
	// TODO: finish checking boundries
	template <typename... Ta> __multi_array(Ta... boundries) : _rank(RANK), _lowerBoundries{0}, _upperBoundries{boundries...} {}
	inline const T operator [](std::initializer_list<size_t> indexes) const { return _data[0]; }
	inline T& operator [](std::initializer_list<size_t> indexes) { return _data[0]; }
	inline operator size_t() const { return (size_t)_length; }
};

template <typename T, int N> class __array_init : public <<%assemblyName%>>::System::Array
{
	int32_t _length;
	T _data[N];
public:
    template <typename... Ta> __array_init(Ta... items) : _length(sizeof...(items)), _data{items...} {} 
};

// Boxing internals
template <typename D, typename S> inline D* __box(S v)
{
	return (D*) new S(v);
}

// Unboxing internals
template <typename D, typename C, typename S> inline D __unbox(S* c)
{
	// TODO: finish it
	D d;
	return d;
}

// interface cast internals
template <typename D, typename S> inline D interface_cast(S v)
{
	return (D) nullptr;
}

// interface cast internals
template <typename D, typename S> inline D as(S v)
{
	return (D) nullptr;
}

// interface cast internals
template <typename D, typename S> inline bool is(S v)
{
	return as<D>(v) != nullptr;
}

// Typeof internals
template <typename T> inline <<%assemblyName%>>::System::Type* _typeof()
{
	// TODO: finish it
	T* t;
	return nullptr;
}

// String literal
inline string* operator "" _s(const wchar_t* str, size_t len)
{
	return new string((wchar_t*)str, 0, (int32_t)len);
}

// Finally block
class Finally
{
public:
	std::function<void()> _dtor;
	Finally(std::function<void()> dtor) : _dtor(dtor) {};
	~Finally() { _dtor(); }
};

// __val conversions
#if _MSC_VER 
template<>
inline __val<intptr_t>::__val(const <<%assemblyName%>>::System::IntPtr& value)
#else
template<> template<>
inline __val<intptr_t>::__val<<<%assemblyName%>>::System::IntPtr>(const <<%assemblyName%>>::System::IntPtr& value)
#endif
{
	_value = reinterpret_cast<intptr_t>(value.m_value);
}

#if _MSC_VER 
template<>
inline __val<uintptr_t>::__val(const <<%assemblyName%>>::System::UIntPtr& value)
#else
template<> template<>
inline __val<uintptr_t>::__val<<<%assemblyName%>>::System::UIntPtr>(const <<%assemblyName%>>::System::UIntPtr& value)
#endif
{
	_value = reinterpret_cast<uintptr_t>(value.m_value);
}

// Interlocked
template <typename T>
T <<%assemblyName%>>::System::Threading::Interlocked::CompareExchange_Ref(T& location1, T value, T comparant)
{
    throw 0xC000C000;
}
