<h1 align="center">
	📖 cub3D
</h1>

<p align="center">
	<b><i>Reproduction of an raycasting game</i></b><br>
</p>
## Description
This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
With the help of the numerous documents available on the internet, you will use
mathematics as a tool to create elegant and efficient algorithms.

## Bresenham's line algorith  
The Brezenham algorithm is an algorithm that determines which points of a two-dimensional raster need to be colored in order to get a close approximation of a straight line between two specified points.
![](https://github.com/markveligod/cub3D/raw/master/img/2.gif)  
  
The segment is drawn between two points — (x0, y0) and (x1, y1), where these pairs indicate a column and a row, respectively, whose numbers grow to the right and down. First, we will assume that our line goes to the right and down, and the horizontal distance (x1 - x0) exceeds the vertical distance (y1 - y0), that is, the slope of the line from the horizontal is less than 45°. Our goal is to determine for each column x between x0 and x1 which row y is closest to the line and draw a point (x, y).  
General formula for a line between two points:  
`y - y0 = ((y1 - y0) / (x1 - x0)) * (x - x0);`  
Since we know column x, row y is rounded to an integer of the following value:  
`y = ((y1 - y0) / (x1 - x0)) * (x - x0) + y;`  
However, it is not necessary to calculate the exact value of this expression. Suffice it to note that y decreases from y0 and for each step we add one to x and add the slope value to y (in our case, the slope value will be a negative number):  
`s = (y1 - y0) / (x1 - x0);`  
which can be calculated in advance. Moreover, at each step, we do one of two things: either keep the same y, or reduce it by 1.  
You can decide which of these two to choose by tracking the error value, which means the vertical distance between the current y value and the exact y value for the current x. Whenever we increase x, we increase the error value by the slope value s given above. If the error exceeds 1.0, the line gets closer to the next y, so we reduce y by 1.0 while reducing the error value by 1.0. in the implementation of the algorithm below, plot(x,y) draws a point, and abs returns the absolute value of the number:
  
```
function line(int x0, int x1, int y0, int y1)
     int deltax := abs(x1 - x0)
     int deltay := abs(y1 - y0)
     real error := 0
     real deltaerr := (deltay + 1) / (deltax + 1)
     int y := y0
     int diry := y1 - y0
     if diry > 0 
         diry = 1
     if diry < 0 
         diry = -1
     for x from x0 to x1
         plot(x,y)
         error := error + deltaerr
         if error >= 1.0
             y := y + diry
             error := error - 1.0
```
The problem with this approach is that computers work relatively slowly with real variables such as error and deltaerr. In addition, for floating-point calculations, due to restrictions related to the representation of real numbers, it is not possible to get exact values when dividing. This leads to the fact that in the process of computation the accumulation of errors and can lead to undesirable results. For these reasons, it is better to work only with integers. This can be done by multiplying all the real values used by (delta x + 1). Getting the following code:  
```
function line(int x0, int x1, int y0, int y1)
     int deltax := abs(x1 - x0)
     int deltay := abs(y1 - y0)
     int error := 0
     int deltaerr := (deltay + 1)
     int y := y0
     int diry := y1 - y0
     if diry > 0 
         diry = 1
     if diry < 0 
         diry = -1
     for x from x0 to x1
         plot(x,y)
         error := error + deltaerr
         if error >= (deltax + 1)
             y := y + diry
             error := error - (deltax + 1)
```
The need to add one to deltax and deltay is caused by the fact that the function must build a line from a point (x0, y0) to a point (x1, y1) inclusive! Now we can quickly draw right-down lines with a slope value less than 1. It remains to extend the algorithm to drawing in all directions. This is achieved by mirroring, that is, replacing the sign (step 1 is replaced by -1), exchanging variables x and y, and exchanging the coordinates of the beginning of the segment with the coordinates of the end.  
  
There is also Bresenham algorithm to draw circles. The construction method is similar to drawing a line. In this algorithm, the circle arc is constructed for the first quadrant, and the coordinates of the circle points for the remaining quadrants are obtained symmetrically. At each step of the algorithm, three pixels are considered, and the most appropriate one is selected by comparing the distances from the center to the selected pixel with the radius of the circle.
```
// R - radius, X1, Y1 - coordinates of the center
   int x := 0
   int y := R
   int delta := 1 - 2 * R
   int error := 0
   while (y >= 0)
       drawpixel(X1 + x, Y1 + y)
       drawpixel(X1 + x, Y1 - y)
       drawpixel(X1 - x, Y1 + y)
       drawpixel(X1 - x, Y1 - y)
       error = 2 * (delta + y) - 1
       if ((delta < 0) && (error <= 0))
           delta += 2 * ++x + 1
           continue
       if ((delta > 0) && (error > 0))
           delta -= 2 * --y + 1
           continue
       delta += 2 * (++x - --y)
```
![](https://github.com/markveligod/cub3D/raw/master/img/3.gif)  

## DDA algorithm
The DDA-line algorithm rasterizes the line segment between two specified points using calculations in floating-point numbers or integers.  
Let the segment be defined by the real coordinates of the ends (x1, y1), (x2, y2). The raster (integer) coordinates of the endpoints are rounded values of the source coordinates: x_start =round (X1), y_start = round(Y1), x_end = round(x2), and y_end = round(Y2).  

A larger absolute number, (x_end - x_start) or (y_end - y_start), increased by 1 L of the rasterization cycle.  

At the beginning of the cycle the auxiliary real variables x and g are assigned the initial coordinates of the beginning of the segment: x = x1, y = y1. at each step of the loop, these real variables get increments (x_end - x_start) / L, (y_end - y_start) / L. The raster coordinates produced at each step are the result of rounding the corresponding real values x and y.  

The use of calculations with real numbers and only a single use of rounding to finally obtain the value of the raster coordinate results in high accuracy and low performance of the algorithm.  

## Raycasting Part and Drawing calculations

Okay so for the raycasting part the main resources that I followed were the following:

To create a minimap and use trigonometrics for raycasting:
- [Pikuma Javascript Raycasting Introduction](https://courses.pikuma.com/courses/take/raycasting/lessons/7485598-introduction-and-learning-outcomes)
(Before the course was free)

To understand the calculations behind the projection itself:
- [Permadi's Raycasting Tutorial](https://www.permadi.com/tutorial/raycast/rayc1.html)

For a fun Youtube video implementing Raycasting in C:
- I watched [this video](https://www.youtube.com/watch?v=gYRrGTC7GtA)

- And I also peaked a lot on [Dimitri's](https://github.com/DimitriDaSilva) code, haha.


I will try to simplify it as much as possible:

Raycasting is basically taking your field of view, dividing it by your window width and calculating the distance from your face to the wall strip in each one of these divisions. (Explanations are clearer in Pikuma's Javascript tutorial).


### Drawing calculations

Let's picture this:
- Our window is 500 pixels width and 500 pixels height.
- We pick a [field of view](https://en.wikipedia.org/wiki/Field_of_view) of 60 degrees (usual in FPS games). The bigger your field of view the more you can see around you and the closest you get to a 360 picture. With a field of view of 60 you just see what's in front of you.
- Our height is 1,5meters.
- The wall's height is 3 meters.
- The wall is 6 meters away from us.

Okay, now I will help you calculate the size that the walls will have on the screen (a simplified version to be better understood).

In order to calculate them I will use the concept of triangle similarity and the [Projection Plane](https://www.permadi.com/tutorial/raycast/rayc9.html):

This concept is in my opinion the most important to grasp in order to draw not only the walls but also the sprites, floor and ceiling.
Using our screen and field of view we have 2 similar triangles.

> One triangle is between our face and the projection plane (the screen) and we can [calculate](https://www.permadi.com/tutorial/raycast/rayc5.html) this distance.
Half the screen size / tan(half our field of view)
(500/2) / tan(30 degrees) = 433.012701892
Our face is 433.012701892 pixels away from the screen. 

I know.. I know... pixels is not really a measurement of distance outside the screen, but it doesnt matter. What matters is this distance in pixels from our face to the projection plane/screen is proportional to the distance in meters from our face to the wall (6 meters).

> The other triangle is between our face and the wall (which we know is 6 meters away).

Okay now look at [this](https://www.permadi.com/tutorial/raycast/rayc9.html).

Projected wall height = wall actual height / distance to the wall * distance to projection plane

Projected wall height = (3 meters / 6 meters) * 433.012701892 = 216.506350946 ≈ 216 pixels.

GREAT!! We now know the height in pixels that our wall will have on our screen! Yay.

Now were do we place this line?

As we said in the beggining our player is 1,5 meters tall.
(1.5/3) * 500 = 250 we will draw (3-1.5)/3 = 0.5 = the middle of our wall. (Don't worry about these calculations. In the Wolfenstein game the player was half of the walls so the middle of the screen will always correspond with the middle of the wall/sprites.

So the wall line has to be centered on the screen.
The beggining of the wall strip will be on 250 - (216/2) = 142nd pixel
The end of the wall strip will be on the 250 + (216/2) = 358th pixel

We draw a line from the 142nd pixel to the 358th and booom. We have a wall strip.

Now we just have to repeat this process for each collumn/width pixel on our screen. To do this we use the raycasting principle.

### Raycasting

Okay for this part I really suggest following [Pikuma's Tutorial](https://courses.pikuma.com/courses/take/raycasting/lessons/7485598-introduction-and-learning-outcomes).

The main challenge was converting the Javascript code into C. Here are the main things to consider:
- Instead of classes for variables just create structs, create the same functions.
- Using double data type for calculations (If you use integer you will lose all decimal point information). Also, <math.h> functions take double as parameters.
- Converting double to int to change the values of the actual coordinates of the pixels (there is no 2.4123, 3.124124 coordinate).
- To avoid overflows do a simple protection like this:

```
if (x < 0)
	x = 0;
if (y < 0)
	y = 0;
if (x >= img_width)
	x = img_width - 1.0;
if (y >= img_width)
	x = img_width - 1.0;
```

This will grant that if when converting to integer if the values are not valid (below zero or above the maximum width) it will fix them and put the first and last value respectively, when needed. 

After you finish the tutorial you will understand how to use the player rotation in radians, you will have a cute minimap, and the distances for each one of the rays. You will then use these distances to draw lines the way I just described.

### Wall textures

Okay once we followed Pikuma's tutorial these are the things we still have left to do:

1. Draw the walls using the distances of the rays (don't forget to correct the [fisheye effect](https://permadi.com/1996/05/ray-casting-tutorial-8/)
2. Assign each texture to the correct wall.
3. Find out which part of the wall we are hitting so we know the correct part of the texture to assign to that wall strip.

To find the correct wall using the ray angle and the wall orientation (Horizontal or Vertical).

For example if the ray rotation angle is 0 radians (looking to the right) and we hit a vertical wall we know that the texture we will choose is the East side texture.

To find which part of the wall we are hitting I suggest looking at [Permadi's](https://www.permadi.com/tutorial/raycast/rayc10.html) explanation.

But summing up.
We define how wide we want the walls to be:

Following the previous example in which the walls were 3 meters, maybe we want the walls width to be 3 meters as well so that the three dimensional space is divided in squares/cubes and to make it easier to imagine.

Imagine this map:
```
Imagine this map:
  _
11111
10001
10001
10N01
11111
```
It is definitely easier to imagine if each represents a 3 meters square, right? What is great about Pikuma's tutorial is that we can use the tile_size to visualize this and just use the distance in pixels on the map as the way to do the raycasting.

So in this case our player would be:
In 2.5 * 3 = 7.5 x position ('1' & '0' full squares and half the 'N' square)
In 3.5 * 3 = 10.5 y position ('1' & '0' & '0' full squares and half the 'N' square)

Okay, hopefully this makes sense because with this scale we can now calculate the corresponding texture strip.

Imagine our ray hits a wall in the (7.5, 3) position (in the middle of third wall (I put an underscore above it to show which wall I'm talking about)).

We can do a while loop

```
while (x >= 3)
	x-=3
```
We will end up with 1.5. This represent half the square size on our map.

To find the corresponding slice on the texture we can calculate this through:
1.5/3 * texture_width.

If a texture is 64 pixels. the wall strip's texture will be drawn with the 32nd texture strip (x = 32).


### Sprites

The major difficulties about sprites were:

1. Reorganizing sprites drawing order based on distance (Sprites thar are further away must be drawn first).
2. Comparing each wall ray distance with the sprite distance to check if the sprite is closer or further away compared to the wall ray distance (if there is a wall strip closer to the player than the sprite we draw the wall. If the sprite distance is closer than the wall ray distance we draw the sprite.

We can calculate the height, width, the position on the screen and the corresponding texture strip of the sprite based on the principles we talked about for the walls.

### Floor

For the floor we find the bottom of the wall lines we drew before and we draw a line imediatly below it.
The only challenge is to find which part of the texture we need to draw for each texture. We must find the x and y positions on the map (as seen from above)and find the corresponding texture coordinates. I followed [these](https://www.permadi.com/tutorial/raycast/rayc12.html) calculations and saw [this Stackoverflow post](https://gamedev.stackexchange.com/questions/159285/ray-casting-floor-casting-part-fails).

## Creeper Textures

In order to create my creeper sprites I first found images online of creepers, I tried to add a black background around the creeper and I finally[converted](https://convertio.co/png-xpm/) it to xpm. After that most images were not perfect so I had to use vim and manually substitute the pixel colors on the xpm file.

It's really intuitive. Usually spaces represent the black color so, to make a particular pixel black we can simply replace the letter that represents a different color with a space. If you look at one of my [xpm pictures](textures/creeper.xpm) you can see what I mean. Before there were random letters around the creeper. I just replace them with spaces.

## Animation

For the animation I just created 2 variables:
- Start_animation
- Animation_counter

If I click on the space bar it changes the start_animation variable to one. If that value is 1 I replace the normal_torch texture with the attack_torch texture and leave it on the screen while the animation_counter doesnt reach a random number (I chose 5 but it will depend on how fast the game is running).

<h3>Resource</h3>
<a href="https://github.com/vinibiavatti1/RayCastingTutorial/wiki">RayCastingTutorial</a><br>
<a href="https://beautiful-wrench-c54.notion.site/Cub3D-aec946d545134fcf83b8d1bd98e0c605">Cub3D</a>
<h3>Testers</h3>
<a href="https://github.com/romslf/cub3d-tester">Tester 1</a><br>
<a href="https://github.com/humblEgo/cub3D_map_tester">Tester 2</a><br>
 
