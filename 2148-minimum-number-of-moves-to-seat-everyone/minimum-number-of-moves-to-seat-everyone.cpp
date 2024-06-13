class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Find the maximum position in the arrays
        int maxPosition = max(findMax(seats), findMax(students));

        // Stores difference between number of seats and students at each
        // position
        vector<int> differences(maxPosition, 0);

        // Count the available seats at each position
        for (int position : seats) {
            differences[position - 1]++;
        }

        // Remove a seat for each student at that position
        for (int position : students) {
            differences[position - 1]--;
        }

        // Calculate the number of moves needed to seat the students
        int moves = 0;
        int unmatched = 0;
        for (int difference : differences) {
            moves += abs(unmatched);
            unmatched += difference;
        }

        return moves;
    }

private:
    int findMax(const vector<int>& array) {
        int maximum = 0;
        for (int num : array) {
            if (num > maximum) {
                maximum = num;
            }
        }
        return maximum;
    }
};