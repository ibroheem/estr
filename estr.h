#ifndef estr_h
#define estr_h

namespace utils
{
   template <unsigned int CAPACITY, class T = char>
   class estr
   {
      public:
         T* begin() { return &m_data[0]; }
         T* cbegin() const { return begin(); }

         T* end() { return &m_data[length()]; }
         T* cend() const  { return end(); }

         /** Note: Erasure is typically over writing with '\0' */
         void erase(T* str, unsigned int index);

         size_t capacity() const { return CAPACITY; }
         size_t length() const;
         size_t size() const;

         template <class CT>
         int index_of(CT);

         bool operator<(const estr&);
         bool operator==(const estr&);
         bool operator!=(const estr&);

      private:
         T m_data[CAPACITY];
   };

   void usage()
   {
      estr<20> str;
   }
}

#endif//estr_h
