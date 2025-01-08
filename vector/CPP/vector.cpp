
#include <iostream>
#include <stdexcept> // For exceptions like std::out_of_range

template <typename T>
class Vector {
private:
    T* data;          // Pointer to the dynamic array
    size_t size_;     // Number of elements in the vector
    size_t capacity_; // Capacity of the vector

    // Resizes the underlying array to a new capacity
    void resizeCapacity(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = data[i];
        }
        delete[] data; // Free the old memory
        data = newData;
        capacity_ = newCapacity;
    }

public:
    // Constructor
    Vector() : data(nullptr), size_(0), capacity_(0) {}

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Return the size
    size_t size() const {
        return size_;
    }

    // Return the capacity
    size_t capacity() const {
        return capacity_;
    }

    // Check if the vector is empty
    bool empty() const {
        return size_ == 0;
    }

    // Access an element with bounds checking
    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Access an element without bounds checking
    T& operator[](size_t index) {
        return data[index];
    }

    // Add an element to the end
    void push_back(const T& value) {
        if (size_ == capacity_) {
            size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            resizeCapacity(newCapacity);
        }
        data[size_++] = value;
    }

    // Remove the last element
    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    // Clear all elements
    void clear() {
        size_ = 0;
    }

    // Iterator support (simplified)
    T* begin() {
        return data;
    }

    T* end() {
        return data + size_;
    }
};

int main() {
    Vector<int> vec;

    // Add elements
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Display elements
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    // Check size and capacity
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";

    // Remove an element
    vec.pop_back();
    std::cout << "After pop_back, size: " << vec.size() << "\n";

    return 0;
}
