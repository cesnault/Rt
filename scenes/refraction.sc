type : cam
{
pos : 0.0 0.0 0.0
rot : 0.5 0.5 0.0
}

type : light
{
pos : 5.0 0.0 1.0
light color : 1.0 1.0 1.0
name : coucou
}

type : plan
{
name : test_sphere2
pos : 0.0 0.0 200.0
rot : 0.0 0.0 0.0
dir : 0.0 0.0 1.0
light color : 0.0 0.0 0.0
texture : procedural
[
procedural : damier2D
specular : 0.0
diffuse : 1.0
refract : 1.0
]
}

type : sphere
{
name : test_sphere2
pos : -10.0 0.0 150.0
dir : 0.0 0.0 0.0
rot : 0.0 0.0 0.0
light color : 0.0 0.0 0.0
rey : 10.0
texture : color
[
color : 0.2 0.5 0.1
specular : 0.0
diffuse : 0.5
refract : 1.0
]
}
