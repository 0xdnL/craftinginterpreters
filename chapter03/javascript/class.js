console.log(JSON.stringify(process.versions));

/* https://johnresig.com/blog/simple-javascript-inheritance/
 *
 * Simple JavaScript Inheritance
 * By John Resig https://johnresig.com/
 * MIT Licensed
 *
 * Inspired by base2 and Prototype
 */
(function(){
  var initializing = false;
  var fnTest       = /xyz/.test(function(){xyz;}) ? /\b_super\b/ : /.*/;

  this.Class = function(){};        // base Class implementation (does nothing)

  Class.extend = function(prop) {   // Create a new Class that inherits from this class

    var _super = this.prototype;

    // Instantiate a base class (but only create the instance, don't run the init constructor)
    initializing = true;
    var prototype = new this();
    initializing = false;

    for (var name in prop) {      // Copy the properties over onto the new prototype
      // Check if we're overwriting an existing function
      prototype[name] = typeof prop[name] == "function" &&
        typeof _super[name] == "function" && fnTest.test(prop[name]) ?
        (function(name, fn) {
          return function() {
            var tmp     = this._super;
            this._super = _super[name];           // Add a new ._super() method that is the same method but on the super-class
            var ret     = fn.apply(this, arguments);  // The method only need to be bound temporarily, so we remove it when we're done executing
            this._super = tmp;
            return ret;
          };
        })(name, prop[name]) :
        prop[name];
    }

    function Class() {                      // The dummy class constructor
      if ( !initializing && this.init )     // All construction is actually done in the init method
        this.init.apply(this, arguments);
    }

    Class.prototype             = prototype;            // Populate our constructed prototype object
    Class.prototype.constructor = Class;                // Enforce the constructor to be what we expect
    Class.extend                = arguments.callee;     // And make this class extendable
    return Class;
  };

})();

/* --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- */
/*
var Person = Class.extend({
  init: function(isDancing){
    this.dancing = isDancing;
  },
  dance: function(){
    return this.dancing;
  }
});

var Ninja = Person.extend({
  init: function(){
    this._super( false );
  },
  dance: function(){
    return this._super(); // Call the inherited version of dance()
  },
  swingSword: function(){
    return true;
  }
});

var p = new Person(true);
p.dance(); // => true

var n = new Ninja();
n.dance();    // => false
n.swingSword(); // => true

// Should all be true
p instanceof Person &&
p instanceof Class &&
n instanceof Ninja &&
n instanceof Person &&
n instanceof Class
*/
