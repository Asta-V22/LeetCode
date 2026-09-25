class Solution {
    int i = 0;

    // Multiplies two sets of strings: Cartesian product (A x B)
    std::set<std::string> multiply(const std::set<std::string>& A, const std::set<std::string>& B) {
        std::set<std::string> res;
        for (const std::string& a : A) {
            for (const std::string& b : B) {
                res.insert(a + b);
            }
        }
        return res;
    }

    // Factor := Letter+ | '{' Expression '}'
    std::set<std::string> parseFactor(const std::string& s) {
        if (s[i] == '{') {
            i++; // skip '{'
            std::set<std::string> res = parseExpression(s);
            i++; // skip '}'
            return res;
        } else {
            std::string word = "";
            while (i < s.size() && s[i] >= 'a' && s[i] <= 'z') {
                word += s[i++];
            }
            return {word};
        }
    }

    // Item := Factor+ (Concatenation / Product)
    std::set<std::string> parseItem(const std::string& s) {
        std::set<std::string> res = {""}; // Multiplicative identity
        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            std::set<std::string> factor = parseFactor(s);
            res = multiply(res, factor);
        }
        return res;
    }

    // Expression := Item (',' Item)* (Union / Addition)
    std::set<std::string> parseExpression(const std::string& s) {
        std::set<std::string> res;
        while (true) {
            std::set<std::string> item = parseItem(s);
            res.insert(item.begin(), item.end()); // Union
            
            if (i < s.size() && s[i] == ',') {
                i++; // skip ','
            } else {
                break;
            }
        }
        return res;
    }

public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        i = 0;
        std::set<std::string> resultSet = parseExpression(expression);
        return std::vector<std::string>(resultSet.begin(), resultSet.end());
    }
};