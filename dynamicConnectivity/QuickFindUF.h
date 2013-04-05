using namespace std;

class QuickFindUF
{
    private:
        int *m_id;
        int m_size;

    public:
        QuickFindUF(int size)
        {
            m_size = size;
            m_id = new int[size];
            for (int i = 0; i < size; i++) m_id[i] = i;
        }

        bool Connected(int left, int right)
        {
            return m_id[left] == m_id[right];
        }

        void Union(int left, int right)
        {
            int qleft = m_id[left];
            int qright = m_id[right];

            for (int i = 0; i< m_size; i++)
            {
                if (m_id[i] == qleft) m_id[i] = qright; 
            }
        }
};
