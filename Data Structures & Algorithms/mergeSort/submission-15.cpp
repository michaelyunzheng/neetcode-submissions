// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.size() <= 1) {
            return pairs;
        }

        auto midpoint = pairs.begin() + pairs.size() / 2;
        std::vector<Pair> first_half(pairs.begin(), midpoint);
        std::vector<Pair> second_half(midpoint, pairs.end());

        first_half = mergeSort(first_half);
        second_half = mergeSort(second_half);

        return merge(first_half, second_half);
    }

    vector<Pair> merge(
        const vector<Pair>& left,
        const vector<Pair>& right
    ) {    
        vector<Pair> result;

        int i = 0;
        int j = 0;

        while (i < left.size() and j < right.size()) {
            if (left[i].key <= right[j].key) {
                result.push_back(left[i++]);
            } else {
                result.push_back(right[j++]);
            }            
        }

        while (i < left.size()) {
            result.push_back(left[i++]);
        }

        while (j < right.size()) {
            result.push_back(right[j++]);
        }

        return result;
    }
};
