class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        skF.push(nestedList.begin());
        skL.push(nestedList.end());
    }

    int next() {
        nit iter = skF.top();
        int res = iter->getInteger();
        ++iter;
        skF.pop();
        skF.push(iter);
        return res;
    }

    bool hasNext() {
        int sz = skF.size();
        while (sz != 0)
        {
            if (skF.top() == skL.top())
            {
                skF.pop();
                skL.pop();
                sz--;
                if (sz > 0)
                {
                    nit iter = skF.top();
                    iter++;
                    skF.pop();
                    skF.push(iter);
                }
                else
                    break;
            }
            else
            {
                nit iter = skF.top();
                if (iter->isInteger())
                    return true;
                else
                {
                    auto& t = iter->getList();
                    if (t.size() == 0)
                    {
                        iter++;
                        skF.pop();
                        skF.push(iter);
                    }
                    else
                    {
                        skF.push(t.begin());
                        skL.push(t.end());
                        ++sz;
                    }
                }
            }
        }
        
        return false;
    }
    
    using nit = vector<NestedInteger>::iterator;
    stack<nit> skF, skL;
};