# Fenwick Tree
# Fenwick Tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.

# Time complexity: O(log n) for both update and query
# Space complexity: O(n)

# how to determine the question is related to Fenwick Tree?
# 1. The question is related to prefix sum
# 2. The question is related to range sum
# 3. The question is related to point update
# 4. The question is related to range update
# 5. The question is related to inversion count
# 6. The question is related to count of smaller numbers after self


class FenwickTree:
    """
    A Fenwick Tree (also known as a Binary Indexed Tree) implementation.

    Attributes:
        BIT (list): The binary indexed tree array.
        n (int): The size of the input array.
    """

    def __init__(self, n):
        """
        Initializes the Fenwick Tree with a given size.

        Args:
            n (int): The size of the input array.
        """
        self.BIT = [0] * (n + 1)
        self.n = n

    def update(self, i, val):
        """
        Updates the Fenwick Tree by adding a value to the given index.

        Args:
            i (int): The index to update.
            val (int): The value to add.
        """
        while i <= self.n:
            self.BIT[i] += val
            i += i & -i

    def query(self, i):
        """
        Queries the Fenwick Tree to get the prefix sum up to the given index.

        Args:
            i (int): The index up to which the prefix sum is calculated.

        Returns:
            int: The prefix sum up to the given index.
        """
        res = 0
        while i > 0:
            res += self.BIT[i]
            i -= i & -i
        return res

    def construct(self, arr):
        """
        Constructs the Fenwick Tree from a given array.

        Args:
            arr (list): The input array.
        """
        for i in range(1, self.n + 1):
            self.update(i, arr[i - 1])


if __name__ == '__main__':
    # Example usage
    freq = [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]
    obj = FenwickTree(len(freq))
    obj.construct(freq)

    print("Sum of elements in arr[0..5] is", obj.query(5))

    # Update the frequency array
    freq[3] += 6
    updateIndex = 3
    obj.update(updateIndex + 1, 6)  # Corrected the update value to 6

    print("Sum of elements in arr[0..5] is", obj.query(5))
