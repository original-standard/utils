bool Dequal(double a,double b) 
{
	double tol = 1e-8;
	if((a - b) * (a-b) < tol * tol)
		return true;
	return false;
}
template <typename T,int N>
class fold{
public:
  T val[N];
  int n;
  fold() {n = N;};
  fold(const fold<T,N> &obj)
  {
    //	val = new T[N];
	n = N;
	for(int i = 0;i < N;i++)
		val[i] = obj.val[i];
  };

  fold<T,N>& operator =(fold<T,N>& obj)
  {
	n = N;
	for(int i = 0;i < N;i++)
	  val[i] = obj.val[i];
	return this;
  };
  bool operator ==(fold<T,N> obj) const
  {
    for(int i = 0;i < N;i++){
if(!Dequal(obj.val[i],val[i]))
	return false;
}	
    return true;
  };
    bool operator >(fold<T,N> obj) const
  {

    for(int i = 0;i < N;i++)
      if(Dequal(obj.val[i],val[i]))
	continue;
      else if(obj.val[i] < val[i])
	return true;
      else
	return false;
    return false;
  };
      bool operator <(fold<T,N> obj) const
  {
    for(int i = 0;i < N;i++)
     if(Dequal(obj.val[i],val[i]))
        continue;
      else if(obj.val[i] > val[i])
	return true;
      else
	return false;
    return false;
  };
};

