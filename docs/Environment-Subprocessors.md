---
title: Environment forces
layout: page
parent: Basic Concepts
nav_order: 3
back_to_top: true
back_to_top_text: "Back to top"
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

<details open markdown="block">
  <summary>
    Contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

# Environment subprocessors

The environment around us affects us in many different ways. Considering these forces in your game will breathe life and realism into your ambient AIs by adding environment specific reactions to their movement. [Spawners](Groups-and-spawners) can add these environmental forces to your boids. MegaBoids provides the following environmental subprocessors to add variety in your world.

> [!Important]
> More environment subprocessors will be developed as we move towards Beta and final release. Feel free to [contact us](mailto:contact@megapunkgames.com) with your requests. This valuable feedback will drive our efforts and is one of the reasons we are releasing in Alpha.

| Subprocessor  | Details     |              |
| :------------ | :---------- | :----------  |
| Constant | Constant force applied to the boids at all times.<br><br>**<ins>Properties</ins>**<br>_Forces_: List of world space forces to apply. | [![Constant Environment Preview](resources/ConstantEnvironmentPreview.png)](resources/ConstantEnvironmentPreview.png) |
