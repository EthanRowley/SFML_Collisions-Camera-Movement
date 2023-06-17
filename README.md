# AABB
## AABB Collisions
- Axis aligned bounding box collisions to detect collisions between the two squares
## Camera Follows Player
- A camera vector is used to follow the blue box around, moving the red box relative to the blue box
## Velocity movement
- player is controlled through WASD, red box can be controlled through arrow keys
- A player position is calculated by:
- 1. Detect Key Press
- 2. Add delta vector to acceleration vector
- 3. Add acceleration to current velocity
- 4. Multiply velocity by a factor to eventually make it 0
- 5. Set player position to new position calculated by adding velocity vector to player position

# Jumping
A demo with gravity affecting a square causing it to fall until it collides with a platform. The square can be controlled with AD and jump with the space bar. The camera will follow the square. 
