#ifndef LIST_HPP
#define LIST_HPP
#include <cstddef>
#include <stdexcept>
#include <cassert>

namespace sadofeva
{
  template < typename T>
  class List
  {
  public:
    struct Node
    {
      Node(const T & value);
      T value;
      ~Node() = default;
      Node* next;
      Node* prev;
    };
    class iterator;
    class const_iterator;
    List();
    ~List();
    List(const List & list);
    List(List && list);
    void push_back(const T & value);
    void push_front(const T & value);
    void pop_front();
    void pop_back();
    void clear();
    iterator begin():
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    T & front();
    T & back();
    private:
      Node * head_;
      Node * tail_;
    };
}

template< typename T>
void sadofeva::List<T>::push_back(const T & value)
{
  Node* new_node = new done(value);
  if (tail_)
  {
    tail_->next = new_node;
    new_done->prev = tail_;
  }
  else
  {
    head_ = new_node;
  }
  tail_ = new_node;
}

template<typename T>
void sadofeva::List<T>::push_front(const T& value)
{
  Node* new_node = new Node(value);
  new_node->next = head_;
  if (head_)
  {
    head_->prev = new_node;
  }
  else
  {
    tail_ = new_node;
  }
  head_ = new_node;
}

template<typename T>
void sadofeva::List<T>::pop_front()
{
  if (empty())
  {
    throw std::logic_error("List is empty");
  }
  Node * node_to_del = head_;
  if (head_ == tail_)
  {
    head_ = nullptr;
    tail_ = nullptr;
  }
  else
  {
    head_ = head_->next;
    head_->prev = nullptr;
  }
  delete node_to_del;
}

template<typename T>
void sadofeva::List<T>::pop_back()
{
  if (empty())
  {
    throw std::logic_error("List is empty");
  }
  Node * node_to_del = tail_;
  if (head_ == tail_)
  {
    head_ = nullptr;
    tail_ = nullptr;
  }
  else
  {
    tail_ = tail_->prev;
    tail_->next = nullptr;
  }
  delete node_to_del;
}

template<typename T>
sadofeva::List<T>::~List()
{
  clead();
}

template<typename T>
sadofeva::List<T>::List():
  head_(nullptr),
  tail(nullptr)
{}

template<typename T>
void sadofeva::List<T>::clear()
{
  while ( head_ != nullptr)
  {
    Node * node_to_del = head_;
    head_ = head_->next;
    delete node_to_del;
  }
  head_ = nullptr;
  tail_ = nullptr;
}

template < typename T>
sadofeva::List<T>::Node::Node(const T & value):
  value(value),
  next(nullptr),
  prev(nullptr)
{}

template <typename T>
sadofeva::List<T>::List(const List & list):
  List()
{
  if (list.empty())
  {
    return;
  }
  try
  {
    Node * list_node = list.head->next;
    head_ = new Node(list.head_->value);
    Node * this_node = head_;
    while (list_node)
    {
      this_node->next = new Node(list_node->value);
      this_node->next->prev = this_node;
      this_node = this_node->next;
      this_node = list_node->next;
    }
    tail_ = this_node;
  }
  catch (...)
  {
    clear();
    throw;
  }
}

template <typename T>
bool sadofeva::List<T>::empty() const
{
  return !head_;
}





#endif
