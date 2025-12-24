---
title: Movement Models
layout: page
---

<style>
table th:nth-of-type(1) {
    width: 100px;
}
table th:nth-of-type(2) {
    width: 600px;
}
table th:nth-of-type(3) {
    width: 150px;
}
</style>

The movement model in MegaBoids is the equivalent of the movement or mover component for Unreal actors. Just like the "regular" movement component, the purpose of the movement model is to act on the boid's input to move the entity in the world. In the case of MegaBoids, the input consists of our 3 different force vectors (steering, propulsion and environment forces) which can impact our movement in different ways, according to your needs.

The movement model in an integral part of a boid and should not differ based on the environment. Therefore, it is configured at the boid level, within the [configuration data asset](Anatomy-of-a-boid). Below, you will find a list of readily available movement models you can use to configure your boids.

> [!Important]
> More movement models will be developed as we move towards Beta and final release. Feel free to [contact us](mailto:contact@megapunkgames.com) with your requests. This valuable feedback will drive our efforts and is one of the reasons we are releasing in Alpha.

| Movement  | Details     |              |
| :-------- | :---------- | :----------  |
| Simple Particle | <p>Simple particle movement is the simplest and most performant movement model. Forces are interpreted as either velocity or acceleration and used directly to move the entity. The boid is considered a particle so it is weightless and all forces are applied at the center. The boid will face the velocity direction and keeps it's Z axis upwards.<p>**<ins>Properties</ins>**<br>_Energy Type_: Energy type for the forces.<br>&nbsp;&nbsp;&nbsp;&nbsp;Kinematic: Forces are directly applied as velocity. This equates to very sudden, jittery orientation making it better for fast moving objects like insects or boids with relatively steady orientation.<br>&nbsp;&nbsp;&nbsp;&nbsp;Kinetic: Forces are applied as an acceleration, resulting is a smoother movement with inertia.<br>_Linear damping_ (Kinetic only): Amount of energy lost over time to friction.<br>_Velocity range_: Min/max velocity the boid can move at.<br>_Max pitch_: Maximum absolute pitch the boid can sustain. When forces push the boid to have a pitch higher than the maximum specified (or lower than -Max), the extra forces are transferred to forward energy. Set to zero for 2D orientation. | [![Simple Particle Preview](resources/SimpleParticlePreview.png)](resources/SimpleParticlePreview.png) |
| Ground Particle | <p>On ground particle (all forces at origin & weightless) allows movement with collision on the provided ground type. When on the ground, friction is applied to slow down movement. The entity will also turn increasingly faster to face the velocity direction until within the configured rotation damping angle.<p>**<ins>Properties</ins>**<br>_Max Rotation Speed_: Maximum rotation speed the boid can reach.<br>_Rotation Acceleration_: Acceleration in turning speed, in degrees/second.<br>_Rotation Damping_: Damping applied to turning speed when in the damping zone.<br>_Rotation Damping Half Angle_: Angle around the desired facing direction where we stop accelerating and start applying rotation damping to slow down, in degrees.<br>_Ground Friction_: Friction factor to slow down movement when on ground.<br>_Ground Type_: Ground type to use for ground collision.<br>&nbsp;&nbsp;&nbsp;&nbsp;Plane: Static ground at world Z height plane.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;_Auto-detect_: Auto-detect ground plane with a raycast on spawn.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;_Raycast collision profile_: Collision profile to use to auto-detect plane.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;_Ground Z Height_: Manual plane Z coordinate.<br>&nbsp;&nbsp;&nbsp;&nbsp;Landscape: Uses the landscape to determine ground height at location.<br>&nbsp;&nbsp;&nbsp;&nbsp;NavMesh: Uses navigation mesh to determine ground height. Note that the navmesh is not precisely on the ground so this might be faster but it is also not as precise as a raycast or landscape but it can be good when far, for flat-ish ground or indoor environments.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;_Navigation agent type_: NavMesh agent type.<br>&nbsp;&nbsp;&nbsp;&nbsp;Raycast: Raycast downwards using the configured profile.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;_Raycast collision profile_: Collision profile to use for raycasting. | [![Ground Particle Preview](resources/GroundParticlePreview.png)](resources/GroundParticlePreview.png) |
| Gliding Particle | <p>Gliding movement for flying/floating particle boids (all forces at origin & weightless). Gravity is always applied to gliding boids with a scaling factor provided to simulate lift, and air friction for velocity deceleration. Turning speed is gradually increased up to a maximum turning angle. The entities will roll on themselves when turning, similar to a glider, but remain flat (no pitch).<p>**<ins>Properties</ins>**<br>_Air Friction_: Factor for air friction that slows down the entity.<br>_Gravity multiplier_: Multiplier on world gravity to simulate lift.<br>_Rotation Acceleration Degrees_: Acceleration speed (degrees/second) at which the boid turns.<br>_Max Turn Angle_: Maximum turning angle for the entity.  | [![Gliding Particle Preview](resources/GlidingParticlePreview.png)](resources/GlidingParticlePreview.png) |


