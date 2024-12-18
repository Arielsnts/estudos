const indef = (x) => typeof x == "undefined"

const quickSort = ([x, ...xs]) => {
    if (indef(x)) return []
    
    const a = xs.filter(n => n <= x)
    const b = xs.filter(n => n > x)

    return [...quickSort(a), x, ...quickSort(b)]
}

console.log(quickSort([3,4,2,6,1,5,7]))