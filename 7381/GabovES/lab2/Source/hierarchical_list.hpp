class H_List;

class Pair{
public:
  friend H_List;	
  Pair();
private:	
  H_List* down;
  H_List* right;
};

class H_List{
public:
  H_List();
  ~H_List();  
  void create_list(H_List*, std::string , int);
  int result_list(H_List*, std::map<char,int>&, int);
private:	
  bool is_atom;
  union{
    Pair pair;
    char data;
  };
};




