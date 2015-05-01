#!/usr/bin/env python

# 16 Happy Buddhas with 32 point lights
# Copyright (c) 2011-2014 Hiroshi Tsubokawa

import fujiyama
si = fujiyama.SceneInterface()

#plugins
si.OpenPlugin('PlasticShader')
si.OpenPlugin('GlassShader')
si.OpenPlugin('ConstantShader')

#Camera
si.NewCamera('cam1', 'PerspectiveCamera')
si.SetProperty3('cam1', 'translate', 5, 4, 5)
si.SetProperty3('cam1', 'rotate', -19.4712206345, 45, 0)

#Light
si.NewLight('light0', 'PointLight')
si.SetProperty3('light0', 'translate', 0.900771, 12, 4.09137)
si.SetProperty1('light0', 'intensity', 0.03125)
si.NewLight('light1', 'PointLight')
si.SetProperty3('light1', 'translate', 2.02315, 12, 5.28021)
si.SetProperty1('light1', 'intensity', 0.03125)
si.NewLight('light2', 'PointLight')
si.SetProperty3('light2', 'translate', 10.69, 12, 13.918)
si.SetProperty1('light2', 'intensity', 0.03125)
si.NewLight('light3', 'PointLight')
si.SetProperty3('light3', 'translate', 4.28027, 12, 7.58462)
si.SetProperty1('light3', 'intensity', 0.03125)
si.NewLight('light4', 'PointLight')
si.SetProperty3('light4', 'translate', 12.9548, 12, 1.19914)
si.SetProperty1('light4', 'intensity', 0.03125)
si.NewLight('light5', 'PointLight')
si.SetProperty3('light5', 'translate', 6.55808, 12, 2.31772)
si.SetProperty1('light5', 'intensity', 0.03125)
si.NewLight('light6', 'PointLight')
si.SetProperty3('light6', 'translate', 0.169064, 12, 10.9623)
si.SetProperty1('light6', 'intensity', 0.03125)
si.NewLight('light7', 'PointLight')
si.SetProperty3('light7', 'translate', 1.25002, 12, 4.51314)
si.SetProperty1('light7', 'intensity', 0.03125)
si.NewLight('light8', 'PointLight')
si.SetProperty3('light8', 'translate', 2.46758, 12, 5.73382)
si.SetProperty1('light8', 'intensity', 0.03125)
si.NewLight('light9', 'PointLight')
si.SetProperty3('light9', 'translate', 3.55644, 12, 6.84334)
si.SetProperty1('light9', 'intensity', 0.03125)
si.NewLight('light10', 'PointLight')
si.SetProperty3('light10', 'translate', 4.76112, 12, 8.00264)
si.SetProperty1('light10', 'intensity', 0.03125)
si.NewLight('light11', 'PointLight')
si.SetProperty3('light11', 'translate', 13.3267, 12, 9.10333)
si.SetProperty1('light11', 'intensity', 0.03125)
si.NewLight('light12', 'PointLight')
si.SetProperty3('light12', 'translate', 14.4155, 12, 2.68084)
si.SetProperty1('light12', 'intensity', 0.03125)
si.NewLight('light13', 'PointLight')
si.SetProperty3('light13', 'translate', 8.10755, 12, 3.79629)
si.SetProperty1('light13', 'intensity', 0.03125)
si.NewLight('light14', 'PointLight')
si.SetProperty3('light14', 'translate', 9.21103, 12, 4.9484)
si.SetProperty1('light14', 'intensity', 0.03125)
si.NewLight('light15', 'PointLight')
si.SetProperty3('light15', 'translate', 2.83469, 12, 6.09221)
si.SetProperty1('light15', 'intensity', 0.03125)
si.NewLight('light16', 'PointLight')
si.SetProperty3('light16', 'translate', 4.00945, 12, 7.18302)
si.SetProperty1('light16', 'intensity', 0.03125)
si.NewLight('light17', 'PointLight')
si.SetProperty3('light17', 'translate', 12.6072, 12, 0.832089)
si.SetProperty1('light17', 'intensity', 0.03125)
si.NewLight('light18', 'PointLight')
si.SetProperty3('light18', 'translate', 6.21169, 12, 1.98055)
si.SetProperty1('light18', 'intensity', 0.03125)
si.NewLight('light19', 'PointLight')
si.SetProperty3('light19', 'translate', 7.39599, 12, 10.5563)
si.SetProperty1('light19', 'intensity', 0.03125)
si.NewLight('light20', 'PointLight')
si.SetProperty3('light20', 'translate', 8.52421, 12, 4.15086)
si.SetProperty1('light20', 'intensity', 0.03125)
si.NewLight('light21', 'PointLight')
si.SetProperty3('light21', 'translate', 9.5891, 12, 5.39715)
si.SetProperty1('light21', 'intensity', 0.03125)
si.NewLight('light22', 'PointLight')
si.SetProperty3('light22', 'translate', 3.18967, 12, 13.9542)
si.SetProperty1('light22', 'intensity', 0.03125)
si.NewLight('light23', 'PointLight')
si.SetProperty3('light23', 'translate', 4.41432, 12, 0.082813)
si.SetProperty1('light23', 'intensity', 0.03125)
si.NewLight('light24', 'PointLight')
si.SetProperty3('light24', 'translate', 5.48803, 12, 1.21856)
si.SetProperty1('light24', 'intensity', 0.03125)
si.NewLight('light25', 'PointLight')
si.SetProperty3('light25', 'translate', 6.57647, 12, 2.31432)
si.SetProperty1('light25', 'intensity', 0.03125)
si.NewLight('light26', 'PointLight')
si.SetProperty3('light26', 'translate', 0.265098, 12, 10.9453)
si.SetProperty1('light26', 'intensity', 0.03125)
si.NewLight('light27', 'PointLight')
si.SetProperty3('light27', 'translate', 8.84422, 12, 12.1117)
si.SetProperty1('light27', 'intensity', 0.03125)
si.NewLight('light28', 'PointLight')
si.SetProperty3('light28', 'translate', 10.0154, 12, 5.67625)
si.SetProperty1('light28', 'intensity', 0.03125)
si.NewLight('light29', 'PointLight')
si.SetProperty3('light29', 'translate', 11.0907, 12, 14.4043)
si.SetProperty1('light29', 'intensity', 0.03125)
si.NewLight('light30', 'PointLight')
si.SetProperty3('light30', 'translate', 4.71726, 12, 7.98851)
si.SetProperty1('light30', 'intensity', 0.03125)
si.NewLight('light31', 'PointLight')
si.SetProperty3('light31', 'translate', 13.3907, 12, 9.08986)
si.SetProperty1('light31', 'intensity', 0.03125)

