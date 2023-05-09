
/*
  Borrow checker

  2 Rules:
  - data has one owner
  - data may have multiple readers or on writer

  let name = "tris"
  let cap_name = capitalize(name)

  "Do not communicate by sharing memroy; isntead, share memory by communicating" - Effective go
  => Go won't stop you to share memory !
  => Rusts Ownership would use this recomendation as a compiler checked rule !

  "In rust, you tell the compiler how the world works,
  and it will hold you and everyone who contributes to your code accountable
  to the contracts you have written"
 */


fn capitalize(s: String) -> String {
// ----------    ^^^^^^ this parameter takes ownership of the value
// |
// in this function    rustc --explain E0382
  return s.to_uppercase();
}

fn main () {
  println!("borrow checker");

  let name = "tris".to_string();

  println!("{}\n", capitalize(name)); // ok
  // println!("{}\n", name);          // error ! name is gone now
}
