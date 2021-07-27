template<class T, T v>
struct integral_constant {
    static constexpr T value = v;
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

template<class T>
struct is_pointer: false_type { };

template<class T>
struct is_pointer<T*>: true_type { };

template<typename T>
constexpr auto is_pointer_v = is_pointer<T>::value;

int main() {
    static_assert(is_pointer_v<int*>);
    static_assert(not is_pointer_v<int>);
}
