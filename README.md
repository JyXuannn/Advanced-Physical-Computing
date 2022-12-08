**Weekly diary:**

**Week 6:**

Based on the concept of week 5, I decided to design a scale, then I drew a sketch. Actually, the first sketch for the appearance looked like a box which did not have any connections with my concept, so I decided to change the appearance. On the process, then I get another one. (see the right picture)

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BD%83%EF%BD%8F%EF%BD%8E%EF%BD%83%EF%BD%85%EF%BD%90%EF%BD%94.jpg "Cow1")
![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BD%81%EF%BD%90%EF%BD%90%EF%BD%85%EF%BD%81%EF%BD%92%EF%BD%81%EF%BD%8E%EF%BD%83%EF%BD%85.jpg "Cow1")

Additionally, I tried to connect the circuit and research how to use some of different sensors. I decided to use Tinkercad to connect them because it can make sure whether it had some problems on the coding. First of all, I tried to link each sensor individually (two servos, two pressures, a distance and a LCD screen). 

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/servo.jpg "Cow1")

Then I wrote the status machine which is when the audiences close the installation, distance sensor can check, light will high, servo will go to 30 degrees and LCD will show some words. And then, the audiences can take something on the left and right tray, the pressure will sense and servo will go to 180 degrees. The next step is that audiences take two different things on the both trays, The first tray to 180 degrees will go to 0 degrees and the other tray will go to 180, then delay a moment, they will swap and loop. On the process, the LCD will change different content.

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%E7%8A%B6%E6%80%81%E6%9C%BA.jpg "Cow1")

To make sure the status machine, I started to combine these sensors. On the first step, I combined the LCD, light and distance because I thought they were easier then the pressure and servo. Then I combined the coding and connect the circuit and add a if in it. Then I tried to combined the pressure and servo, and add 4 ‘if’ in coding. At last, I combined them together but I have no idea how can I combine the so many ‘if’.

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/servo%20and%20pressure.png "Cow1")
![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%E5%85%A8%E9%83%A8.jpg "Cow1")

After trying many time and numerous errors, I decided to use the distance sensor as the the first if, and then wrote the other ‘if’ in the else.

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BD%83%EF%BD%8F%EF%BD%84%EF%BD%89%EF%BD%8E%EF%BD%87%EF%BC%8D%EF%BC%91.png "Cow1")

**Week 7:**

When I make sure the coding did not has any problems. I decided to make a 3D model because I want to use 3D print to print the it. I thought there are some of complicated structures on the modal, so 3D print was a better choice I believed. Actually, it is not an easy thing though it just combined by some of different geometries. I needed to consider how can I make a right route to put the wires in, how big do I want to do and how thick do I want to do? 

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BC%B2%EF%BD%88%EF%BD%89%EF%BD%8E%EF%BD%8F%EF%BC%8D%EF%BC%91.png "Cow1")
![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BC%B2%EF%BD%88%EF%BD%89%EF%BD%8E%EF%BD%8F%EF%BC%8D%EF%BC%92.png "Cow1")

After building the model, I booked the 3D print and decided to do a prototype for making sure the installation can be run in practice.

I chose card paper as the material to make the prototype because It has a little bit hard I guessed it can bear the weight.

Before making the prototype, I needed to link the circuit on Arduino and breadboard, but when I connected the circuit and copy the coding from Tinkercad to Arduino, everything can run except the servo. The both servos rotated all the time when I connected the circuit, it cannot be controlled by pressure, so I add the coding for checking the value of pressure at first. After testing the pressure, I can make sure it does not has some problems on them, then I checked the coding but it looked fine. I have tried to debug for a few days. However, I cannot solve it and the bug is when I When I plug it in, the two servos keeps turning and the value of pressure constantly changing though I did not touch the pressure, so I felt so confused and booked a tutorial on week 8.

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BD%90%EF%BD%92%EF%BD%8F%EF%BD%94%EF%BD%8F%EF%BD%99%EF%BD%90%EF%BD%85.jpg
 "Cow1")
 
![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/B%EF%BD%92%EF%BD%85%EF%BD%81%EF%BD%84%EF%BD%82%EF%BD%8F%EF%BD%81%EF%BD%92%EF%BD%84.jpg
 "Cow1")

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BD%82%EF%BD%92%EF%BD%85%EF%BD%81%EF%BD%84%EF%BD%82%EF%BD%8F%EF%BD%92%EF%BD%81%EF%BD%84%EF%BC%8D%EF%BC%92.jpg
 "Cow1")

**Week 8:**

I went to the tutorial and got the answer for the bug which is the power is high, and Matt gave me a new power supply to connect the servo, then the installation can run. After that, I went to workshop and queued for hours to print the model. Since my installation has some of structure, I was going to print these parts separately, but there are too many parts on it, I planed to print it twice because the tray of 3D printer cannot fit them.

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BD%90%EF%BD%8F%EF%BD%97%EF%BD%85%EF%BD%92.jpg
 "Cow1")

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/3D%EF%BC%8D%EF%BC%91.jpg
 "Cow1")

![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/3D%EF%BC%8D%EF%BC%92.jpg
 "Cow1")
 
 ![Cow1](https://github.com/JyXuannn/Advanced-Physical-Computing/blob/main/%EF%BC%93%EF%BC%A4%EF%BC%8Dto%20assemble.jpg
 "Cow1")








