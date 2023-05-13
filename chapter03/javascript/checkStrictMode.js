//"use strict";


function isStrictMode() {
  return (function() { return !this; })() === true;
}

if (isStrictMode()) {
  console.log("Strict mode is enabled.");
} else {
  console.log("Strict mode is not enabled.");
}

/*
  Alternatively, check whether a syntax error is thrown when you attempt to use a feature that is disallowed in strict mode
  e.g. in strict mode, using a variable without declaring it first will throw a ReferenceError
*/

var isStrictMode = (function() {
  'use strict';
  return function() { return !this; };
})();

try {
  // using an undeclared variable will throw a ReferenceError in strict mode
  foo = 'bar';
} catch (e) {
  if (e instanceof ReferenceError) {
    console.log("Strict mode is enabled.");
  } else {
    console.log("Strict mode is not enabled.");
  }
}
