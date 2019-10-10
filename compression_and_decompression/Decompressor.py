class Decompressor:

  def __init__(self, compressed_string):
    self.compressed_string = compressed_string
    self.current_index = 0

  def get_number(self):
    starting_index = self.current_index
    while self.compressed_string[self.current_index].isdigit():
      self.current_index+=1
    return int(self.compressed_string[starting_index:self.current_index])
  
  def get_inner_string(self):
    starting_index = self.current_index
    while self.compressed_string[self.current_index].isalpha():
      self.current_index+=1
    return self.compressed_string[starting_index:self.current_index]
  
  def decompress(self):
    # if end of final string then return empty string
    if self.current_index >= len(self.compressed_string):
      return ''

    # if ']' then return empty string
    if self.compressed_string[self.current_index] == ']':
      self.current_index += 1
      return ''
    
    # if digit then get number and advance to next nested string, check for trailing string and skipping the '['
    if self.compressed_string[self.current_index].isdigit():
      number = self.get_number() 
      self.current_index+=1
      return number*self.decompress()+self.decompress()
    
    # if character then return inner string and advance skipping the ']'
    if self.compressed_string[self.current_index].isalpha():
      inner_string = self.get_inner_string()
      self.current_index+=1      
      return inner_string

  def decompress_all(self):
    # ensures non recursive pieces are solved too 

    final_string = ''

    # for i in range(len(self.compressed_string)):
    #   i, inner_string = self.decompress(i)
    #   final_string += inner_string

    while self.current_index < len(self.compressed_string):
      final_string += self.decompress()
    
    return final_string