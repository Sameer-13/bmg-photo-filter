# bmg-photo-filter
Filter simplly is a program that can put some effect on bmg image (this program works only for bmg image with version less than 4)

the reason why it is works only for bmp image because photo is a file is just a sequence of bits, arranged in some fashion.
A 24-bit BMP file, then, is essentially just a sequence of bits, (almost) every 24 of which happen to represent some pixel’s color.
But a BMP file also contains some “metadata,” information like an image’s height and width.
That metadata is stored at the beginning of the file in the form of two data structures generally referred to as “headers,”.
So by editing the header of these kind of image we can filter image in different mode.

In this program there are four mode for the filter which are Blur, Grayscale, Reflection and Sepia.
