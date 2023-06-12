template<typename T>
void swap(T*& left, T*& right)
{
    T* temp = left;
    left = right;
    right = temp;
};
