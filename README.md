# bmg-photo-filter
Filter simply is a program that change the format of(filtering) bmg image (note: this program works only for 24-bit bmg image )

the reason why it is works only for 24-bit bmp image because photo is a file that is just a sequence of bits, arranged in some fashion.
A 24-bit BMP file, then, is essentially just a sequence of bits, (almost) every 24 of which happen to represent some pixel’s color.
But a BMP file also contains some “metadata,” information like an image’s height and width.
That metadata is stored at the beginning of the file in the form of two data structures generally referred to as “headers,”.
So by editing the header of these kind of image we can filter image in different mode.

In this program there are four modes for the filter which are Blur, Grayscale, Reflection and Sepia.

(Note: in images folder there are bmg images with appropriate version to try them ,and out.bmp is the image after the filter)
Here an example to  how run the program using terminal window : ./filter -g images/yard.bmp out.bmp
