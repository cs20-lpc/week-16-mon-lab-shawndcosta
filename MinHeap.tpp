template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
        while (i > 0) {
        int parent = (i - 1) / 2;
        if (data[i] >= data[parent]) {
            break;
        } 
        swap(data[i], data[parent]);
        i = parent;
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int n = size();
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;        
        if (left < n && data[left] < data[smallest]) {
            smallest = left;
        } 
        if (right < n && data[right] < data[smallest]) {
            smallest = right;
        }        
        if (smallest == i) {
            break;
        }        
        swap(data[i], data[smallest]);
        i = smallest;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    siftUp(size() - 1);

}

template <typename T>
T MinHeap<T>::removeRoot() {
    if (size() == 0) {
        throw runtime_error("empty heap");
    }
    T rootValue = data[0];
    data[0] = data.back();
    data.pop_back();    
    if (size() > 0) {
        siftDown(0);
    }    
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
       if (index < size()) {
        int originalIndex = index;
        siftUp(index);
        if (index == originalIndex) {
            siftDown(index);
        }
    }
}
