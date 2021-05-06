function dfs(nums, target, num = 0) {
    if (!nums.length) return target == num;
    
    const arrrr = nums.slice();
    const poped = arrrr.shift();
    return dfs(arrrr, target, num + poped) + dfs(arrrr, target, num - poped);
}

function solution(numbers, target) {
    return dfs(numbers, target);
}