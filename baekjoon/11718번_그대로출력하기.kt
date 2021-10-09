fun main() = with(System.`in`.bufferedReader()) {
    while(true) {
        val line = readLine()
        if (line != null) println(line) else break
    }
}