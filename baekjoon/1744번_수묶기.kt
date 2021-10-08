import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val positives = mutableListOf<Int>()
    val negatives = mutableListOf<Int>()
    var oneCnt = 0
    var hasZero = false
    repeat(n) {
        val t = nextInt()
        when {
            t >  1 -> positives.add(t)
            t <  0 -> negatives.add(t)
            t == 1 -> oneCnt++
            t == 0 -> hasZero = true
        }
    }
    positives.sortDescending()
    negatives.sort()

    var sum = 0

    // 1보다 큰 정수 계산
    sum += _folding(positives, -1)
    if (positives.size % 2 != 0) sum += positives.last()

    // 1 개수만큼 계산
    sum += oneCnt

    // 0보다 작은 정수들 계산
    sum += _folding(negatives, 1)
    if (negatives.size % 2 != 0) sum += if (hasZero) 0 else negatives.last()

    print(sum)
    close()
}

fun _folding(list: List<Int>, prevInit: Int): Int {
    var sum = 0
    var prev = prevInit
    for (i in list.indices) {
        if (prev == prevInit) {
            prev = list[i]
        } else {
            sum += prev * list[i]
            prev = prevInit
        }
    }
    return sum
}