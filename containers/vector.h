/*
 * vector.h
 *
 *  Created on: 28 Sep 2012
 *      Author: michael
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#define size_t unsigned int

namespace std {

template <class T>
class vector {
public:
	vector();
	vector(vector<T> &in);
	~vector();

	size_t size() const;
	size_t max_size() const;
	void resize(size_t sz, T c = T());
	size_t capacity() const;
	bool empty() const;
	void reserve(size_t n);

	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	T& at(size_t n);
	const T& at(size_t n) const;

	T& front();
	T& front() const;
	T& back();
	T& back() const;

	void assign (size_t n, const T& u);

	void push_back(const T& u);
	void pop_back();

	void clear();




private:
	class CPrivateData;
	CPrivateData *d;
};

} /* namespace std */

#include "vectorImpl.h"

#endif /* VECTOR_H_ */
