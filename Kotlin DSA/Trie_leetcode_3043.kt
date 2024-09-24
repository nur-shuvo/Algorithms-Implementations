data class TrieNode (
    val children: MutableMap<Char, TrieNode> = mutableMapOf(),
)

class Trie {
    private val root = TrieNode()
    
    fun insertWordForFirstArray(word: String) {
        var currentNode = root
        for (char in word) {
            currentNode = currentNode.children.getOrPut(char) {
                 TrieNode() 
            }
        }
    }

    fun countLCPSecondArrayWord(word: String): Int {
        var cntOfChar = 0
        var currentNode = root
        for (char in word) {
            currentNode = currentNode.children.get(char) ?: return cntOfChar
            cntOfChar++
        }
        return cntOfChar
    }
}

class Solution {
    fun longestCommonPrefix(arr1: IntArray, arr2: IntArray): Int {
        var maxLCPSize = 0
        var trie = Trie()
        for (int in arr1) trie.insertWordForFirstArray(int.toString())
        for (int in arr2) maxLCPSize = max(maxLCPSize, trie.countLCPSecondArrayWord(int.toString()))
        return maxLCPSize
    }
}