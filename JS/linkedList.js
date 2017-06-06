function InvalidIndexException(index) {
  this.value = index;
   this.message = ' is an invalid index.';
   this.toString = function() {
      return String(this.value) + this.message;
   };
}

function Node(data){
  this.val = data;
  this.next = null;
}

function LinkedList(){
  this._length = 0;
  this.head = null;
}

LinkedList.prototype.displayAll = function () {
  var current = this.head;
  var result = ""
  while(current){
    result += current.val + " ";
    current = current.next;
  }
  return result;
};

LinkedList.prototype.addAtBeginning = function (value) {
    var temp = this.head;
    this.head = new Node(value)
    this.head.next = temp;
    this._length++;
};

LinkedList.prototype.add = function (value) {
  if(this.head == null){
    this.addAtBeginning(value);
  }
  else{
    var current = this.head;
    while(current.next){
      current = current.next;
    }
    current.next = new Node(value);
    this._length++;
  }
};
