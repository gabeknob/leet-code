class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        stack<int> st;

        int cursor;
        st.push(0);

        while (st.size()) {
            cursor = st.top();
            st.pop();

            visited[cursor] = true;

            for (int i = 0; i < rooms[cursor].size(); i++) {
                if (!visited[rooms[cursor][i]])
                    st.push(rooms[cursor][i]);
            }
        }

        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == false) return false;
        }

        return true;
    }
};
