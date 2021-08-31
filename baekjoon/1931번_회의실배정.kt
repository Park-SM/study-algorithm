import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val room = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until n) room.add(nextInt() to nextInt())
    room.sortWith(compareBy({it.second}, {it.first}))

    var answer = 1
    var currentRoom = room[0]
    for (i in 1 until n) {
        if (currentRoom.second > room[i].first) continue
        currentRoom = room[i]
        answer++
    }
    print(answer)
}