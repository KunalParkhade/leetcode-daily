class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array length is less than or equal to 2, return its length directly.
        if (nums.size() <= 2) return nums.size();

        // Initialize the write index at 1 since the first element is always allowed.
        int write_index = 1;

        // Initialize a counter for the current element occurrence.
        int count = 1;

        // Iterate from the second element to the end of the array.
        for (int read_index = 1; read_index < nums.size(); read_index++) {
            if (nums[read_index] == nums[read_index - 1]) {
                // If the current element is the same as the previous one, increment the count.
                count++;
            } else {
                // If the current element is different, reset the count to 1.
                count = 1;
            }

            // If the count is less than or equal to 2, copy the element to write_index and increment write_index.
            if (count <= 2) {
                nums[write_index] = nums[read_index];
                write_index++;
            }
        }

        // Return the new length of the array where duplicates appear at most twice.
        return write_index;
    }
};
