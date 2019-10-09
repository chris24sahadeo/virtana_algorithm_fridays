# question: https://techdevguide.withgoogle.com/paths/advanced/compress-decompression#code-challenge
from Decompressor import Decompressor

def main():
  input_file_name = 'input_1.txt'
  with open(input_file_name) as input_file:
    compressed_string = input_file.readline().strip()
    while(compressed_string):
      print(compressed_string)
      decompressor = Decompressor(compressed_string)
      decompressor.decompress(0)

      compressed_string = input_file.readline().strip()

if __name__ == '__main__':
  main()