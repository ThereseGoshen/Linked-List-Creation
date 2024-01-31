//  <TODO Filename>
//      <TODO: Describe the data structure here >
//
//  Author: <TODO: Therese Goshen e>
//  CU ID: <TODO: place your CU ID here (thgo8749)>
//  GitHub Username: <TODO: ThereseGoshen>
//  Hours to complete lab: <TODO: place the number of hours needed to complete
//  lab, do not count time reading or watching videos>
//

#include "LinkedList.h"

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList() {
  top_ptr_ = NULL; //nullptr
  // Your code here
  
}

// deconstructor,
LinkedList::~LinkedList() {}

node* LinkedList::init_node(int data) {
  node* ret(new node);
  ret->data = data;
  ret->next = NULL; 
  // Your code here
  return ret;
}

string LinkedList::report() {
  string ret = "";
  if (this->top_ptr_ != nullptr) {
    ret = ret + to_string(this->top_ptr_->data) + " ";
    node* curr_node = top_ptr_->next;
    while (curr_node != nullptr) {
      ret = ret + to_string(curr_node->data) + " ";
      curr_node = curr_node->next;
    }
  }
  // Your code here
  return ret;
}

void LinkedList::append_data(int data) {
  auto new_node = init_node(data);
  append(new_node);
}

void LinkedList::append(node* new_node) {
  node* cursor = top_ptr_;
  if (cursor == NULL){
    top_ptr_ = new_node;
    return;
  }
  while (cursor->next != NULL){
    cursor = cursor->next;
  }
  cursor->next = new_node;
}

void LinkedList::insert_data(int offset, int data) {
  // Your code here
  node* curr_node = this->top_ptr_;
  int temp_val = curr_node->data;
  int i = 0;
  while (true) 
  {
    if (i == offset) {
      temp_val = curr_node->data;
      curr_node->data = data;
    } else if (i > offset) {
      int placeholder = curr_node->data;
      curr_node->data = temp_val;
      temp_val = placeholder;
    }

    if (curr_node->next == nullptr) {
      if (i < offset) {
        append_data(data);
        return;
      }
      append_data(temp_val);
      return;
    }
    curr_node = curr_node->next;
    i++;
  }
}

void LinkedList::insert(int offset, node* new_node) {
  // Your code here
  node* curr_node = this->top_ptr_;
  int temp_node_val = curr_node->data;
  int i = 0;

  while(true) {
    if (i == offset) {
      temp_node_val = curr_node->data;
      curr_node->data = new_node->data;
    } else if (i > offset) {
      int placeholder = curr_node->data;
      curr_node->data = temp_node_val;
      temp_node_val = placeholder;
    }

    if (curr_node->next == nullptr) {
      if (i < offset) {
        append(new_node);
        return;
      }
      append_data(temp_node_val);
      return;
    }

    i++;
    curr_node = curr_node->next;
  }

}

void LinkedList::remove(int offset) {
  // Your code here
  node* curr_node = this->top_ptr_;
  int temp_val = curr_node->data;
  int i = 0;
  while (true) {
    if (i >= offset) {
      if (curr_node->next == nullptr) {
        curr_node->data = NULL;
        return;
      }
      curr_node->data = curr_node->next->data;
    }
    curr_node = curr_node->next;
    i++;
  }
}

int LinkedList::size() {
  int ret = 0;
  // Your code here
  node* curr_node = this->top_ptr_;
  while(true) {
    ret++;
    if(curr_node->next == nullptr) {
      return ret;
    }
    curr_node = curr_node->next;
  }
  return ret;
}

bool LinkedList::contains(int data) {
  // Your code here
  node* curr_node = this->top_ptr_;
  while(true) {
    if(curr_node->data == data) {
      return true;
    }
    curr_node = curr_node->next;
  }
  return false;
}

// This function is implemented for you
// It returns the top pointer
node* LinkedList::get_top() { return top_ptr_; }

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::set_top(node* top_ptr) { top_ptr_ = top_ptr; }
