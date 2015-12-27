# Streaming UDP Video

This is a simple video streaming application. The sender captures video frames from a webcam using OpenCV, and sends the frames to the receiver over UDP. The frames are compressed in JPEG format and optionally downsampled to reduce the data payload. The receiver decodes the JPEG data and displays the video frame in a GUI window (also using OpenCV).

Requires OpenCV 2. Works on OS X and Linux.

TODO
------

<ul>
  <li> Test the build on Linux. </li>
  <li> UDP packets that are too large won't be delivered. Split up frame packets that exceed a certain size limit. </li>
  <li> There is currently no security, and anyone can send a packet to the receiver, whether it's a video frame or not. Implement a protocol that adds some security and ensures the incoming data is valid. Possibly encrypt the video. </li>
  <li> Test sending video across a large physical distance over the Internet. </li>
  <li> Define a clean API so the UDP video streaming can be plugged in to other applications. </li>
  <li> Add support from Windows (it uses a different socket library). </li>
</ul>
