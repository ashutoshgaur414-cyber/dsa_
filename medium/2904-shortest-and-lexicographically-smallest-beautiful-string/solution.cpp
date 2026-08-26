                if (ans == "")
                {
                    ans = current;
                }
                // Shorter answer
                else if (current.size() < ans.size())
                {
                    ans = current;
                }
                // Same length -> lexicographically smaller
                else if (current.size() == ans.size() && current < ans)
                {
                    ans = current;
                }
            }
        }

        return ans;
    }
};
