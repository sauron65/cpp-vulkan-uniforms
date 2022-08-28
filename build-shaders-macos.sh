#                                               +-- google doesn't like .vsh/.fsh so I have to use .vert/.frag >:(
#                                               |
#                                               V
~/VulkanSDK/1.3.216.0/macOS/bin/glslc ./shaders/t.vert -o ./shaders/tv.spv
~/VulkanSDK/1.3.216.0/macOS/bin/glslc ./shaders/t.frag -o ./shaders/tf.spv