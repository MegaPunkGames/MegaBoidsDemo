<p align="center">
    <a href="#">
        <img src="https://raw.githubusercontent.com/MegaPunkGames/MegaBoidsDemo/refs/heads/master/Resources/ReadmeBanner.PNG">
    </a>
</p>

# Contents
- [About](#About)
- [Features](#Features)
- [Changelog](#Changelog)
- [Installation](#Installation)
- [Acknowledgements](#Acknowledgements)

Be sure to check out the [Wiki](https://github.com/MegaPunkGames/MegaBoidsDemo/wiki) for documentation and technical reference.

# About
MegaBoids in a Mass Entity plugin to create groups of ambient NPCs with rich behavior. Built upon the common boid algorithm with alignment, cohesion and separation, MegaBoids makes it easy to create atmosphere within your environment by adding thousands of entities with small CPU and GPU overhead. Whether it's flocks of birds, swarms of insects, schools of fish or your custom groups of aliens, this plugin has it covered with it's extensive feature set and support for custom behavior injection.

# Features
- $\color{green}{Mass~Entity}$: Based on Mass Entity for maximum performance.
- $\color{green}{Multi~threaded}$: Fully multi threaded to make the most use of those CPU cores and limit the impact on the game thread.
- $\color{green}{Movement~models}$: Extensive set of common movement models (Ground, gliding, kinetic particle & rigid bodies, etc.).
- $\color{green}{Driving~forces}$: Extensive set of common force sources to drive the boid movement (Impulse, burst, follow path, flee, etc.).
- $\color{green}{Environment~forces}$: Add forces to your environment to simulate water or air currents for more dynamic and rich movement.
- $\color{green}{Obstacle~avoidance}$: Avoid clipping through the environment by avoiding obstacles.
- $\color{green}{Mixed~entities}$: Supports mixed entity types and visual representation within a single group for realistic interactions.
- $\color{green}{HISM~ based~rendering}$: Hierarchical instanced static mesh rendering with LODs support and shader animation using per instance custom data.
- $\color{green}{Actor~ based~rendering}$: Using Mass Entity traits, you can simulate your boids efficiently yet the keep actor based rendering goodness.
- $\color{green}{Additional~behaviors}$: Compatible with the usual Mass Entity traits to extend the entity behaviors.
- $\color{green}{Extensible}$: Inject your custom project specific forces and movement models to get the exact behavior you are aiming for (C++ only).
- $\color{green}{Easy~API}$: We take great care to hide the implementation details and let you focus on what matters to you with a simple API that doesn't require learning more than the basics of Mass Entity.
- $\color{green}{Full~UE5.1+~support}$: All features supported in Unreal 5.1+

# Changelog

## Version 0.1
 - First ALPHA release

# Installation
- Purchase and download the plugin from Fab
- Extract zip file into your project's Plugins folder
- Regenerate your C++ project files for the target UE version
- Compile and enjoy!

# Acknowledgements
Special thanks to:
- Lancaster Modelagem for the blue butterfly model and animation (https://sketchfab.com/3d-models/borboleta-azul-butterfly-ab9192b6bc8f49e3baed63e984c7073a), licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
- huykhoi2407 for the carp fish model (https://sketchfab.com/3d-models/carp-fish-ef0c406d4ca84242a0464abecb7d7037), licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)
- kromond for the AnimToTextureHelpers (https://github.com/kromond/AnimToTextureHelpers)
