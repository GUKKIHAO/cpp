/*基类Vector_alloc_base*/
template <class _Tp, class _Allocator, bool _IsStatic>//类型，分配器，和？？？
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
//protected可以被派生类集成并直接使用	，所以后面有可能会用到
	protected:
		allocator_type _M_data_allocator;//配置器类型
  		_Tp* _M_start;//内存空间起始地址
 		_Tp* _M_finish;//已使用空间结束地址
  		_Tp* _M_end_of_storage;//可用空间结束地址
  		_Tp* _M_allocate(size_t __n)//配置空间
    	　{ return _M_data_allocator.allocate(__n); }//allocate(__n)应该是_Alloc_traits<_Tp, _Allocator>::allocator_type的成员函数
 		void _M_deallocate(_Tp* __p, size_t __n)//释放空间
    		{ if (__p) _M_data_allocator.deallocate(__p, __n); }


}
