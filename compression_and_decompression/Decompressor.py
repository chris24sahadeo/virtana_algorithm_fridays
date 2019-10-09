class Decompressor:

  def __init__(self, compressed_string):
    self.compressed_string = compressed_string

  def get_number(self, i):
    j = i
    while self.compressed_string[j].isdigit():
      j+=1
    return j+1, int(self.compressed_string[i:j-1])
  
  def get_inner_string(self, i):
    j = i
    while self.compressed_string[j].isalpha():
      j+=i
    return j+1, self.compressed_string[i:j-1]
  
  def decompress(self, i):
    # if end of final string
    if i == len(self.compressed_string)-1:
      return ''

    # if ']'
    if self.compressed_string[i] == ']':
      self.decompress(i+1)
    
    # if digit then get number and advance to next section skipping the '['
    if self.compressed_string[i].isdigit():
      i, number = self.get_number(i)
      return i, number*self.decompress(i)
    
    # if character then return inner string and advance skipping the ']'
    if self.compressed_string[i].isalpha():
      i, inner_string = self.get_inner_string(i)
      return inner_string

  def decompress_all(self):
    final_string = ''
    for i in range(len(self.compressed_string)):
      i, inner_string = self.decompress(i)
      final_string += inner_string
    return final_string