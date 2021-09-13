
fun main() {
    val s = readLine()!!.toLong()

    var i = 0
    var fac = 0L
    do {
        fac += ++i
    } while (fac < s)

    println(if (fac == s) i else i - 1)
}