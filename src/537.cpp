string complexNumberMultiply(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        if (len1 == 0 || len2 == 0)
            return "";
        
        size_t pos = 0;
        int real1 = stoi(a, &pos);
        int img1 = stoi(a.substr(pos + 1));
        
        int real2 = stoi(b, &pos);
        int img2 = stoi(b.substr(pos + 1));
        int real = real1*real2 - img1*img2;
        int img = real1*img2 + real2*img1;
        
        return to_string(real) + "+" + to_string(img) + "i";
        
    }