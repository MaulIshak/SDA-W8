// File: linked_list.c
// Author: Maulana Ishak
// Date: 06-04-2025
// Description: Implementation of linked list functions in C
// License: MIT License

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

// Initialize the linked list
void create_list(LinkedList* list){
  list->head = NULL;
}

// Create a new node with the given nm
Node* create_node(infotype nm){
  Node* new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL){
    printf("Overflow, Memory allocation failed\n");
    return NULL;
  }
  new_node->nm = strdup(nm);
  new_node->next = NULL;
  return new_node;
}

// Check if the list is empty
bool is_list_empty(LinkedList list){
  if(list.head == NULL){
    return true;
  }
  return false;
}

// Check if given nm exists in the list
bool is_exist(LinkedList list, infotype nm){
  Node* curr;

  curr = list.head;
  while(curr != NULL){
    if(curr->nm == nm){
      return true;
    }else{
      curr = curr->next;
    }
  }

  return false;
}
Node* find_node(LinkedList list, infotype nm){
  Node* curr;

  curr = list.head;
  while(curr != NULL){
    if(curr->nm == nm){
      return curr;
    }else{
      curr = curr->next;
    }
  }

  return NULL;
}
Node* find_prev_node(LinkedList list, Node* node){
  Node* curr;
  curr = list.head;

  if(curr == NULL || node == NULL){
    return NULL;
  }

  while(curr != NULL && curr->next != node){
    curr = curr->next;
  }

  return curr;
}
// Print the linked list in forward order
void print_list(LinkedList list){
  Node* curr;
  if(is_list_empty(list)){
    // printf("list empty\n");
  }else{
    curr = list.head;
    while(curr->next != NULL){
      printf("[%s]->", curr->nm);
      curr = curr->next;
    }
    printf("[%s]\n", curr->nm);
  }
}

void destroy_list(LinkedList* list){
  Node* curr;
  Node* temp;

  curr = list->head;
  while(curr != NULL){
    temp = curr;
    curr = curr->next;

    temp->next = NULL;
    free(temp);
  }
  list->head = NULL;
}

// Get the length of the linked list
int get_length(LinkedList list){
  Node* curr;
  int count;

  curr = list.head;
  count = 0;

  while(curr != NULL){
    count++;
    curr = curr->next;
  }

  return count;
  
}


void insert_first(LinkedList* list, infotype nm){
  Node* new_node;
  new_node = create_node(nm);
  if(new_node == NULL) return;

  if(is_list_empty(*list)){
    list->head = new_node;
  }else{
    new_node->next = list->head;
    list->head = new_node;
  }
}

void insert_last(LinkedList* list, infotype nm){
  Node  *new_node, *curr;
  new_node = create_node(nm);
  if(new_node == NULL) return;

  curr = list->head;
  if(curr == NULL){
    insert_first(list, nm);
  }else{
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = new_node;
  }
}

void insert_after(LinkedList* list, infotype prev_data, infotype nm){
  Node *new_node, *prev, *after;
  new_node = create_node(nm);
  if(new_node == NULL) return;

  prev = find_node(*list, prev_data);

  if(prev == NULL){
    printf("Node with nm %s not found\n", prev_data);
    return;
  }
  after = prev->next;
  prev->next = new_node;
  new_node->next = after;

}

void insert_at(LinkedList* list, int position, infotype nm){
  Node *new_node, *curr;
  new_node = create_node(nm);
  if(new_node == NULL) return;

  if(position < 1 || position > get_length(*list)){
    printf("Invalid position\n");
    return;
  }

  if(position == 1){
    insert_first(list, nm);
  }else{
    curr = list->head;
    for(int i = 1; i < position-1; i++){
      curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
  }
}

void insert_before(LinkedList* list, infotype next_data, infotype nm){
  Node *new_node, *prev, *next;
  new_node = create_node(nm);
  if(new_node == NULL) return;

  prev = find_prev_node(*list, find_node(*list, next_data));
  if(prev == NULL){
    printf("Node with nm %s not found\n", next_data);
    return;
  }
  next = prev->next;
  prev->next = new_node;
  new_node->next = next;
}

void delete_first(LinkedList* list, infotype* temp){
  Node* curr;
  if(is_list_empty(*list)){
    printf("List is empty\n");
    return;
  }else{
    curr = list->head;
    list->head = curr->next;
    curr->next = NULL;

    *temp = curr->nm;
    free(curr);
    curr = NULL;
  }
}
void delete_last(LinkedList* list, infotype* temp){
  Node *curr, *prev;
  if(is_list_empty(*list)){
    printf("List is empty\n");
    return;
  }else{
    curr = list->head;
    prev = NULL;
    while(curr->next != NULL){
      prev = curr;
      curr = curr->next;
    }
    *temp = curr->nm;
    if(prev == NULL){
      free(curr);
      list->head = NULL;
    }else{
      free(curr);
      prev->next = NULL;
    }
  }
}

// Delete the node after the given nm in the list
void delete_after(LinkedList* list, infotype prev_data, infotype* temp){
  Node *prev, *del;
  if(is_list_empty(*list)) return;

  prev = find_node(*list, prev_data);
  if(prev == NULL){
    printf("Node with nm %s not found\n", prev_data);
    return;
  }else{
    del = prev->next;
    if(del == NULL){
      printf("Node with nm %s is the last node\n", prev_data);
      return;
    }else{
      prev->next = del->next;
      del->next = NULL;
      *temp = del->nm;
      free(del);
    }
  }
}

void delete_before(LinkedList* list, infotype next_data, infotype* temp){
  Node *prev, *del;
  if(is_list_empty(*list)) return;

  prev = find_prev_node(*list, find_node(*list, next_data));
  if(prev == NULL){
    printf("Node with nm %s not found\n", next_data);
    return;
  }else{
    del = prev->next;
    if(del == NULL){
      printf("Node with nm %s is the first node\n", next_data);
      return;
    }else{
      prev->next = del->next;
      del->next = NULL;
      *temp = del->nm;
      free(del);
    }
  }
}

void delete_val(LinkedList* list, infotype nm, infotype* temp){
  Node *curr, *prev;
  if(is_list_empty(*list)){
    printf("List is empty\n");
    return;
  }else{
    curr = list->head;
    prev = NULL;
    while(curr != NULL && curr->nm != nm){
      prev = curr;
      curr = curr->next;
    }
    if(curr == NULL){
      printf("Node with nm %s not found\n", nm);
      return;
    }else{
      if(prev == NULL){
        list->head = curr->next;
      }else{
        prev->next = curr->next;
      }
      *temp = curr->nm;
      free(curr);
    }
  }
}

void delete_at(LinkedList* list, int position, infotype* temp){
  Node *curr, *prev;
  if(is_list_empty(*list)){
    printf("List is empty\n");
    return;
  }else{
    curr = list->head;
    prev = NULL;
    if(position < 1 || position > get_length(*list)){
      printf("Invalid position\n");
      return;
    }
    for(int i = 1; i < position; i++){
      prev = curr;
      curr = curr->next;
    }
    if(prev == NULL){
      list->head = curr->next;
    }else{
      prev->next = curr->next;
    }
    *temp = curr->nm;
    free(curr);
  }
}
void print_list_reverse(LinkedList list){
  Node* curr;
  if(is_list_empty(list)){
    printf("list empty\n");
  }else{
    curr = list.head;
    while(curr->next != NULL){
      curr = curr->next;
    }
    while(curr != NULL){
      printf("[%s]->", curr->nm);
      curr = find_prev_node(list, curr);
    }
    printf("NULL\n");
  }
}