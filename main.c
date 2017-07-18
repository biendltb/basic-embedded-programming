
int main()
{
  unsigned int counter = 0;
  
  while (counter < 21)
  {
      ++counter;
      if ((counter & 1) != 0)
      {
        ++counter;
        /* if counter is odd */
      }
      else
      {
        /* if counter is even */
      }
  }
  
  return 0;
}
