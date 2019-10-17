
#include<iostream>
#include<algorithm>
#include<map>


namespace std{

template <typename T>
std::vector<T> operator+(const std::vector<T>& a,const std::vector<T>& b)
{
  std::vector<T> temp;
  if(a.size() == 0)
    return b;
  if(b.size() == 0)
    return a;

  if(a.size() != b.size()){
    std::cout << "Error!!" << std::endl;
  }
  temp.resize(a.size());
  transform(a.begin(),a.end(),b.begin(),temp.begin(),std::plus<T>());

  return temp;
}

  template <typename T,typename U>
  std::map<T,U> operator+(const std::map<T,U>& a,const std::map<T,U>& b)
{
  std::map<T,U> temp;

  for(auto itr = b.begin();itr != b.end();itr++)
    temp[itr->first] = itr->second;

  for(auto itr = a.begin();itr != a.end();itr++)
    temp[itr->first] = temp[itr->first] + itr->second;
  
  return temp;
}

  template <typename T,typename U>
  std::map<T,U> operator*(const std::map<T,U>& a,const std::map<T,U>& b)
{
  std::map<T,U> temp;

  for(auto itr = b.begin();itr != b.end();itr++)
    temp[itr->first] = itr->second;

  for(auto itr = a.begin();itr != a.end();itr++)
    temp[itr->first] = temp[itr->first] * itr->second;
  
  return temp;
}

template <typename T>
std::vector<T> operator-(const std::vector<T>& a,const std::vector<T>& b)
{
  std::vector<T> temp;
  if(a.size() == 0){
    return -b;
  }
  if(b.size() == 0)
    return a;

  if(a.size() != b.size()){
    std::cout << "-Error!!" << std::endl;
  }
  temp.resize(a.size());
  transform(a.begin(),a.end(),b.begin(),temp.begin(),std::minus<T>());

  return temp;
}

template <typename T>
std::vector<T> operator-(const std::vector<T>& a)
{
  std::vector<T> temp;

  temp.resize(a.size());
  transform(a.begin(),a.end(),temp.begin(),([](T c) -> T {return -c;}));

  return temp;
}




template <typename T>
std::vector<T> operator*(const std::vector<T>& a,const std::vector<T>& b)
{
  std::vector<T> temp;
  if(a.size() == 0)
    return b;
  if(b.size() == 0)
    return a;

  if(a.size() != b.size()){
    std::cout << "*Error!!" << std::endl;
  }

  temp.resize(a.size());
  transform(a.begin(),a.end(),b.begin(),temp.begin(),std::multiplies<T>());

  return temp;
}

template <typename T>
std::vector<T> operator/(const std::vector<T>& a,const std::vector<T>& b)
{
  std::vector<T> temp;
  if(a.size() == 0)
    return b;
  if(b.size() == 0)
    return a;

  if(a.size() != b.size()){
    std::cout << "/Error!!" << std::endl;
  }

  temp.resize(a.size());
  transform(a.begin(),a.end(),b.begin(),temp.begin(),std::divides<T>());

  return temp;
}

}
