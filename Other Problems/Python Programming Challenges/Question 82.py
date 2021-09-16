import zlib
compressedString = zlib.compress(b'hello world!hello world!hello world!hello world!')
print(compressedString)
print(zlib.decompress(compressedString))