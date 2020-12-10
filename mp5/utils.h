

template <typename T> inline
int compare(T &x, T &y)
{
    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}