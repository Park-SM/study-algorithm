function solution(answers) {
    var answer = [];
    const omr = [0, 0, 0];
    const patterns = [ [1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]];
    for (var i = 0; i < answers.length; i++) {
        if (answers[i] == patterns[0][i % patterns[0].length]) omr[0]++;
        if (answers[i] == patterns[1][i % patterns[1].length]) omr[1]++;
        if (answers[i] == patterns[2][i % patterns[2].length]) omr[2]++;
    }
    const max = Math.max.apply(null, omr);
    for (var i = 0; i < omr.length; i++) {
        if (max == omr[i]) answer.push(i + 1);
    }
    return answer;
}