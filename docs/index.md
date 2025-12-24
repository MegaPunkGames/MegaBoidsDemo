---
title: Home
layout: home
nav_order: 1
---

# Introduction
MegaBoids in a Mass Entity plugin to create groups of ambient NPCs with rich behavior. Based on the common boid algorithm with alignment, cohesion and separation, MegaBoids makes it easy to create atmosphere within your environment by adding thousands of entities with small CPU and GPU overhead. Whether it's flocks of birds, swarms of insects, schools of fish or your custom groups of aliens, this plugin has it covered with it's extensive feature set and support for custom behavior injection.

[Get MegaBoids on Fab](https://www.fab.com/portal/listings/bfcc52a6-6ee7-4d78-a7be-c65ce4f0a18c)

# Features
* Based on Mass Entity for maximum performance
* Fully multi threaded to make the most use of those CPU cores
* Extensive set of common movement models (Ground, gliding, kinetic particle & rigid bodies, etc.)
* Extensive set of common force sources to drive the boid movement (Impulse, burst, follow path, avoid, etc.)
* Obstacle avoidance
* Supports mixed boid configurations and visual representation within a single group
* HISM based rendering with support for shader animation using per instance custom parameters
* Inject your own custom force sources and movement models to get the exact behavior you are aiming for (C++ only, there is no support for blueprint in Mass Entity at the moment)
* Compatible with the usual Mass Entity traits to extend the entity behaviors
* All features supported in Unreal 5.1+ (yes, we will backport new features!)

***

> [!NOTE]
> **CURRENTLY IN ALPHA PHASE.**

We are currently releasing this plugin as an ALPHA version while we keep on adding new features. We are happy with the current architecture based on subprocessors which allows us to extend the API and modify it's internals with limited impact on the users. Therefore, we will now focus mostly on adding new features and bug fixing but you should expect a smooth transition over to the beta and official release afterwards.

Currently planned features for official release:
* New driving force subprocessors
* New movement model subprocessors
* More obstacle types and allow inside vs. outside avoidance
* Optimize the HISM renderer
* Throttling/Time slicing to reduce computations per frame
* Debug hook to ease debugging of custom subprocessors
* [Improved Blueprint support](Blueprint-support)
