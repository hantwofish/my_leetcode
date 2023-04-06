#### MAP

https://blog.csdn.net/wsp_1138886114/article/details/106794899

```c++
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;
    //向 umap 容器添加新键值对
    umap.emplace("Python教程", "http://c.biancheng.net/python/");
    umap.emplace("Java教程", "http://c.biancheng.net/java/");
    umap.emplace("Linux教程", "http://c.biancheng.net/linux/");

    //输出 umap 存储键值对的数量
    cout << "umap size = " << umap.size() << endl;
    //使用迭代器输出 umap 容器存储的所有键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
```

##### 按照key进行排序
```c++
按照key进行排序
struct CmpByKeyLength {
  bool operator()(const string& k1, const string& k2) {
    return k1.length() < k2.length();
  }
};

int main() {
  map<string, int, CmpByKeyLength> name_score_map;
  name_score_map["LiMin"] = 90; 
  name_score_map["ZiLinMi"] = 79; 
  name_score_map["BoB"] = 92; 
  name_score_map.insert(make_pair("Bing",99));
  name_score_map.insert(make_pair("Albert",86));
  for (map<string, int>::iterator iter = name_score_map.begin();
       iter != name_score_map.end();
       ++iter) {
    cout << *iter << endl;
  }
  return 0;
}
```

##### 按照value进行排序

```
int main() {
  map<string, int> name_score_map;
  name_score_map["LiMin"] = 90;
  name_score_map["ZiLinMi"] = 79;
  name_score_map["BoB"] = 92;
  name_score_map.insert(make_pair("Bing",99));
  name_score_map.insert(make_pair("Albert",86));
 //把map中元素转存到vector中 
  vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());
  sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());
 // sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
  for (int i = 0; i != name_score_vec.size(); ++i) {
    cout << name_score_vec[i] << endl;
  }
  return 0;
}
```


#### algo
```
第一反应是利用stl中提供的sort算法实现，这个想法是好的，不幸的是，sort算法有个限制，利用sort算法只能对序列容器进行排序，就是线性的（如vector，list，deque）。map也是一个集合容器，它里面存储的元素是pair，但是它不是线性存储的（前面提过，像红黑树），所以利用sort不能直接和map结合进行排序。
```