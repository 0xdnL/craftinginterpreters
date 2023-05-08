// by value borrows / consumes input -> must allocate memory foreach consumption
fn greet_by_val(name: String) {
  println!("greet_by_val: Hello, {}!", name)
}

fn greet_by_ref(name: &String) {
  println!("greet_by_ref: Hello, {}!", name)
}

/*
  example: "telling the compiler what the intentions are"

  fn divide(x: &mut i32, y: i32) -> Result<(),String> {
    // don't know what goes on here
    // but we see that fn returns as "Result" with a
    // "()" Success to be discarded OR
    //  "Error" in form of String Message

    // y is passed by vall -> discarded after fn-call
    // x is  a mutable ref -> it can and most likely will be changed
  }
  let val = divid(&mut some_ref, num);
*/

fn main() {
  let name = "Foo".to_string(); // move occurs because `name` has type `String`, which does not implement the `Copy` trait
  println!("{}", name);

  greet_by_val(name);               // value moved here
  greet_by_val(name);               // calling a second time would fail
  // greet_by_val(name.clone());          // both need clone()
  // greet_by_val(name.clone());

  // greet_by_ref(&name)
}
