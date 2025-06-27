class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string dir;
        stringstream ss(path);

        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") continue;
            if (dir == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(dir);
            }
        }

        string result = "";
        for (string s : stack) {
            result += "/" + s;
        }

        return result.empty() ? "/" : result;
    }
};
