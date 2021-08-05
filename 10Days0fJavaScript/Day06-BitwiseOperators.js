'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}
function getMaxLessThanK(n, k){
    
    let max = 0;
    for ( var i = 1 ;i < n ;i++){
        for (var j = i+1 ; j < n+1; j++){
            if ( Number(i & j) < k){
                if(Number(i & j) > max){
                    max = i & j;
                }
            }
        }
    }
    return max;
    
}
/*
    ERROR: "Terminated due to timeout :( , Time limit exceeded"
    TODO: Fix the time complexity.
    function getMaxLessThanK(n, k){
    
        let arr = Array.from({length: n}, (_, i) =>  i + 1); // '_'kullanilmayan eleman.
        // console.log(arr);
        // Output = Array [1, 2, 3, 4, 5]
            
        let arr2 = Array.from(arr, (el, i) =>  { 
            let tmpArr = Array.from({length: n - (i+1)}, (_, j) => el & (el + j + 1));
            // console.log(el + "=>" +tmpArr);
            // > "1=>0,1,0,1"
            // > "2=>2,0,0"
            // > "3=>0,1"
            // > "4=>4"
            // > "5=>"
            tmpArr = tmpArr.filter(el => el < k);
            return (!tmpArr || tmpArr.length === 0) ? 0 : Math.max(...tmpArr);  
        })
        // console.log(arr2);
        // Output = Array [1, 0, 1, 0, 0]
        return Math.max(...arr2)
    }
*/
