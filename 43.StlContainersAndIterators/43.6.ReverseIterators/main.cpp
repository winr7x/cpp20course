template <typename T>
std::list<T> union_func(const std::list<T>& l1,
                        const std::list<T>& l2){

    std::list<T> result;
    auto itl1 = l1.begin();
    auto itl2 = l2.begin();
    while( (itl1!=l1.end()) && (itl2!=l2.end())){

        if(*itl1 == *itl2){
            result.push_back(*itl1);
            ++itl1;
            ++itl2;
        }else if( *itl1 < *itl2){
            result.push_back(*itl1);
            ++itl1;
        }else{
            result.push_back(*itl2);
            ++itl2;
        }
    }

    //Handle remaining elements from bigger list
    while(itl1!=l1.end()){
        result.push_back(*itl1);
        ++itl1;
    }

    while(itl2!=l2.end()){
        result.push_back(*itl2);
        ++itl2;
    }

    return result;
}