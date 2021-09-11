import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    
    while(true) {

        val str = readLine()
        if (str[0] == '.') break

        val stack = Stack<Char>()
        var isBalanced = true
        for (i in str.indices) {
            when (str[i]) {
                ')' -> {
                    if (stack.isEmpty() || stack.peek() != '(') {
                        isBalanced = false
                        break
                    } else {
                        stack.pop()
                    }
                }
                ']' -> {
                    if (stack.isEmpty() || stack.peek() != '[') {
                        isBalanced = false
                        break
                    } else {
                        stack.pop()
                    }
                }
                '(', '[' -> stack.push(str[i])
            }
        }
        if (isBalanced && stack.isEmpty()) {
            println("yes")
        } else {
            println("no")
        }
    }
}