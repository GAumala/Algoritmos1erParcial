const spawn = require('child_process').spawn;

const silent = process.argv.length == 3 && process.argv[2] === "-s"
const algoritmos = ["countsort", "quicksort", "qsort_gcc", "bitonicsort",
"insertionsort", "shakersort"]
const results = []
const tests = []
const iterations = 3 //cuantas veces voy a iterar para calcular promedio

let index = 0

function createRandomTests(){
  for(let i = 0; i < iterations; i++){
    const algoritmosCopy = Object.assign([], algoritmos)
    while(algoritmosCopy.length > 0){
      randomIndex = Math.random() * algoritmosCopy
      deletedItem = algoritmosCopy.splice(randomIndex, 1)[0]
      tests.push(deletedItem)
    }
  }
}

function initResults(){
  algoritmos.forEach((al) => {
    results[al] = 0
  })
}

function postResults(){
  algoritmos.forEach((al) => {
    console.log(`${al},${parseFloat(results[al]/iterations).toFixed(3)} ms.`)
  })
}

function runTest(){
  const algorithmName = tests[index]
  const startTime = new Date().getTime()
  const algoritmo = spawn("./" + algorithmName, []);

/*
  algoritmo.stdout.on('data', (data) => {
    console.log(data);
  })
  */

  algoritmo.on('close', (code) => {
    const endTime = new Date().getTime()
    const diff = endTime - startTime
    results[algorithmName] += diff
    //console.log(algorithmName + ":\t" + diff + " ms.")
    index++;
    if(index < tests.length){
      if((index % algoritmos.length === 0)){
        createNewList()
      } else {
        runTest()
      }
    } else {
      postResults();
    }
  })
}

function createNewList(){
  const listGenerator = spawn("./newlist", []);
  listGenerator.stderr.setEncoding("utf8");
  listGenerator.stderr.on('data', logOutput)
  listGenerator.on('close', (code) => {
    if(code == 0)
      runTest()
  })

}
function logOutput(data){
  if(!silent)
    console.log(data)
}
function start(){
  const make = spawn("make", []);
  make.stdout.setEncoding('utf8');
  make.stderr.setEncoding('utf8');
  make.stdout.on('data', logOutput)
  make.stderr.on('data', logOutput)
  make.on('close', (code) => {
    if(code == 0)
      createNewList()
  })
}

initResults();
createRandomTests();
start();
