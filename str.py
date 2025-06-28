def remove_chars(word, n):
    if n < len(word):
        result = ''.join(char for index, char in enumerate(word) if index != n)
        return result
    else:
        print(f"Error: Index {n} is greater than or equal to the length of the word.")
        return word


# Example usage:
input_word = input("Enter a word: ")
index_to_remove = int(input("Enter the index to remove: "))

result_word = remove_chars(input_word, index_to_remove)
print(f"Result: {result_word}")

