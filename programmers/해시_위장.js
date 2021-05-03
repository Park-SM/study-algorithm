function solution(clothes) {
    var answer = 1;
    const closet = {};
    for (let i = 0; i < clothes.length; i++) {
        closet[clothes[i][1]] = (closet[clothes[i][1]]) ? closet[clothes[i][1]] + 1 : 2;
    }
    for (let key in closet) {
        answer *= closet[key];
    }
    return answer - 1;
}