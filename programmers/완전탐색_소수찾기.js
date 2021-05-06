function permutation(num, str) {    
    let result = [str];
    for (var i = 0; i < num.length; i++) {
        const arrrr = num.slice();
        const poped = arrrr.splice(i, 1);
        result = result.concat(permutation(arrrr, str + poped));
    }
    return result;
}

function isPrime(n) {
    if (n < 2) return false;
    for (var i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

function solution(numbers) {
    var answer = [];
    const num = numbers.split('');
    let arr = [];
    for (var i = 0; i < num.length; i++) {
        const arrrr = num.slice();
        const poped = arrrr.splice(i, 1);
        arr = arr.concat(permutation(arrrr, poped));
    }
    arr = arr.map( (e) => {return Number(e);}).sort();
    for (var i = 0; i < arr.length - 1; i++) {
        if (arr[i] && arr[i] == arr[i + 1]) arr.splice(i--, 1);
    }
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] && isPrime(arr[i])) answer.push(arr[i]);
    }
    return answer.length;
}