#Texture
si.NewTexture('tex1', '../../mip/uffizi-large.mip')

#Shader
si.NewShader('buddha_shader0', 'PlasticShader')
si.SetProperty3('buddha_shader0', 'diffuse', 0.420094, 0.420094, 0.350488)
si.NewShader('buddha_shader1', 'PlasticShader')
si.SetProperty3('buddha_shader1', 'diffuse', 0.28069, 0.458229, 0.137373)
si.NewShader('buddha_shader2', 'PlasticShader')
si.SetProperty3('buddha_shader2', 'diffuse', 0.0677194, 0.243452, 0.17638)
si.NewShader('buddha_shader3', 'PlasticShader')
si.SetProperty3('buddha_shader3', 'diffuse', 0.103483, 0.282905, 0.463173)
si.NewShader('buddha_shader4', 'PlasticShader')
si.SetProperty3('buddha_shader4', 'diffuse', 0.3928, 0.316322, 0.499749)
si.NewShader('buddha_shader5', 'PlasticShader')
si.SetProperty3('buddha_shader5', 'diffuse', 0.177487, 0.107719, 0.285897)
si.NewShader('buddha_shader6', 'PlasticShader')
si.SetProperty3('buddha_shader6', 'diffuse', 0.464536, 0.145117, 0.0744061)
si.NewShader('buddha_shader7', 'PlasticShader')
si.SetProperty3('buddha_shader7', 'diffuse', 0.25295, 0.432513, 0.363791)
si.NewShader('buddha_shader8', 'PlasticShader')
si.SetProperty3('buddha_shader8', 'diffuse', 0.0438571, 0.469678, 0.397773)
si.NewShader('buddha_shader9', 'PlasticShader')
si.SetProperty3('buddha_shader9', 'diffuse', 0.329916, 0.258578, 0.437995)
si.NewShader('buddha_shader10', 'PlasticShader')
si.SetProperty3('buddha_shader10', 'diffuse', 0.114984, 0.29606, 0.224838)
si.NewShader('buddha_shader11', 'PlasticShader')
si.SetProperty3('buddha_shader11', 'diffuse', 0.153974, 0.084485, 0.262245)
si.NewShader('buddha_shader12', 'PlasticShader')
si.SetProperty3('buddha_shader12', 'diffuse', 0.19063, 0.119706, 0.299113)
si.NewShader('buddha_shader13', 'PlasticShader')
si.SetProperty3('buddha_shader13', 'diffuse', 0.478574, 0.409711, 0.335123)
si.NewShader('buddha_shader14', 'PlasticShader')
si.SetProperty3('buddha_shader14', 'diffuse', 0.016735, 0.196075, 0.374869)
si.NewShader('buddha_shader15', 'PlasticShader')
si.SetProperty3('buddha_shader15', 'diffuse', 0.304462, 0.234848, 0.41284)

