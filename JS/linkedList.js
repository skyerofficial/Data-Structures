//Method to check invalid index

function InvalidIndexException(index) {
  this.value = index;
   this.message = ' is an invalid index.';
   this.toString = function() {
      return String(this.value) + this.message;
   };
}

//Method to create a node

function Node(data){
  this.val = data;
  this.next = null;
}

//Method to initialize head pointer and length of Linked List

function LinkedList(){
  this._length = 0;
  this.head = null;
}

//Method to display all nodes of Linked List

LinkedList.prototype.displayAll = function () {
  var current = this.head;
  var result = ""
  while(current){
    result += current.val + " ";
    current = current.next;
  }
  return result;
};

//Method to add a node at the beginning

LinkedList.prototype.addAtBeginning = function (value) {
    var temp = this.head;
    this.head = new Node(value)
    this.head.next = temp;
    this._length++;
};

//Method to add a node at beginning if list was empty else at the end

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

//Method to add node at particular index

LinkedList.prototype.addAt = function (value,index) {
    if(index == 1){
      this.addAtBeginning(value);
    }
    else if ((index > 1)&&(index <= this._length + 1)){
      var current = this.head;
      var toMove = index-2;
      while(toMove--){
        current = current.next;
      }
      var temp = new Node(value);
      temp.next = current.next;
      current.next = temp;
      this._length ++;
    }
    else{
      throw new InvalidIndexException(index).toString();
    }
};

//Method to remove node from particular index

LinkedList.prototype.removeNode = function(index) {
    var currNode = this.head, count = 0, sav;
    // if empty list then return none
    if(this._length === 0) return;

    // if first Node
    if(index === 1){
        this.head = currNode.next;
        this._length--;
    } else {
        while(count < index) {
            sav = currNode;
            currNode = currNode.next;
            count++;
        }
        sav.next = currNode.next;
        this._length--;

        return this.head;
    }
};
