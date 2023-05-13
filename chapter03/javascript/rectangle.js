class Rectangle {
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
	getArea() {
		return this.height * this.width;
	}
}

const rect = new Rectangle(10,10);

console.log("the area is: ", rect.getArea());
