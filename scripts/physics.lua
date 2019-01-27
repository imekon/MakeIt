function setup_physics()
	crate = Texture()
	crate:load("textures/crate.png")

	ball = Texture()
	ball:load("textures/ball.png")

	floor_texture = Texture()
	floor_texture:load("textures/floor.png")

	physics = Physics(10.0, 30.0)
	-- physics.debug = true

	root = Scene()
	Scene.set_root(root)

	node = Node2D()
	node.name = "node"

	s1 = Sprite()
	s1:set_texture(crate)
	s1.z = 10
	s1.position = Vector2(100, 100)
	s1.name = "crate"
	node:add_child(s1)

	s2 = Sprite()
	s2:set_texture(ball)
	s2.z = -10
	s2.position = Vector2(200, 100)
	s2.name = "ball"
	node:add_child(s2)

	floor = StaticBody()
	floor.name = "physics floor"
	shape2 = BoxShape(1280, 10)
	floor:set_shape(shape2)
	floor.position = Vector2(0, 600)

	floor_sprite = Sprite()
	floor_sprite:set_texture(floor_texture)
	floor:add_child(floor_sprite)
	node:add_child(floor)

	root:add_child(node)
	root:sort()
end

function create_crates()
	for i = 1,8 do
		local p = DynamicBody()
		local shape = BoxShape(64, 64)
		p:set_shape(shape)
		p.position = Vector2(300 + i * 64, 100)
		node:add_child(p)

		local s = Sprite()
		s:set_texture(crate)
		p:add_child(s)
	end
end