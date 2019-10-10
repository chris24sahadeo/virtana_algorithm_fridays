# question: https://techdevguide.withgoogle.com/paths/advanced/compress-decompression#code-challenge
from Decompressor import Decompressor
import sys, getopt

def main(argv):

  # command line args
  try:
    opts, args = getopt.getopt(argv, "i:")
  except getopt.GetoptError:
    print('args error')
    sys.exit(2)
  for opt, arg in opts:
    if opt == '-i':
      print('input file is {}'.format(arg))
      input_file_name = arg
    else:
      print('Loading default input file')
      input_file_name = 'input_1.txt'

  with open(input_file_name) as input_file:
    compressed_string = input_file.readline().strip()
    while(compressed_string):
      print(compressed_string)
      decompressor = Decompressor(compressed_string)
      print(decompressor.decompress_all())

      compressed_string = input_file.readline().strip()

if __name__ == '__main__':
  main(sys.argv[1:])