#pragma once
#include <iostream>
/// @brief ArrayList is a dynamic array implementation.
/// @tparam T The type of elements stored in the list.
template <typename T>
class ArrayList{
private:
    /// @brief Pointer to the array that holds the elements.
    T* arr;
    /// @brief Index of the last element in the list.
    size_t size;
    /// @brief Maximum number of elements the list can hold.
    size_t capacity;
public:
    /// @brief Default constructor
    ArrayList();
    /// @brief Copy constructor
    ArrayList(const ArrayList<T>& other);
    /// @brief Construct a list with capacity and values to fill
    ArrayList(size_t c, T vals = T());
    /// @brief Construct a list with a specific capacity.
    ArrayList(size_t c);
    /// @brief Assignment operator
    ArrayList<T>& operator=(const ArrayList<T>& other);
    /// @brief Destructor
    ~ArrayList();
    /// @brief Return number of elements in the list.
    size_t length(void) const;
    /// @brief Retrieve the element at position i.
    const T& get(size_t idx) const;
    /// @brief Find the position of element x (if present).
    size_t find(T x) const;
    /// @brief Insert element x at position i.
    void insert(size_t idx, T x);
    /// @brief Add element x at the end of the list.
    void append(T x);
    /// @brief Add element x at the beginning.
    void prepend(T x);
    /// @brief Remove element at position i.
    void remove(size_t idx);
    /// @brief Remove first occurrence of element x.
    void remove(T x);
    /// @brief Remove all elements.
    void clear(void);
    /// @brief Replace element at position i with x
    void set(size_t idx, T x);
    /// @brief Prints all elements in order to std::cout.
    void traverse(void) const;
    /// @brief Check if the list has no elements.
    bool isEmpty(void) const;
    /// @brief Check if the list is full.
    bool isFull(void) const;
    /// @brief Check if element x exists in the list.
    bool contains(T x) const;
    /// @brief Get a sublist from position i to j (inclusive of i, exclusive of j).
    ArrayList<T> subList(size_t i, size_t j);
    /// @brief Reverse the order of elements.
    void reverse(void);
};