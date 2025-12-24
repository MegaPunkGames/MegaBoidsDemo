---
title: Project Settings
layout: page
parent: Basic Concepts
nav_order: 6
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

# Project Settings

Within the **Project Settings - MegaBoids** page, you will find some project specific settings for the plugin, unsurprisingly. These settings allow basic configuration of the plugin for your game.

![Project Settings Preview](resources/ProjectSettingsPreview.png)

| Settings | Description |
| :------- | :---------- |
| Maximum Delta Time | The maximum delta time to use when updating boids. Since movement is often based on velocity, it can get out of control with large timesteps (when there is a framerate drop / stutter). This settings allows to limit teh frame deltatime to a given maximum value to prevent excessive movement. |
| Default Space Partition | The space partition settings to use by default for the project. This setting can be overriden at the [boid configuration](Anatomy-of-a-Boid#Boid-configuration) level as well as on the [spawner](Spawners-and-Groups#Space-partition). For more details on the properties within this setting, see [here](Spawners-and-Groups#Space-partition-settings).