si.NewShader('floor_shader', 'PlasticShader')
si.NewShader('dome_shader', 'ConstantShader')

#Mesh
si.NewMesh('buddha_mesh', '../../ply/happy.ply')
si.NewMesh('floor_mesh', '../../ply/floor.ply')
si.NewMesh('dome_mesh', '../../ply/dome.ply')

#ObjectInstance
si.NewObjectInstance('buddha0', 'buddha_mesh')
si.SetProperty3('buddha0', 'translate', -0.0, 0, -0.0)
si.SetProperty3('buddha0', 'rotate', 0, 0, 0)
si.SetProperty3('buddha0', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha0', 'DEFAULT_SHADING_GROUP', 'buddha_shader0')
si.NewObjectInstance('buddha1', 'buddha_mesh')
si.SetProperty3('buddha1', 'translate', -0.0, 0, -1.5)
si.SetProperty3('buddha1', 'rotate', 0, 30, 0)
si.SetProperty3('buddha1', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha1', 'DEFAULT_SHADING_GROUP', 'buddha_shader1')
si.NewObjectInstance('buddha2', 'buddha_mesh')
si.SetProperty3('buddha2', 'translate', -0.0, 0, -3.0)
si.SetProperty3('buddha2', 'rotate', 0, 60, 0)
si.SetProperty3('buddha2', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha2', 'DEFAULT_SHADING_GROUP', 'buddha_shader2')
si.NewObjectInstance('buddha3', 'buddha_mesh')
si.SetProperty3('buddha3', 'translate', -0.0, 0, -4.5)
si.SetProperty3('buddha3', 'rotate', 0, 90, 0)
si.SetProperty3('buddha3', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha3', 'DEFAULT_SHADING_GROUP', 'buddha_shader3')
si.NewObjectInstance('buddha4', 'buddha_mesh')
si.SetProperty3('buddha4', 'translate', -1.5, 0, -0.0)
si.SetProperty3('buddha4', 'rotate', 0, 120, 0)
si.SetProperty3('buddha4', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha4', 'DEFAULT_SHADING_GROUP', 'buddha_shader4')
si.NewObjectInstance('buddha5', 'buddha_mesh')
si.SetProperty3('buddha5', 'translate', -1.5, 0, -1.5)
si.SetProperty3('buddha5', 'rotate', 0, 150, 0)
si.SetProperty3('buddha5', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha5', 'DEFAULT_SHADING_GROUP', 'buddha_shader5')
si.NewObjectInstance('buddha6', 'buddha_mesh')
si.SetProperty3('buddha6', 'translate', -1.5, 0, -3.0)
si.SetProperty3('buddha6', 'rotate', 0, 180, 0)
si.SetProperty3('buddha6', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha6', 'DEFAULT_SHADING_GROUP', 'buddha_shader6')
si.NewObjectInstance('buddha7', 'buddha_mesh')
si.SetProperty3('buddha7', 'translate', -1.5, 0, -4.5)
si.SetProperty3('buddha7', 'rotate', 0, 210, 0)
si.SetProperty3('buddha7', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha7', 'DEFAULT_SHADING_GROUP', 'buddha_shader7')
si.NewObjectInstance('buddha8', 'buddha_mesh')
si.SetProperty3('buddha8', 'translate', -3.0, 0, -0.0)
si.SetProperty3('buddha8', 'rotate', 0, 240, 0)
si.SetProperty3('buddha8', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha8', 'DEFAULT_SHADING_GROUP', 'buddha_shader8')
si.NewObjectInstance('buddha9', 'buddha_mesh')
si.SetProperty3('buddha9', 'translate', -3.0, 0, -1.5)
si.SetProperty3('buddha9', 'rotate', 0, 270, 0)
si.SetProperty3('buddha9', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha9', 'DEFAULT_SHADING_GROUP', 'buddha_shader9')
si.NewObjectInstance('buddha10', 'buddha_mesh')
si.SetProperty3('buddha10', 'translate', -3.0, 0, -3.0)
si.SetProperty3('buddha10', 'rotate', 0, 300, 0)
si.SetProperty3('buddha10', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha10', 'DEFAULT_SHADING_GROUP', 'buddha_shader10')
si.NewObjectInstance('buddha11', 'buddha_mesh')
si.SetProperty3('buddha11', 'translate', -3.0, 0, -4.5)
si.SetProperty3('buddha11', 'rotate', 0, 330, 0)
si.SetProperty3('buddha11', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha11', 'DEFAULT_SHADING_GROUP', 'buddha_shader11')
si.NewObjectInstance('buddha12', 'buddha_mesh')
si.SetProperty3('buddha12', 'translate', -4.5, 0, -0.0)
si.SetProperty3('buddha12', 'rotate', 0, 360, 0)
si.SetProperty3('buddha12', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha12', 'DEFAULT_SHADING_GROUP', 'buddha_shader12')
si.NewObjectInstance('buddha13', 'buddha_mesh')
si.SetProperty3('buddha13', 'translate', -4.5, 0, -1.5)
si.SetProperty3('buddha13', 'rotate', 0, 390, 0)
si.SetProperty3('buddha13', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha13', 'DEFAULT_SHADING_GROUP', 'buddha_shader13')
si.NewObjectInstance('buddha14', 'buddha_mesh')
si.SetProperty3('buddha14', 'translate', -4.5, 0, -3.0)
si.SetProperty3('buddha14', 'rotate', 0, 420, 0)
si.SetProperty3('buddha14', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha14', 'DEFAULT_SHADING_GROUP', 'buddha_shader14')
si.NewObjectInstance('buddha15', 'buddha_mesh')
si.SetProperty3('buddha15', 'translate', -4.5, 0, -4.5)
si.SetProperty3('buddha15', 'rotate', 0, 450, 0)
si.SetProperty3('buddha15', 'scale', 0.6, 0.6, 0.6)
si.AssignShader('buddha15', 'DEFAULT_SHADING_GROUP', 'buddha_shader15')

si.NewObjectInstance('floor1', 'floor_mesh')
si.SetProperty3('floor1', 'translate', -2.0, 0, -2.0)
si.AssignShader('floor1', 'DEFAULT_SHADING_GROUP', 'floor_shader')

si.NewObjectInstance('dome1', 'dome_mesh')
si.SetProperty3('dome1', 'scale', 0.5, 0.5, 0.5)
si.AssignShader('dome1', 'DEFAULT_SHADING_GROUP', 'dome_shader')
si.AssignTexture('dome_shader', 'texture', 'tex1')

#ObjectGroup
si.NewObjectGroup('group1')
si.AddObjectToGroup('group1', 'buddha0')
si.AddObjectToGroup('group1', 'buddha1')
si.AddObjectToGroup('group1', 'buddha2')
si.AddObjectToGroup('group1', 'buddha3')
si.AddObjectToGroup('group1', 'buddha4')
si.AddObjectToGroup('group1', 'buddha5')
si.AddObjectToGroup('group1', 'buddha6')
si.AddObjectToGroup('group1', 'buddha7')
si.AddObjectToGroup('group1', 'buddha8')
si.AddObjectToGroup('group1', 'buddha9')
si.AddObjectToGroup('group1', 'buddha10')
si.AddObjectToGroup('group1', 'buddha11')
si.AddObjectToGroup('group1', 'buddha12')
si.AddObjectToGroup('group1', 'buddha13')
si.AddObjectToGroup('group1', 'buddha14')
si.AddObjectToGroup('group1', 'buddha15')
si.AssignObjectGroup('buddha0', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha1', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha2', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha3', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha4', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha5', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha6', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha7', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha8', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha9', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha10', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha11', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha12', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha13', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha14', 'shadow_target', 'group1')
si.AssignObjectGroup('buddha15', 'shadow_target', 'group1')
si.AssignObjectGroup('floor1', 'shadow_target', 'group1')

#FrameBuffer
si.NewFrameBuffer('fb1', 'rgba')

#Renderer
si.NewRenderer('ren1')
si.AssignCamera('ren1', 'cam1')
si.AssignFrameBuffer('ren1', 'fb1')
si.SetProperty2('ren1', 'resolution', 640, 480)
#si.SetProperty2('ren1', 'resolution', 160, 120)

#Rendering
si.RenderScene('ren1')

#Output
si.SaveFrameBuffer('fb1', '../happy_buddhas.fb')

#Run commands
si.Run()
#si.Print()
