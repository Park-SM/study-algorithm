import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val t = nextInt()
    repeat(t) {

        var isVps = true
        val stack = Stack<Char>()
        next().forEach {
            if (it == '(') {
                stack.add(it)
            } else {
                if (stack.isEmpty()) {
                    isVps = false
                    return@forEach
                }
                stack.pop()
            }
        }
        isVps = isVps && stack.isEmpty()
        println(if (isVps) "YES" else "NO")
    }
}