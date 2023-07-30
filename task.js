console.log("First Console...");

setTimeout(() => {
    console.log("Console Timeout");
  }, 0);

Promise.resolve().then(() => {
  console.log("Console Promise");
});

console.log("Last Console...");


// first console
// console time out
// console promise
// last console
