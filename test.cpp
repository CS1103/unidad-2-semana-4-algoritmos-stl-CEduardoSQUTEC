#include <algorithm>
#include <iostream>
#include <vector>

static bool sort_using_greater_than(double u, double v)
{
   return u > v;
}

int
main()
{
   std::vector<double> v;

   v.push_back(0.3);
   v.push_back(0.1);
   v.push_back(1.2);
   v.push_back(0.01);

   std::sort(v.begin(), v.end(), sort_using_greater_than);

   for(std::vector<double>::size_type index = 0; index < v.size(); ++index)
      std::cout << v[index] << std::endl;
}
