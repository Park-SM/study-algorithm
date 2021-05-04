function solution(numbers) {
    const answer = numbers.map( (a) => { return String(a); })
                          .sort( (a, b) => { return (b + a) - (a + b) })
                          .join('');
    return answer == 0 ? "0" : answer;
}