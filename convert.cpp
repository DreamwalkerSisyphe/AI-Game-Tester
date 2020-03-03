struct s
{
  // Your POD data here
  string _text;
    Spell* _spell;
    bool _success;
    signed char _rating; //Don't need need more than a byte to store values -2 to 2
public:
    string getName();
    int getLevel();

protected:
    pair<string, string> _startSpell;
    pair<string, string> _curSpell;
    int _level;

private:
    void updateLevel();
    
// still need to talk on the string of bits ex. 01111111 

void write(const std::string& file_name, s& data)
{
  std::ofstream out(file_name.c_str());
  out.write(reinterpret_cast<char*>(&s), sizeof(s));
}

void read(const std::string& file_name, s& data)
{
  std::ifstream in(file_name.c_str());
  in.read(reinterpret_cast<char*>(&s), sizeof(s));
}

// Template function for reading PODs
template<typename T>
void write_pod(std::ofstream& out, T& t)
{
  out.write(reinterpret_cast<char*>(&t), sizeof(T));
}

template<typename T>
void read_pod(std::ifstream& in, T& t)
{
  in.read(reinterpret_cast<char*>(&t), sizeof(T));
}

// Read Into file for vector with template
template<typename T>
void read_pod_vector(std::ifstream& in, std::vector<T>& vect)
{
  long size;

  read_pod(in, size);
  vect.resize(size);

  for(int i = 0;i < size;++i)
  {
    T t;
    read_pod(in, t);
    vect.push_back(t);
  }
}

// Write into file for vector with template
template<typename T>
void write_pod_vector(std::ofstream& out, std::vector<T>& vect)
{
  write_pod<long>(out, vect.size());
  std::for_each(vect.begin(), vect.end(), std::bind1st(write_pod<T>, out));
}


int main()
{
  
  // great for writing, but posses a problem when reading; we don't know the size of the array. This is not always a problem - we can just read until we hit the end of the file. But if you need to allocate an array, or want to store several different structs in one file this will not work.
  std::vector<s> myStructs;
  std::ofstream out("test.dat");

  // Fill vector here
  write_pod<long>(out, myStructs.size());
  std::for_each(myStructs.begin(), myStructs.end(), std::bind1st(write_pod<s>, out));


  // read & write to file
  s myStruct;
  read("transcript.tran", myStruct);
  write("", myStruct);
  
  
  //read and write vector with template to file
  std::vector&lts> myStructs;
  std::ofstream out("test.dat");
  std::ifstream in("test.dat");

  // Fill vector here
  write_pod_vector(out, myStructs);
  out.close();
  read_pod_vector(in, myStructs);

};
