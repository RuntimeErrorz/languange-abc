#pragma once

//模板，同样不敢分开

template<typename iterator, typename filter> iterator find(iterator first, iterator last, filter fn)
{
    for(iterator i = first; i != last; i++)
        if(fn(*i))
            return i;
    return last;
}

template<typename iterator, typename filter> int statistics(iterator first, iterator last, filter fn)
{
    int cnt = 0;
    for(iterator i = first; i != last; i++)
        if(fn(*i))
            cnt++;
    return cnt;
}