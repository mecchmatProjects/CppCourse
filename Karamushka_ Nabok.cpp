#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <climits>

using namespace std;

typedef struct DLine DLine;
struct DLine {
	double a, b, c;

  friend bool     operator> (DLine&,    DLine&);
  friend bool     operator< (DLine&,    DLine&);
  friend bool     operator==(DLine&,    DLine&);
  friend ostream& operator<<(ostream&,  DLine );

  DLine() : a(0.0), b(0.0), c(0.0) {
  }

  DLine(double a, double b, double c) : a(a), b(b), c(c) {
  }
};

const DLine dline_minv(0.0, 0.0, 0.0);

double abs(DLine& t) {
  return sqrt(t.a * t.a + t.b * t.b + t.c * t.c);
}

bool operator> (DLine& d1, DLine& d2) {
  return abs(d1) > abs(d2);
}

bool operator< (DLine& d1, DLine& d2) {
  return abs(d1) < abs(d2);
}

bool operator==(DLine& d1, DLine& d2) {
  return d1.a == d2.a && d1.b == d2.b && d1.c == d2.c;
}

ostream& operator<<(ostream& stream, DLine t) {
  stream << "DLine(a=" << t.a << ",b=" << t.b << ",c=" << t.c << ")";
  return stream;
}

template <typename data>
class DataStruct {
public:
  virtual bool append(data p)                     = 0;
  virtual data pop()                              = 0;
  virtual bool is_empty()                         = 0;
  virtual bool is_present(data p)                 = 0;
  virtual size_t find(data p)                     = 0;
  virtual bool remove(data p)                     = 0;
  virtual vector<data> find_all(data p1, data p2) = 0;
};

template <typename data, const data& minv>
class MinHeap : public DataStruct<data> {
private:
  data *arr;
  int capacity;
  int size;

  void min_heapify(int i) {
    int lt = 1 + 2 * i;
    int rt = 1 + 2 * i + 1;
    int sm = i;
    if (lt < size && arr[lt] < arr[sm]) {
      sm = lt;
    }
    if (rt < size && arr[rt] < arr[sm]) {
      sm = rt;
    }
    if (sm != i) {
      data t = arr[i];
      arr[i] = arr[sm];
      arr[sm] = t;
      min_heapify(sm);
    }
  }

public:
  MinHeap() {
    this->capacity = 16;
    this->arr = new data[capacity];
    this->size = 0;
  }

  MinHeap(vector<data> v) {
    this->capacity = v.size();
    this->arr = new data[capacity];
    this->size = 0;
    for (int i = 0; i < v.size(); i++) {
      append(v[i]);
    }
  }

  template <size_t SIZE>
  MinHeap(array<data, SIZE> v) {
    this->capacity = v.size();
    this->arr = new data[capacity];
    this->size = 0;
    for (int i = 0; i < v.size(); i++) {
      append(v[i]);
    }
  }

  MinHeap(data *v, size_t n) {
    this->capacity = n;
    this->arr = new data[capacity];
    this->size = 0;
    for (int i = 0; i < n; i++) {
      append(v[i]);
    }
  }

  MinHeap(size_t n) {
    this->capacity = n;
    this->arr = new data[capacity];
    this->size = 0;
  }

  bool append(data p) {
    if (size == capacity) {
      return false;
    }
    int i = size++;
    arr[i] = p;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
      data t = arr[i];
      arr[i] = arr[(i - 1) / 2];
      arr[(i - 1) / 2] = t;
      i = (i - 1) / 2;
    }
    return true;
  }

  data pop() {
    if (size == 0) {
      return minv;
    }
    data ret = arr[0];
    arr[0] = arr[--size];
    min_heapify(0);
    return ret;
  }

  bool is_empty() {
    return size == 0;
  }

  bool is_present(data p) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == p) {
        return true;
      }
    }
    return false;
  }

  size_t find(data p) {
    size_t ret = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i] == p) {
        ret += 1;
      }
    }
    return ret;
  }

  bool remove(data p) {
    int i = -1;
    for (int j = 0; j < size; j++) {
      if (arr[j] == p) {
        i = j;
        break;
      }
    }

    if (i == -1) {
      return false;
    }

    arr[i] = minv;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
      data t = arr[i];
      arr[i] = arr[(i - 1) / 2];
      arr[(i - 1) / 2] = t;
      i = (i - 1) / 2;
    }
    pop();

    return true;
  }

  vector<data> find_all(data p1, data p2) {
    vector<data> ret;
    for (int i = 0; i < size; i++) {
      if ((arr[i] > p1 && arr[i] < p2)
          || arr[i] == p1
          || arr[i] == p2) {
        ret.push_back(arr[i]);
      }
    }
    return ret;
  }
};

template <typename data, const data& minv>
class Tree : public DataStruct<data> {
private:
  data *arr;
  int capacity;
  int size;

public:
  Tree() {
    this->capacity = 16;
    this->arr = new data[capacity];
    this->size = 0;
  }

  Tree(vector<data> v) {
    this->capacity = v.size();
    this->arr = new data[capacity];
    this->size = 0;
    for (int i = 0; i < v.size(); i++) {
      append(v[i]);
    }
  }

  template <size_t SIZE>
  Tree(array<data, SIZE> v) {
    this->capacity = v.size();
    this->arr = new data[capacity];
    this->size = 0;
    for (int i = 0; i < v.size(); i++) {
      append(v[i]);
    }
  }

  Tree(data *v, size_t n) {
    this->capacity = n;
    this->arr = new data[capacity];
    this->size = 0;
    for (int i = 0; i < n; i++) {
      append(v[i]);
    }
  }

  Tree(size_t n) {
    this->capacity = n;
    this->arr = new data[capacity];
    this->size = 0;
  }

  bool append(data p) {
    if (size == capacity) {
      return false;
    }
    arr[size++] = p;
    return true;
  }

  data pop() {
    if (size == 0) {
      return minv;
    }
    return arr[--size];
  }

  bool is_empty() {
    return size == 0;
  }

  bool is_present(data p) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == p) {
        return true;
      }
    }
    return false;
  }

  size_t find(data p) {
    size_t ret = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i] == p) {
        ret += 1;
      }
    }
    return ret;
  }

  bool remove(data p) {
    int i = -1;
    for (int j = 0; j < size; j++) {
      if (arr[j] == p) {
        i = j;
        break;
      }
    }

    if (i == -1) {
      return false;
    }

    arr[i] = arr[--size];

    return true;
  }

  vector<data> find_all(data p1, data p2) {
    vector<data> ret;
    for (int i = 0; i < size; i++) {
      if ((arr[i] > p1 && arr[i] < p2)
          || arr[i] == p1
          || arr[i] == p2) {
        ret.push_back(arr[i]);
      }
    }
    return ret;
  }
};

int main() {
  cout << "hello world" << endl;

  vector<DLine> tmp = {
    DLine(8, 9, 6),
    DLine(2, 5, 3),
    DLine(7, 4, 5),
  };

  DataStruct<DLine> *heap = new MinHeap<DLine, dline_minv>(tmp);

  cout << endl;
  cout << "MinHeap:" << endl;
  while (!heap->is_empty()) {
    cout << heap->pop() << endl;
  }

  DataStruct<DLine> *tree = new Tree<DLine, dline_minv>(tmp);

  cout << endl;
  cout << "Tree:" << endl;
  while (!tree->is_empty()) {
    cout << tree->pop() << endl;
  }

  return 0;
}

