#include <iostream>
#include <vector>

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;
    const double growthFactor = 2;

public:
    DynamicArray() {
        arr = new int[1];
        size = 0;
        capacity = 1;
    }

    void pushBack(int element) {
        if (size == capacity) {
            capacity = (int)((double)capacity * growthFactor) + 1;
            int* temp = new int[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            
        }
        arr[size++] = element;
    }

    int getCapacity() {
        return this->capacity;
    }

    int getSize() {
        return this->size;
    }

    int& operator[](int index) {
        if (index > size || index < 0) {
            std::cerr << "array index out of bounds" << std::endl;
            exit(1);
        }
        return arr[index];
    }


    ~DynamicArray() {
        delete[] arr;
    }

};

int main()
{
    DynamicArray arr;
    for (int i = 0; i < 200; i++) {
        arr.pushBack(i * i);
        std::cout << arr.getSize() << " " << arr.getCapacity() << std::endl;
    }

    for (int i = 0; i < 200; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;



    
}

