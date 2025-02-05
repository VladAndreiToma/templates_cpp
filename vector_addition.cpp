// we want to perform addition on vectors
// we ll use templates to work with resources directly and not creating other objects
#include <iostream>
using namespace std;

template <typename T>
class MyVector{
    private:
        int* data_; // array so its continuous memory it has to be a pointer to the head
        int size_;
    public:
        MyVector( int size ) :
         size_(size) , data_( new int[size] ){
            // constructor passes size and allocates room for the array
         }
        int& operator[]( int posx ){
            return data_[posx];
        }
        int size() const { return size_; }
}

template <typename T>
MyVector<T> operator+( const MyVector<T>& v ,
    const MyVector<T>& w ){
        // constructs the result
        // addition makes sense if the two vectors are the same
        MyVector<T> result( v.size() );
        for( int i = 0 ; i < v . size() ; i++ ){
            result[i] = v[i] + w[i];
        }
        return result;
}

int main(){
    MyVector<int> v1(5);
    MyVector<int> v2(5);
    MyVector<int> v3 = v1 + v2;

return 0;
}


// the above code does not work as expected cause there is a problem
// the operator cannot be T& type nor const T& type as it must be const qualified
// so we have to define the T& operator first and establish the action of it
// but when [] operator access the element inside the array we have to be able to not modify the array so we overwrite with a version of &


#include <iostream>
using namespace std;

template <typename T>
class MyVector {
private:
    T* data_;   // array, it has to be a pointer to the head
    int size_;  // size of the vector
public:
    MyVector(int size) : size_(size), data_(new T[size]) {}

    ~MyVector() { delete[] data_; }

    // Non-const version for modification
    T& operator[](int posx) {
        return data_[posx];
    } // this is the intended version for when we add the elements of 2 or multiple arrays into one
    // so it access here has the property that it modifies the structure of the array

    // Const version for read-only access
    const T& operator[](int posx) const {
        return data_[posx];
        // read only cannot modify the content so explicit return is casted to const
    }

    int size() const { return size_; }

    // Addition operator will now handle size mismatch
    friend MyVector<T> operator+(const MyVector<T>& v, const MyVector<T>& w) {
        if (v.size() != w.size()) {
            throw std::invalid_argument("Vectors must be of the same size for addition.");
        }

        MyVector<T> result(v.size());
        for (int i = 0; i < v.size(); i++) {
            result[i] = v[i] + w[i];
        }

        return result;
    }
};

int main() {
    MyVector<int> v1(5);
    MyVector<int> v2(5);
    MyVector<int> v3 = v1 + v2;

    return 0;
}
