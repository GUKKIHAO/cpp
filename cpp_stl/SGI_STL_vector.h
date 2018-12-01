/*基类Vector_alloc_base*/
template <class _Tp, class _Allocator, bool _IsStatic>//类型，分配器，和_IsStatic用于？？？感觉没有起到作用啊
class _Vector_alloc_base//用来干嘛的？？？
{
	public:
		typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type
          		　allocator_type;
		//typedef创建了存在类型的别名，而typename告诉编译器_Alloc_traits<_Tp, _Allocator>::allocator_type是一个类型而不是一个成员
		allocator_type get_allocator() const { return _M_data_allocator; }//获取分配器类型
		_Vector_alloc_base(const allocator_type& __a)//构造函数声明和定义
		　: _M_data_allocator(__a), _M_start(0), _M_finish(0), _M_end_of_storage(0)
		{}
		//采用默认析构函数
//protected可以被派生类集成并直接使用，所以后面有可能会用到
	protected:
		allocator_type _M_data_allocator;//配置器类型
  		_Tp* _M_start;//内存空间起始地址
 		_Tp* _M_finish;//已使用空间结束地址
  		_Tp* _M_end_of_storage;//可用空间结束地址
  		_Tp* _M_allocate(size_t __n)//配置空间
    	　{ return _M_data_allocator.allocate(__n); }//allocate(__n)应该是_Alloc_traits<_Tp, _Allocator>::allocator_type的成员函数
 		void _M_deallocate(_Tp* __p, size_t __n)//释放空间
    		{ if (__p) _M_data_allocator.deallocate(__p, __n)

};
template <class _Tp, class _Allocator>//偏特化版
class _Vector_alloc_base<_Tp, _Allocator, true>　
{
	public:
		typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type
          		allocator_type;
		  _Vector_alloc_base(const allocator_type&)
    		: _M_start(0), _M_finish(0), _M_end_of_storage(0)
  		  {}
	protected:
		_Tp* _M_start;
		_Tp* _M_finish;
  		_Tp* _M_end_of_storage;
  		typedef typename _Alloc_traits<_Tp, _Allocator>::_Alloc_type _Alloc_type;
		_Tp* _M_allocate(size_t __n)//配置空间
    	  { return _Alloc_type::allocate(__n); }
  		void _M_deallocate(_Tp* __p, size_t __n)//释放空间
    	  { _Alloc_type::deallocate(__p, __n);}

};

template <class _Tp, class _Alloc>
struct _Vector_base//vector基类，继承自template <class _Tp, class _Allocator, bool _IsStatic>　class _Vector_alloc_base
//struct表示默认访问权限是public
  : public _Vector_alloc_base<_Tp, _Alloc,
                              _Alloc_traits<_Tp, _Alloc>::_S_instanceless>//S_instanceless是什么？？
{
	typedef _Vector_alloc_base<_Tp, _Alloc,
　                             _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
          　_Base;
	typedef typename _Base::allocator_type allocator_type;
	_Vector_base(const allocator_type& __a) : _Base(__a) {}//构造函数
	_Vector_base(size_t __n, const allocator_type& __a) : _Base(__a) {//构造函数
    	_M_start = _M_allocate(__n);
    	_M_finish = _M_start;
    	_M_end_of_storage = _M_start + __n;
  	}
	~_Vector_base() { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }//析构函数，调用_M_deallocate()函数
}；
template <class _Tp, class _Alloc>
//基类_Vector_base,
class _Vector_base
{
	public:
		typedef _Alloc allocator_type;
		allocator_type get_allocator() const { return allocator_type(); }//获取分配器类型
		_Vector_base(const _Alloc&)//默认构造函数
    　　　: _M_start(0), _M_finish(0), _M_end_of_storage(0) {}
		_Vector_base(size_t __n, const _Alloc&)//构造函数,
    　　　: _M_start(0), _M_finish(0), _M_end_of_storage(0)//对三个成员进行赋值
		 {
			_M_start = _M_allocate(__n);
			_M_finish = _M_start;
			_M_end_of_storage = _M_start + __n;
		  }
		~_Vector_base() { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }
	protected:
		_Tp* _M_start;//内存空间起始地址
		_Tp* _M_finish;//已使用空间结束地址
		_Tp* _M_end_of_storage;//可用空间结束地址
		//提供构造函数和析构函数接口		
		typedef simple_alloc<_Tp, _Alloc> _M_data_allocator;//simple_alloc<_Tp, _Alloc>是？？？配置器的简单版本？？？
		_Tp* _M_allocate(size_t __n)//分配内存空间
    	　{ return _M_data_allocator::allocate(__n); }
		void _M_deallocate(_Tp* __p, size_t __n) //释放内存空间
		　{ _M_data_allocator::deallocate(__p, __n); }
};
//vector类，保护继承自 _Vector_base类
//Alloc是SGI STL的空间配置器，默认是第二级配置器
template <class _Tp, class _Alloc = __STL_DEFAULT_ALLOCATOR(_Tp) >
class vector : protected _Vector_base<_Tp, _Alloc>
{
	 // requirements:
	__STL_CLASS_REQUIRES(_Tp, _Assignable);

	private:
		typedef _Vector_base<_Tp, _Alloc> _Base;//定义基类别名
	public://vector的内嵌型别定义
			//基本的数据
		typedef _Tp value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
			
