#include <memory>
#include <limits>
#include <stdexcept>
#include <cmath>
template<typename T, Alloc = alloc>
class vector {
public:
	typedef T value_type; 
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef allocator<value_type> allocator_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	typedef allocator<T> mem_allocate;

	reverse_iterator<iterator> reverse_iterator;
	reverse_iterator<const_iterator> const_reverse_iterator;

	vector() = default;

	explicit vector (const allocator_type& alloc = allocator_type());

	explicit vector (size_type n);

    vector (size_type n, const value_type& val,
                 const allocator_type& alloc = allocator_type());	

	template <class InputIterator>
	  vector (InputIterator first, InputIterator last,
          		const allocator_type& alloc = allocator_type());
	
	vector (const vector& x);
	vector (const vector& x, const allocator_type& alloc);
	
	vector (vector&& x);
	vector (vector&& x, const allocator_type& alloc);

	vector (initializer_list<value_type> il,
	       const allocator_type& alloc = allocator_type());

	~vector() {}

	iterator begin() {
		return start;
	}

	iterator end() {
		return finish;
	}

	reverse_iterator rbegin() {
		return finish;
	}

	reverse_iterator rend() {
		return start;
	}

	const_iterator cbegin() {
		return start;
	}

	const_iterator cend() {
		return end;
	}

	const_reverse_iterator crbegin() {
		return end;
	}

	const_reverse_iterator crend() {
		return begin;
	}

	size_type size() const {
		return finish - start;
	}

	size_type max_size() {	//所能存储的最多元素个数
		return numeric_limits<size_t>::max();
	}

	/* Returns the size of the storage space currently 
	 * allocated for the vector, expressed in terms of elements.
	 */
	size_type capacity() const noexcept {	
		return end_of_storage - start;
	}

	void resize (size_type n) {
		allocator(n);
	}

	void resize (size_type n, const value_type& val) {
		allocator(n);
		uninitialized_fill(first, first + n, val);
	}

	bool empty() const noexcept {
		return size() == 0 ? true : false;
	}

	void reserve (size_type n) {
		try {
			if (n > capacity()) {
				allocator(n);
			}
		} catch (const std::length_error& le) {
			  std::cerr << "Length error: " << le.what() << '\n';
		  }
	}
	
	void shrink_to_fit() {
		allocator(size());
	}

	reference operator[] (size_type n) {
		try {
		    return *(first + n);
		}
		catch (const std::out_of_range& oor) {
		    std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
	}

	const_reference operator[] (size_type n) const {
		try {
		    return *(first + n);
		}
		catch (const std::out_of_range& oor) {
		    std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
	}

	reference at (size_type n) {
		try {
		    return *(first + n);
		}
		catch (const std::out_of_range& oor) {
		    std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
	}

	const_reference at (size_type n) const {
		try {
		    return *(first + n);
		}
		catch (const std::out_of_range& oor) {
		    std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
	}

	reference front() {
		return *first;
	}
	const_reference front() const {
		return *first;
	}

	reference back() {
		return *(end() - 1);
	}
	const_reference back() const {
		return *(end() - 1);
	}

	value_type* data() noexcept {
		return first;
	}
	const value_type* data() const noexcept {
		return first;
	}

	template <class InputIterator>
    void assign (InputIterator first_a, InputIterator last_a) {
    	auto tmp = first;
    	for(auto ite = first_a; ite != last_a; ++ite) {
    		*tmp++ = *ite;
    	}
    }

	void assign (size_type n, const value_type& val) {
		auto tmp = first;
		do{
			*(tmp + (--n)) = val;
		} while(n)
	}

	void assign (initializer_list<value_type> il) {
		auto tmp = first;
		for(auto ite = il.begin(); ite != il.end(); ++ite) {
			*tmp++ = *ite;
		}
	}

	void push_back (const value_type& val) {
		if(behind_last == behind_entire) {
			allocator(n * log2(n));
		} 
		*behind_last = val;
		++behind_last;
	}
	void push_back (value_type&& val) {

	}
private:
	iterator first;               // 表示目前使用空间的头
	iterator behind_last;              // 表示目前使用空间的尾后
	iterator behind_entire;      // 表示实际分配内存空间的尾后

	void allocator(size_type n) {
		auto new_data = mem_allocate.allocate(n);
		auto dest = new_data;
		for(size_type i = 0; i != size(); ++i) {
			mem_allocate.construct(dest++, std::move(*first++));
		}
		free();
		first = new_data;
		behind_last = dest;
		behind_entire = first + n;
	}

	void free() {
		if(first) {
			for(auto p = behind_last; p != first;)
				mem_allocate.destory(--p);
			mem_allocate.deallocate(first, behind_entire - first);
		}
	}
}