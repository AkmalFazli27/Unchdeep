from BinarySearchTree import AddX,Akar

def BuildBSTFromList(elements):
    """Build a BST from a list of elements recursively."""
    if not elements:
        return None  # Base case: empty list results in an empty tree
    else:
        # Insert the first element into the BST and recursively process the rest
        return AddX(BuildBSTFromList(elements[1:]), elements[0])

# Example list of elements
elements = [2, 3, 4, 5, 6, 7, 8]

# Build the BST
bst = BuildBSTFromList(elements)

# Output or visualize the BST
print(bst)
