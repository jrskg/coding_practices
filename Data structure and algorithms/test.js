let arr = [
    [ 1, 1, 1, 0, 0, 0 ],
    [ 0, 1, 0, 0, 0, 0 ],
    [ 1, 1, 1, 0, 0, 0 ],
    [ 0, 0, 2, 4, 4, 0 ],
    [ 0, 0, 0, 2, 0, 0 ],
    [ 0, 0, 1, 2, 4, 0 ]
];

let output = [];
let oneD = [];
let twoD = [];
let count = 0;

for(let i  = 0; i < 3; i++){
    for(let j = i; j < arr[i].length; j++){
        if(j <= i+2){
            oneD[count] = arr[i][j];
            count++;
        }
       
    }
    console.log(oneD);
}