function solution(brown, yellow) {
    const divisors = [];
    for (var i = 1; i <= yellow; i++) {
        if (yellow % i == 0) divisors.push([i, yellow / i]);
    }
    for (var i = 0; i < divisors.length; i++) {
        if (divisors[i][0] < divisors[i][1]) { divisors.shift(); i--; }
        else break;
    }
    for (var i = 0; i < divisors.length; i++) {
        if (((divisors[i][0] + 2) * 2) + (divisors[i][1] * 2) == brown) {
            return [divisors[i][0] + 2, divisors[i][1] + 2];
        }
    }
}