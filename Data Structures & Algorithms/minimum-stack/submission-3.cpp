class MinStack {
    std::vector<int> arr;
    std::vector<int> min_array;

public:
    MinStack() {}

    void push(int val) {
        arr.push_back(val);

        if (min_array.empty()) {
            min_array.push_back(val);
        } else {
            min_array.push_back(std::min(val, min_array.back()));
        }
    }

    void pop() {
        arr.pop_back();
        min_array.pop_back();
    }

    int top() {
        return arr.back();
    }

    int getMin() {
        return min_array.back();
    }
};