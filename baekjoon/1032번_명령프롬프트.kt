import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val patterns = arrayListOf<String>()
    repeat(n) { patterns.add(next()) }

    var answer = ""
    patterns[0].forEachIndexed { idx, c ->
        val b = patterns.find { c != it[idx] }
        answer += if (b == null) c else "?"
    }
    print(answer)
}