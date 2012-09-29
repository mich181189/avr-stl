/*
 * vectorImpl.h
 *
 *  Created on: 28 Sep 2012
 *      Author: michael
 */




namespace std {

	template <class T>
	class vector<T>::CPrivateData
	{
	public:
		CPrivateData() : m_ptr(0),m_nSize(0), m_nAlloc(0) {}
		T* m_ptr;
		unsigned int m_nSize;
		unsigned int m_nAlloc;
	};

	template <class T>
	vector<T>::vector()
		 : d(new CPrivateData)
	{
		// TODO Auto-generated constructor stub

	}

	template <class T>
	vector<T>::vector(vector<T> &in)
		: d(new CPrivateData)
	{
		reserve(in.size());
		for(int i=0;i<in.size();++i)
		{
			at(i) = in[i];
		}
	}

	template <class T>
	vector<T>::~vector()
	{
		delete d->m_ptr;
	}

	template <class T>
	size_t vector<T>::size() const
	{
		return d->m_nSize;
	}

	template <class T>
	size_t vector<T>::max_size() const
	{
		//Estimate 2k of memory, and divide by size. This is a guess!
		return 2000/sizeof(T);
	}

	template <class T>
	void vector<T>::resize(size_t sz, T c)
	{
		if(sz > d->m_nAlloc)
		{
			reserve(sz);
			for(int i=d->m_nSize;i< sz;++i)
			{
				d->m_ptr[i] = c;
			}
		}
		d->m_nSize = sz;
	}

	template <class T>
	size_t vector<T>::capacity() const
	{
		return d->m_nAlloc;
	}

	template <class T>
	bool vector<T>::empty() const
	{
		return (d->m_nSize == 0);
	}

	template <class T>
	void vector<T>::reserve(size_t n)
	{
		T* tmp = new T[n];
		if(n > d->m_nAlloc)
		{
			//growing
			for(int i=0;i<d->m_nAlloc;++i)
			{
				tmp[i] = d->m_ptr[i];
			}

			delete d->m_ptr;
			d->m_ptr = tmp;
			d->m_nAlloc = n;
		}
	}

	template <class T>
	T& vector<T>::operator[](size_t n)
	{
		return d->m_ptr[n];
	}

	template <class T>
	const T& vector<T>::operator[](size_t n) const
	{
		return d->m_ptr[n];
	}

	template <class T>
	T& vector<T>::at(size_t n)
	{
		return d->m_ptr[n];
	}

	template <class T>
	const T& vector<T>::at(size_t n) const
	{
		return d->m_ptr[n];
	}

	template <class T>
	T& vector<T>::front()
	{
		return d->m_ptr[0];
	}

	template <class T>
	T& vector<T>::front() const
	{
		return d->m_ptr[0];
	}

	template <class T>
	T& vector<T>::back()
	{
		return d->m_ptr[d->m_nSize-1];
	}

	template <class T>
	T& vector<T>::back() const
	{
		return d->m_ptr[d->m_nSize-1];
	}

	template <class T>
	void vector<T>::assign (size_t n, const T& u)
	{
		return d->m_ptr[n] = u;
	}

	template <class T>
	void vector<T>::push_back(const T& u)
	{
		d->m_ptr[d->m_nSize++] = u;
	}

	template <class T>
	void vector<T>::pop_back()
	{
		--(d->m_nSize);
	}

	template <class T>
	void vector<T>::clear()
	{
		d->m_nSize = 0;
	}

} /* namespace std */

