import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
	val n = nextInt()
	
	// 1로 시작하는 모든 고리의 경우의 수 생성
	val lists = mutableListOf<List<Int>>()
	makeLists(lists, mutableListOf<Int>(), n, 1)
	
	// 생성한 경우의 수 중에 소수 리스트만 추출
	val primeLists = mutableListOf<List<Int>>()
	for (i in lists.indices) {
		if (isPrimeList(lists[i])) primeLists.add(lists[i])
	}
	
	// 출력 예시에 맞게 소수 리스트 출력
	for (i in primeLists.indices) {
		for (j in 0 until n) {
			print(primeLists[i][j])
			if (j != primeLists[i].lastIndex) print(" ")
		}
		if (i != primeLists.lastIndex) println()
	}
}

fun makeLists(lists: MutableList<List<Int>>, list: MutableList<Int>, n: Int, s: Int) {
	list.add(s)
	if (list.size == n) {
		lists.add(list)
	} else {
		for (i in 2..n) {
			if (!list.contains(i)) {
				val clone = mutableListOf<Int>().apply { addAll(list) }
				makeLists(lists, clone, n, i)
			}
		}
	}
}

fun isPrimeList(list: List<Int>): Boolean {
	
	fun isPrime(n: Int): Boolean {
		var i = 2
		while (i * i <= n) {
			if (n % i++ == 0) return false
		}
		return true
	}
	
	val firstCheck = list[0] + list.last()
	if (!isPrime(firstCheck)) return false
	
	for (i in 1 until list.size) {
		if (!isPrime(list[i - 1] + list[i])) return false
	}
	return true
}