		typedef typename _Base::allocator_type allocator_type;//配置器类型
  		allocator_type get_allocator() const { return _Base::get_allocator(); }
		//不清楚，反向迭代器的声明(有什么用)？？？
		#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
		　typedef reverse_iterator<const_iterator> const_reverse_iterator;
		　typedef reverse_iterator<iterator> reverse_iterator;
		#else /* __STL_CLASS_PARTIAL_SPECIALIZATION */
 		　typedef reverse_iterator<const_iterator, value_type, const_reference,
                  difference_type>  const_reverse_iterator;
 		　typedef reverse_iterator<iterator, value_type, reference, difference_type>
        　　		　reverse_iterator;
		#endif /* __STL_CLASS_PARTIAL_SPECIALIZATION */
	protected:
		#ifdef __STL_HAS_NAMESPACES
		  using _Base::_M_allocate;
		  using _Base::_M_deallocate;
		  using _Base::_M_start;
		  using _Base::_M_finish;
		  using _Base::_M_end_of_storage;
		#endif /* __STL_HAS_NAMESPACES */

	protected://在迭代器所指的地址插入x值
		void _M_insert_aux(iterator __position, const _Tp& __x);
		void _M_insert_aux(iterator __position);
	public://定义vector迭代器
		iterator begin() { return _M_start; }//指向内存空间起始地址的迭代器
		const_iterator begin() const { return _M_start; }
  		iterator end() { return _M_finish; }//指向已使用内存空间结束地址的迭代器
  		const_iterator end() const { return _M_finish; }

		reverse_iterator rbegin()
    	　	{ return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const
    		{ return const_reverse_iterator(end()); }
  		reverse_iterator rend()
   			{ return reverse_iterator(begin()); }
		const_reverse_iterator rend() const
		    { return const_reverse_iterator(begin()); }

		size_type size() const//vector容器大小，即容器内存储元素的个数
			{ return size_type(end() - begin()); }
		size_type max_size() const//返回可容纳最大元素数
    		{ return size_type(-1) / sizeof(_Tp); }
  		size_type capacity() const//vector容器可用空间的大小
    		{ return size_type(_M_end_of_storage - begin()); }
		bool empty() const//判断容器是否为空
			{ return begin() == end(); }

 		reference operator[](size_type __n) { return *(begin() + __n); }//返回指定位置的元素
		const_reference operator[](size_type __n) const { return *(begin() + __n); }

		#ifdef __STL_THROW_RANGE_ERRORS
  		//若用户要求的空间大于可用空间，抛出错误信息，即越界检查
		  void _M_range_check(size_type __n) const {
		    if (__n >= this->size())
		    	__stl_throw_range_error("vector");
		　}

  		　reference at(size_type __n)//访问指定元素，并且进行越界检查
    		{ _M_range_check(__n); return (*this)[__n]; }//访问前，先进行越界检查
		  const_reference at(size_type __n) const
		    { _M_range_check(__n); return (*this)[__n]; }
		#endif /* __STL_THROW_RANGE_ERRORS */
		explicit vector(const allocator_type& __a = allocator_type())
 		   : _Base(__a) {}//默认构造函数
  		vector(size_type __n, const _Tp& __value,
				const allocator_type& __a = allocator_type())
		    : _Base(__n, __a)//构造函数，里面包含n个初始值为value的元素
			//全局函数，填充值函数，即从地址M_start开始连续填充n个初始值为value的元素
    		{ _M_finish = uninitialized_fill_n(_M_start, __n, __value); }//uninitialized_fill_n填充函数从_M_start开始填充n个__value
		explicit vector(size_type __n)//该构造函数不接受初始值，只接受容易包含元素的个数n
		    : _Base(__n, allocator_type())
	    	{ _M_finish = uninitialized_fill_n(_M_start, __n, _Tp()); }
		vector(const vector<_Tp, _Alloc>& __x)
    		: _Base(__x.size(), __x.get_allocator())//拷贝构造函数
    		{ _M_finish = uninitialized_copy(__x.begin(), __x.end(), _M_start); }
		
		#ifdef __STL_MEMBER_TEMPLATES
		  // Check whether it's an integral type.  If so, it's not an iterator.
		  /*这个是某个区间的构造函数，首先判断输入是否为整数_Integral()
		  *采用__type_traits技术
		  */
		template <class _InputIterator>
  		vector(_InputIterator __first, _InputIterator __last,
         		const allocator_type& __a = allocator_type()) : _Base(__a) {
    		typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
    		_M_initialize_aux(__first, __last, _Integral());
  		}
  		template <class _Integer>
  		//若输入为整数，则调用该函数
  		void _M_initialize_aux(_Integer __n, _Integer __value, __true_type) {
    		_M_start = _M_allocate(__n);
    		_M_end_of_storage = _M_start + __n;
    		_M_finish = uninitialized_fill_n(_M_start, __n, __value);
  		}
  		template <class _InputIterator>
  		//若输入不是整数，则采用Traits技术继续判断迭代器的类型
  		void _M_initialize_aux(_InputIterator __first, _InputIterator __last,
                         		__false_type) {
    		_M_range_initialize(__first, __last, __ITERATOR_CATEGORY(__first));
  		}
		#else
  		vector(const _Tp* __first, const _Tp* __last,
         		const allocator_type& __a = allocator_type())
    	: _Base(__last - __first, __a)
    	{ _M_finish = uninitialized_copy(__first, __last, _M_start); }
		#endif /* __STL_MEMBER_TEMPLATES */

  		~vector() { destroy(_M_start, _M_finish); }//析构函数

};

























































































